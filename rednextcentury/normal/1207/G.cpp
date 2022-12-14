#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Alpha=28;
vector<int> G[1000000];
int tim=2;
int L[2000000];
int R[2000000];
int node[2000000];
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
        st[0].len = 0;
        st[0].link = -1;
    }
    int extend(char ccc,int last) {
        int c = ccc - 'a';
        /*if (st[last].next[c]!=-1){
            last = st[last].next[c];
            return last;
        }*/
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
        return cur;
    }
    void getTerminal()
    {
        int p=last;
        while(p>0)terminal[p]=1,p=st[p].link;
    }
    void build(string s)
    {
        Init(s.size());
        for (auto x:s)extend(x,last);
        getTerminal();
    }
    void dfs(int v) {
        node[v] = tim;
        L[v] = tim++;
        for (auto u:G[v]) {
            dfs(u);
        }
        R[v] = tim-1;
    }
    void solve() {
        for (int i=0;i<sz;i++) {
            if (st[i].link!=-1)G[st[i].link].push_back(i);
        }
        dfs(0);
    }
    int getNode(string s) {
        int v=0;
        for (auto x:s) {
            v = st[v].next[x-'a'];
            if (v==-1)return v;
        }
        return v;
    }
};

char a[1000000];
vector<int> adj[1000000];
SuffixAutomata SA;
int cnt[1000000];
vector<int> Q[1000000];
string t[1000000];
int ret[1000000];
int BIT[3000000];
void update(int x, int delta)
{
    for(; x <= tim; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
}
void pre(int v,int cur) {
    int nLast = 0;
    if (v!=0) {
        nLast = SA.extend(a[v],cur);
    }
    for (auto u:adj[v]) {
        pre(u,nLast);
    }
}
char inp[1000000];
void solve(int v=0,int V=0) {
    if (v)V = SA.st[V].next[a[v]-'a'];
    if(V>0)update(node[V],1);
    for (auto q:Q[v]) {
        int need = SA.getNode(t[q]);
        ret[q] = query(R[need]) - query(L[need]-1);
    }
    for (auto u:adj[v]) {
        solve(u,V);
    }
    if (V>0)update(node[V],-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int typ,par;
        char c=' ';
        scanf("%d",&typ);
        par = 0;
        if (typ==1) {
            while(c==' ')scanf("%c",&c);
        } else {
            scanf("%d",&par);
            while(c==' ')scanf("%c",&c);
        }
        adj[par].push_back(i);
        a[i] = c;

    }
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++){
        int v;
        scanf("%d",&v);
        scanf("%s",inp);t[i]=inp;
        Q[v].push_back(i);
    }
    SA.Init(1e6);
    pre(0,0);
    SA.solve();
    solve(0,0);
    for (int i=0;i<q;i++) {
        printf("%d\n",ret[i]);
    }
}