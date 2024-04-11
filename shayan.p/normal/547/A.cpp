// Phoenix

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

const int maxn=1e6+10,mod=1e9+7;
const ll inf=1e18;

int m;
int h[2],x[2],y[2],a[2];
bool mark[maxn];

inline void RET(ll x){
    cout<<x<<endl;
    exit(0);
}
inline int nxt(int h,int x,int y){
    return (1ll*h*x+1ll*y)%m;
}
int nxt(int h,int x,int y,int t){
    int ans=h;
    while(t--) ans=nxt(ans,x,y);
    return ans;
}
int solve(int a,int b,int x,int y){
    memset(mark,0,sizeof mark);
    int t=1;
    mark[a]=1;
    a=nxt(a,x,y);
    while(!mark[a]){
	if(a==b)  return t;
	mark[a]=1;
	t++;
	a=nxt(a,x,y);
    }
    if(a==b) return t;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>m;
    for(int i=0;i<2;i++)
	cin>>h[i]>>a[i]>>x[i]>>y[i];
    int X=solve(a[0],a[0],x[0],y[0]),Y=solve(a[1],a[1],x[1],y[1]);
    int XX=solve(h[0],a[0],x[0],y[0]),YY=solve(h[1],a[1],x[1],y[1]);
    if(XX==-1 || YY==-1) RET(-1);
    if(X==-1 && Y==-1){
	if(XX!=YY) RET(-1);
	RET(XX);
    }
    else if(X==-1){
	if(nxt(h[1],x[1],y[1],XX)==a[1]) RET(XX);
	RET(-1);
    }
    else if(Y==-1){
	if(nxt(h[0],x[0],y[0],YY)==a[0]) RET(YY);
	RET(-1);
    }
    else{
	ll ans=-1;
	int num=(YY-XX)%Y;
	if(num<0) num+=Y;
	for(int i=2*m;i>=0;i--)
	    if((1ll*i*X)%Y == num && 1ll*i*X>=YY-XX)
		ans=i;
	if(ans==-1) RET(-1);
	ans=ans*X+XX;
	RET(ans);
    }
    return 0;
}