#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s;
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;
    vector<int> firstpos;
    vector<int> sum;
    vector<int> save;
    vector<P> query[MAXN];
    void init(){
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
    }
    int add(int p,char ch) {
        edges.push_back(map<char,int>());
        length.push_back(length[p]+1); link.push_back(0);
        int r=edges.size()-1;
        while(p>=0&&edges[p].find(ch)==edges[p].end()) {
            edges[p][ch]=r;
            p=link[p];
        }
        if(p!=-1) {
            int q=edges[p][ch];
            if(length[p]+1==length[q]) link[r]=q;
            else {
                edges.push_back(edges[q]); 
                length.push_back(length[p]+1);
                link.push_back(link[q]); 
                int qq=edges.size()-1;
                link[q]=qq; link[r]=qq;
                while(p>=0&&edges[p][ch]==q) {
                    edges[p][ch]=qq;
                    p=link[p];
                }
            }
        }
        return r;
    }
    vector<bool> vis;
    void dfs(int v)
    {
        vis[v]=true;
        if(firstpos[v]==0) firstpos[v]=INF;
        for(auto p:edges[v])
        {
            if(!vis[p.S]) dfs(p.S);
            firstpos[v]=min(firstpos[v],firstpos[p.S]-1);
        }
    }
    ll solve(string &s){
        sum.resize(s.size()+1);
        sum[0]=0;
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) 
        {
            cur=add(cur,s[i]);
            firstpos.resize(edges.size()); 
            firstpos[cur]=i+1; 
            sum[i+1]=sum[i]+(s[i]=='('?1:-1);
        }
        vis.resize(edges.size());
        dfs(0);
        vector<int> left(s.size()+1),st;
        for(int i=0;i<=(int)s.size();i++)
        {
            while(st.size()&&sum[st.back()]>=sum[i]) st.pop_back();
            left[i]=(!st.size())?-1:(st.back());
            st.push_back(i);
        }
        /*printf("sum:\n");
        for(int i=0;i<=(int)s.size();i++) printf("%d ",sum[i]);
        puts("");
        printf("left:\n");
        for(int i=0;i<=(int)s.size();i++) printf("%d ",left[i]);
        puts("");*/
        ll ans=0;
        for(int i=1;i<(int)edges.size();i++)
        {
            int pos=firstpos[i];
            int l=max(left[pos]+1,pos-length[i]),r=pos-(length[link[i]]+1);
            //printf("sum=%d i=%d pos=%d minlen=%d maxlen=%d l=%d r=%d\n",sum[pos],i,pos-1,length[link[i]]+1,length[i],l,r);
            if(l<=r)
            {
                if(l) query[l-1].push_back(P(sum[pos],-1));
                query[r].push_back(P(sum[pos],1));
            }
        }
        save.resize(1000005);
        for(int i=0;i<=(int)s.size();i++)
        {
            save[sum[i]+500000]++;
            for(auto p:query[i])
                ans+=p.S*save[p.F+500000];
        }
        return ans;
    }
}sam;
int main()
{
    scanf("%d",&n);
    cin>>s; 
    printf("%lld\n",sam.solve(s));
    return 0;
}