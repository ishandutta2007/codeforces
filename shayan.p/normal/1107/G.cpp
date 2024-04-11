// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,Lg=20;
const ll inf=1e18;

int dis[maxn];
ll sm[maxn],Mx[Lg][maxn],Mn[Lg][maxn];
int wh[Lg][maxn],d[maxn],c[maxn];

ll ask1(int l,int r){
    if(l>r) return inf;
    bool is=(l==-1);
    l+=(l==-1);
    if(l>r) return 0;
    int id=31-__builtin_clz(r-l+1);
    ll ans=min(Mn[id][l],Mn[id][r-(1<<id)+1]);
    if(is) ans=min(ans,ll(0));
    return ans;
}
ll ask2(int l,int r){
    if(l>r) return -inf;
    int id=31-__builtin_clz(r-l+1);
    return max(Mx[id][l],Mx[id][r-(1<<id)+1]);
}
int ask3(int l,int r){
    int id=31-__builtin_clz(r-l);
    int A=wh[id][l],B=wh[id][r-(1<<id)];
    if(dis[A]>dis[B]) return A;
    return B;
}
ll solve(int l,int r){
    if(l==r) return max(ll(0),sm[l]-(l==0?0:sm[l-1]));
    int pos=ask3(l,r);
    ll ans=max(ll(0),ask2(pos+1,r)-ask1(l-1,pos-1)-1ll*dis[pos]*dis[pos]);
    ans=max(ans,max(solve(l,pos),solve(pos+1,r)));
    //    cout<<"HEYYY "<<l<<" "<<r<<" "<<ans<<"  "<<pos<<" "<<ask1(l-1,pos-1)<<" "<<ask2(pos+1,r)<<" "<<dis[pos]<<endl;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a;cin>>n>>a;
    for(int i=0;i<n;i++){
	cin>>d[i]>>c[i];
    }
    for(int i=0;i<n;i++){
	sm[i]=(i==0?0:sm[i-1])+a-c[i];
	dis[i]=d[i+1]-d[i];
	Mx[0][i]=sm[i];
	Mn[0][i]=sm[i];
	wh[0][i]=i;
    }
    for(int i=1;i<Lg;i++){
	for(int j=0;j<n;j++){
	    Mn[i][j]=Mn[i-1][j];
	    if(j+(1<<(i-1))<n) Mn[i][j]=min(Mn[i][j],Mn[i-1][j+(1<<(i-1))]);
	    Mx[i][j]=Mx[i-1][j];
	    if(j+(1<<(i-1))<n) Mx[i][j]=max(Mx[i][j],Mx[i-1][j+(1<<(i-1))]);
	    wh[i][j]=wh[i-1][j];
	    if(j+(1<<(i-1))<n-1 && dis[wh[i][j]]<dis[wh[i-1][j+(1<<(i-1))]]) wh[i][j]=wh[i-1][j+(1<<(i-1))];
	}
    }
    return cout<<solve(0,n-1)<<endl,0;
}