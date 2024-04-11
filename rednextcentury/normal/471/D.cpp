#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Alpha=28;
class SuffixAutomata{
    public:
    struct state {
        int len, link;
        map<int,int> next;
        state(){
            len = link = 0;
            next.clear();
        }
    };
    int sz=1, last=0;
    vector<state> st;
    vector<int> terminal;
    vector<int> DP;
    void Init(int len) {
        st.clear();
        terminal.clear();
        st.resize(2*len);
        terminal.resize(2*len);
        sz = 1;
        last=0;
        st[0].len = 0;
        st[0].link = -1;
    }
    void extend(int c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].next.find(c) == st[p].next.end()) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        }
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void getTerminal()
    {
        int p=last;
        while(p>0)terminal[p]=1,p=st[p].link;
    }
    void build(vector<int> s)
    {
        Init(s.size());
        for (auto x:s)extend(x);
        getTerminal();
        for (int i=0;i<sz;i++)DP.push_back(-1);
    }
    int count(int i) {
        if (DP[i]!=-1)return DP[i];
        DP[i] = terminal[i];
        for (auto p:st[i].next) {
            DP[i]+=count(p.second);
        }
        return DP[i];
    }
    int sol(vector<int> x) {
        vector<int> need;
        for (int i=1;i<x.size();i++)need.push_back(x[i]-x[i-1]);
        int v = 0;
        for (auto x:need) {
            if (st[v].next.find(x)==st[v].next.end())return 0;
            v = st[v].next[x];
        }
        return count(v);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> s(n);
    vector<int> t(m);
    for (int i=0;i<n;i++)cin>>s[i];
    for (int i=n-1;i>0;i--)s[i]=s[i]-s[i-1];
    s[0]=0;
    SuffixAutomata SA;
    SA.build(s);
    for (int i=0;i<m;i++)cin>>t[i];
    vector<int> need;
    for (int i=1;i<m;i++)need.push_back(t[i]-t[i-1]);
    int sub = (m>1);
    for (int i=0;i<m-1;i++){
        if (s[i]!=need[i])sub=0;
    }
    cout<<SA.sol(t)-sub<<endl;
}