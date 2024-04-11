#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,m,k,x[25][25],h,R,C,le,ri,mid,a1,a2,y,z,t,ans;
vector<ll> v[25][25];
vector<pair<ll,pii> > u;

void dfs(int r,int c,ll nw){
	//cout<<r<<" "<<c<<" "<<nw<<endl;
	if(r+c==h){u.pb({nw,{r,c}}); return;}
	if(r<n)dfs(r+1,c,nw^x[r][c]);
	if(c<m)dfs(r,c+1,nw^x[r][c]);
}

void dfs2(int r,int c,ll nw){
	if(r==n && c==m){v[R][C].pb(nw^x[r][c]); return;}
	if(r<n)dfs2(r+1,c,nw^x[r][c]);
	if(c<m)dfs2(r,c+1,nw^x[r][c]);
}

int main(){
	//cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    h = (n+m)/2+1;
    dfs(1,1,0);
    rep(i,1,n)rep(j,1,m){
    	if(i+j!=h)continue;
    	R = i, C = j;
		dfs2(i,j,0);
		sort(v[i][j].begin(),v[i][j].end());
		//for(auto k:v[i][j])cout<<i<<" x "<<j<<" x "<<k<<endl;
	}
	for(auto i:u){
		//cout<<i.fi<<" - "<<i.sf<<" - "<<i.ss<<endl;
		y = i.sf, z = i.ss;
		t = k^i.fi;
		le = 0, ri = v[y][z].size(); ri--;
		a1 = a2 = -1;
		//cout<<"size "<<v[y][z].size()<<endl;
		while(le<=ri){
			mid = (le+ri)/2;
			//cout<<"le = "<<le<<", ri = "<<ri<<", mid = "<<mid<<endl;
			//cout<<"lala "<<v[y][z][mid]<<" "<<t<<endl;
			if(v[y][z][mid]<t)le = mid+1;
			else if(v[y][z][mid]>t)ri = mid-1;
			else a1 = mid, ri = mid-1;
		}
		le = 0, ri = v[y][z].size(); ri--;
		while(le<=ri){
			mid = (le+ri)/2;
			if(v[y][z][mid]<t)le = mid+1;
			else if(v[y][z][mid]>t)ri = mid-1;
			else a2 = mid+1, le = mid+1;
		}
		//cout<<"T = "<<t<<endl;
		//cout<<a2<<" "<<a1<<endl;
		if(a1==-1 || a2==-1)continue;
		ans+=a2-a1;
	}
	cout<<ans<<endl;
    return 0;
}