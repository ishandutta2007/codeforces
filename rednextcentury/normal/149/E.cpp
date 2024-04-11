#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Alpha=28;
int first[1000000];
int last[1000000];
class SuffixAutomata{
    public:
    struct state {
        int len, link;
        int next[Alpha];
        state(){
            len = link = 0;
            memset(next , -1 , sizeof(next));
        }
    };
    int sz=1, last=0;
    vector<state> st;
    vector<int> terminal;
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
    void extend(char ccc) {
        int c = ccc - 'A';
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].next[c] == -1) {
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
                for(int j = 0 ; j < Alpha ; j++)
                    st[clone].next[j] = st[q].next[j];
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
    string org;
    void build(string s)
    {
        org=s;
        Init(s.size());
        for (auto x:s)extend(x);
        getTerminal();
    }
    void solve(vector<int>& sol){
        sol.resize(sz);
        for (int i=0;i<sz;i++)sol[i]=-1;
        int v = 0;
        for (int i=0;i<org.size();i++) {
            v = st[v].next[org[i]-'A'];
            int u = v;
            while(u!=-1 && sol[u]==-1){
                sol[u]=i+1;
                u = st[u].link;
            }
        }
    }
};
int preNode[1000000];
int sufNode[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    SuffixAutomata SA,SAr;
    SA.build(s);
    reverse(s.begin(),s.end());
    SAr.build(s);
    int n;
    cin>>n;
    int ret=0;
    vector<int> last;  SAr.solve(last);
    vector<int> first; SA.solve(first);
    for (int i=0;i<n;i++) {
        string t;
        cin>>t;
        for (int j=0;j<t.size();j++)preNode[j]=sufNode[j]=-1;
        int v = 0;
        for (int j=0;j<t.size();j++) {
            v = SA.st[v].next[t[j]-'A'];
            if (v==-1)break;
            preNode[j] = v;
        }
        v=0;
        for (int j=t.size()-1;j>=0;j--) {
            v = SAr.st[v].next[t[j]-'A'];
            if (v==-1)break;
            sufNode[j]=v;
        }
        bool ok=0;
        for (int j=0;j+1<t.size();j++) {
            if (preNode[j]==-1 || sufNode[j+1]==-1)continue;
            if (first[preNode[j]]==-1 || last[sufNode[j+1]]==-1)continue;
            if (first[preNode[j]]+last[sufNode[j+1]]<=s.size())ok=1;
        }
        if (ok)ret++;
    }
    cout<<ret<<endl;
}