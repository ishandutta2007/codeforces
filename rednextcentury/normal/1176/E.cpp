#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long
#define ii pair<ll,ll>
#define all(x) x.be,x.ee
#define le (x*2)
#define ri (x*2+1)
#define mid ((l+r)/2)
#define ld long double
#define e '\n'
#define sp ' '
#define pb push_back
#define pf push_front
#define po pop_back()
#define up upper_bound
#define lo lower_bound
#define in insert
#define mk make_pair
#define er erase
#define R return
#define se second
#define co continue
#define fi first
#define fr front()
#define ba back()
#define si size()
#define em empty()
#define be begin()
#define ee end()
#define mod 100000000
#define eb 0.000000001
#define pi acos(-1)

int t,n,m,a,b,s,sz[200200];
bool vis[200200];
vector<int> vec,v[200200];
vector<pair<int,int>> edge;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            edge.pb(mk(a,b));
            v[a].pb(b);
            v[b].pb(a);
            sz[a]++;
            sz[b]++;
        }
        for(int i=0;i<m;i++){
            a=edge[i].fi, b=edge[i].se;
            if(sz[b]>sz[a]) swap(a,b);
            if(!vis[a]){
                vis[a]=1;
                vec.pb(a);
                sz[a]=0;
                for(int j=0;j<v[a].si;j++){
                    vis[v[a][j]]=1;
                    sz[v[a][j]]--;
                }
            }
            else if(!vis[b]){
                vis[b]=1;
                vec.pb(b);
                sz[b]=0;
                for(int j=0;j<v[b].si;j++){
                    vis[v[b][j]]=1;
                    sz[v[b][j]]--;
                }
            }
        }
        if (vec.si > n/2)
        {
            for(int i=0;i<=n;i++){
                vis[i]=0;
            }
            for (auto x:vec)vis[x]=1;
            vec.clear();
            for (int i=1;i<=n;i++)
                if (!vis[i])vec.push_back(i);
        }
        printf("%d\n",vec.si);
        for(int i=0;i<vec.si;i++) printf("%d ",vec[i]);
        printf("\n");

        vec.clear();
        edge.clear();
        for(int i=0;i<=n;i++){
            vis[i]=0;
            sz[i]=0;
            v[i].clear();
        }
    }
    R 0;
}