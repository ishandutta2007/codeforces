#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Alpha=28;
int ret[1000000];
vector< pair<int,pair<int,int> > > Q[1000000];
vector<int> vec[1000000];
int BIT[1000000],mx=5e5;
void update(int x, int delta)
{
    for(; x <= mx; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
}
int range(int l,int r) {
    return query(r)-query(l-1);
}
int S[1000000];
vector<int> adj[1000000];
bool bad[1000000];
void pre(int v=0,int pa=-1)
{
    S[v] = vec[v].size()+1;
    for(auto u:adj[v])
        if (u!=pa)
            pre(u,v),S[v] += S[u];
}
void add(int v,int p,int x=1)
{
    for (auto o:vec[v]){
        update(o,x);
    }

    for(auto u:adj[v])
        if(!bad[u] && u!=p)
            add(u,v,x);
}
void dfs(int v=0,bool cl=1,int p=-1){

    int mx=-1,node=-1;
    for(auto u:adj[v])
        if(u!=p && S[u]>mx)
            mx=S[u], node = u;
    for(auto u:adj[v])
        if(u != node && u!=p)
            dfs(u,1,v);
    if(node!=-1)
        bad[node]=1,dfs(node,0,v);
    add(v,p);
    if (node!=-1)bad[node]=0;
    for (auto q:Q[v]) {
        ret[q.first] = range(q.second.first,q.second.second);
    }

    if(cl)
        add(v,p,-1);
}

class SuffixAutomata{
public:
    string org;
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
    void build(string s)
    {
        org = s;
        Init(s.size());
        for (auto x:s)extend(x);
        getTerminal();
    }
    void solve() {
        for (int i=0;i<sz;i++) {
            if (st[i].link!=-1)
                adj[st[i].link].push_back(i);
        }
        int v = 0;
        for (int i=0;i<org.size();i++) {
            int x = org[i]-'a';
            if (x>=26){
                v=0;
                continue;
            }
            v = st[v].next[x];
            vec[v].push_back(i);
        }
    }
    int getNode(string s) {
        int v = 0;
        for (auto x:s)
            v = st[v].next[x - 'a'];
        return v;
    }
};
char inp[1000000];
string s[1000000];
int L[1000000];
int R[1000000];
int node[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    scanf("%d%d",&n,&q);
    string t="||";
    for (int i=1;i<=n;i++) {
        scanf("%s",inp);
        L[i]=t.size();
        s[i]=inp;
        t+=inp;
        R[i]=t.size();
        t+="|";
    }
    SuffixAutomata ST;
    ST.build(t);
    ST.solve();
    for (int i=1;i<=n;i++) node[i]=ST.getNode(s[i]);
    for (int i=0;i<q;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        Q[node[k]].push_back({i,{L[l],R[r]}});
    }
    pre();
    dfs();
    for (int i=0;i<q;i++) {
        printf("%d\n",ret[i]);
    }
}