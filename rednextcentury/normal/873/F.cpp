#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = (200105);
const int Alpha = 26;
int vv[MAXLEN*2];
long long ret[MAXLEN*2];
string s,t;
long long ans=0;
struct state {
    int len, link;
    int next[Alpha];
    vector<int> prev;
    state(){
        len = link = 0;
        memset(next , -1 , sizeof(next));
    }
    void reset()
    {
        len = link = 0;
        memset(next , -1 , sizeof(next));
        prev.clear();
    }
};
state st[MAXLEN*2];
int terminal[MAXLEN*2];
class SuffixAutomata{
    public:
    int sz, last;
    void init() {
        for(int j = 0 ; j < 2*MAXLEN ; j++) st[j] = state(),terminal[j]=0;
        st[0].len = 0;
        st[0].link = -1;
        sz = 1;
        last = 0;
    }
    void extend(char ccc) {
        int c = ccc - 'a';
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
    void dfs(int v)
    {
        for (auto u:st[v].prev)
            dfs(u),ret[v]+=ret[u];
        ans=max(ans,st[v].len*ret[v]);
    }
    void solve()
    {
        for (int i=1;i<sz;i++)
            st[st[i].link].prev.push_back(i);
        int cur=0;
        int num=0;
        for (int i=0;i<s.size();i++)
        {
            int x = s[i]-'a';
            int safe = 1-(t[i]-'0');
            cur = st[cur].next[x];
            if (safe)ret[cur]++;
        }
        dfs(0);
    }
}SA;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cin>>s>>t;
    SA.init();
    for (auto x:s)SA.extend(x);
    SA.solve();
    cout<<ans<<endl;
}