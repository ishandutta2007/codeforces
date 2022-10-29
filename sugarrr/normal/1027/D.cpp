#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


//////////////////////////////////////

#define MAX_N 1000000//
int par[MAX_N],dep[MAX_N];//deprank
//n//
void init(int n){
    for(int i=0;i<=n-1;i++){//0~n-1
        par[i]=i;
        dep[i]=0;
    }
}
//
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
//xy
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(dep[x]<dep[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(dep[x]==dep[y])dep[x]++;
    }
}
//xy
bool same(int x,int y){
    return find(x)==find(y);
}

//////////////////////////////////////

int main(){
    int n;scanf("%d",&n);
    int c[n],a[n];
    rep(i,0,n-1)scanf("%d",&c[i]);
    rep(i,0,n-1){scanf("%d",&a[i]);a[i]--;}
    init(n);
    rep(i,0,n-1){
        unite(i,a[i]);
    }
    i_i root[n];rep(i,0,n-1)root[i]=i_i(find(i),i);
    sort(root,root+n);
    
/*    rep(i,0,n-1){
        cout<<root[i].first<<" "<<root[i].second<<endl;
    }*/
    
    int pos=0;
    bool used[n];rep(i,0,n-1)used[i]=false;
    ll ans=0;
    while(pos<=n-1){
        queue<int>q;
        int t=root[pos].second;
        used[t]=true;
        q.push(t);
        while(1){
            if(used[a[t]]==true)break;
            else{
                t=a[t];
                used[t]=true;
                q.push(t);
            }
        }
        int x=a[t];
        while(q.front()!=x){
            q.pop();
        }
        ll mi=inf;
        while(!q.empty()){
            mi=min(mi,c[q.front()]);
            q.pop();
        }
        ans+=mi;
        
        while(pos<=n-2&&root[pos].first==root[pos+1].first){
            pos++;
        }
        pos++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}