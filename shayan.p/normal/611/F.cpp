// Remember...

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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

struct Solver{
    int n, a[maxn], mn[20][maxn], mx[20][maxn], mn2[maxn], mx2[maxn], sm[maxn];

    int f(int pos,ll cnt){
	ll ans=0;
	ans+= 1ll*(cnt/n)*sm[0];
	cnt%=n;
	if(pos+cnt>n){
	    ans+= sm[pos];
	    cnt-=(n-pos);
	    pos=0;
	}
	return ans+sm[pos]-sm[pos+cnt];
    }
    int calcs(int l,int r){// [)
	return sm[l]-sm[r];
    }
    int bin(int pos,ll MN,ll MX){
	ll ans=0;
	for(int i=19;i>=0;i--){
	    if(pos+(1<<i)<=n && MN<=mn[i][pos] && mx[i][pos]<=MX){
		MN-= calcs(pos,pos+(1<<i)), MX-= calcs(pos,pos+(1<<i));
		pos+=(1<<i);
		ans+=(1<<i);
	    }
	}
	return ans+1;	
    }
    ll solve(int pos,ll MN,ll MX){
	MN*=-1;
	ll ans=0;
	if(MN<=mn2[pos] && mx2[pos]<=MX){
	    MN-=sm[pos], MX-=sm[pos];
	    ans+=n-pos;
	    pos=0;
	}
	else{
	    return bin(pos,MN,MX);
	}
	if(MN<=mn2[0] && mx2[0]<=MX){
	    if(sm[0]==0) return inf;
	    ll stp=0;
	    if(sm[0]<0)
		stp= (abs(MN-mn2[0]-1)+(abs(sm[0])-1)) / abs(sm[0]);
	    else
		stp= (abs(MX-mx2[0]+1) + (abs(sm[0])-1)) / abs(sm[0]);
	    MN-= stp*sm[0];
	    MX-= stp*sm[0];		
	    ans+= stp*n;
	}
	return ans+bin(0,MN,MX);
    }
    void build(){
	for(int i=n-1;i>=0;i--){
	    sm[i]= sm[i+1] + a[i];
	    mn2[i]= min( mn2[i+1] + a[i], 0 );
	    mx2[i]= max( mx2[i+1] + a[i], 0 );
	}
	for(int i=0;i<n;i++){
	    mn[0][i]= mx[0][i]= a[i];
	    mx[0][i]= max(mx[0][i],0);
	    mn[0][i]= min(mn[0][i],0);	    
	}
	for(int i=1;i<20;i++){
	    for(int j=0;j<n;j++){
		mn[i][j]= mn[i-1][j];
		mx[i][j]= mx[i-1][j];
		int cnt=1<<(i-1);
		if(j+cnt>=n) continue;
		mn[i][j]= min( mn[i-1][j], calcs(j,j+cnt) + mn[i-1][j+cnt] );
		mx[i][j]= max( mx[i-1][j], calcs(j,j+cnt) + mx[i-1][j+cnt] );
	    }
	}
    }
};
Solver sx,sy;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,x=0,y=0,X,Y,xx,yy; cin>>n>>X>>Y;
    xx=X-1, yy=Y-1;
    string s; cin>>s;

    sx.n=n, sy.n=n;
    for(int i=0;i<n;i++){
	sx.a[i]= sy.a[i]=0;
	if(s[i]=='L') sy.a[i]=-1;
	if(s[i]=='R') sy.a[i]=1;
	if(s[i]=='U') sx.a[i]=-1;
	if(s[i]=='D') sx.a[i]=1;
    }
    sx.build(), sy.build();
    
    int pos=0, ans=0;
    while(x<=xx && y<=yy){
	//	cout<<x<<" "<<xx<<"   "<<y<<" "<<yy<<"    "<<sx.solve(pos,x,X-xx-1)<<"  "<<sy.solve(pos,y,Y-yy-1)<<endl;
	ll trn=min( sx.solve(pos,x,X-xx-1), sy.solve(pos,y,Y-yy-1) );
	if(trn==inf) return cout<<-1<<endl,0;
	ans+= 1ll*trn %mod * (xx-x+1) %mod * (yy-y+1) %mod;
	ans%=mod;
	int fx=sx.f(pos,trn), fy=sy.f(pos,trn);
	pos=(pos + (trn%n))%n;
	x+=fx, xx+= fx, y+=fy, yy+=fy;
	//	cout<<"SALAM "<<trn<<"    "<<fx<<" "<<fy<<endl;
	x=max(x,0), y=max(y,0), yy=min(yy,Y-1), xx=min(xx,X-1);
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")