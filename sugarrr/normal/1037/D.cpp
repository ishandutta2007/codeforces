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
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}

////////////////////////////////////////

bool check(vector<int>a,vector<int>b){
    int posa=0,posb=0;
    int sa=a.size(),sb=b.size();
    while(posa<=sa-1&&posb<=sb-1){
        if(a[posa]==b[posb]){
            posa++;posb++;
        }else{
            posa++;
        }
    }
    if(posb==sb)return true;
    else return false;
}

int main(){
    int n;cin>>n;
    vector<int>v[n+1];
    rep(i,1,n-1){
        int x,y;cin>>x>>y;
        v[x].pb(y);v[y].pb(x);
    }
    int a[n+1];rep(i,1,n)cin>>a[i];
    
    int dep[n+1];rep(i,1,n)dep[i]=-1;dep[1]=0;
    int par[n+1];par[1]=-1;
    queue<int>q;q.push(1);
    while(!q.empty()){
        int t=q.front();q.pop();
        for(auto x:v[t]){
            if(dep[x]==-1){
                dep[x]=dep[t]+1;
                par[x]=t;
                q.push(x);
            }
        }
    }
    bool flag=true;
    int pos=2;
    int nowd=1;
    vector<int>p;p.pb(1);
    int ad[n+1],ap[n+1];
    rep(i,1,n){
        ad[i]=dep[a[i]];
        ap[i]=par[a[i]];
    }
    
    if(a[1]!=1){cout<<"No"<<endl;return 0;}
    while(pos<=n){
        vector<int>c;
        vector<int>r;//
        while(pos<=n&&ad[pos]==nowd){
            c.pb(a[pos]);
            r.pb(par[a[pos]]);
            pos++;
        }
        vector<int>q;//r
        int siz=r.size();
        if(siz==0){flag=false;break;}
        q.pb(r[0]);
        rep(i,1,siz-1){
            if(r[i]!=r[i-1])q.pb(r[i]);
        }
        if(!check(p,q)){flag=false;break;}
        p=c;
        nowd++;
    }
    
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}