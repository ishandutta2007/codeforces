#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;

ll tc,n,m,k,id[5],z[5],o,a,b,ans,nw,mn,cnt,tmp;
pll x[5][MAX],y[3];
piiii he;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n){
    	cin>>o>>a>>b;
    	x[(a<<1)|b][++z[(a<<1)|b]] = {o,i};
	}
	if(k*2-z[3]>m)return cout<<"-1\n",0;
	
	rep(i,0,3)sort(x[i]+1,x[i]+1+z[i]), id[i] = 1;
	
	mn = cnt = min(z[3],m);
	rep(i,1,cnt)nw+= x[3][i].fi;
//	db(nw);
	
	tmp = cnt;
	while(tmp<k){
		++tmp;
		if(id[1]>z[1]||id[2]>z[2])return cout<<"-1\n",0;
		cnt+= 2;
		nw+= x[1][id[1]].fi + x[2][id[2]].fi, id[1]++, id[2]++;
	}
	
	while(cnt!=m){
		rep(i,0,2)y[i] = {id[i]<=z[i] ? x[i][id[i]].fi : INF , i};
		sort(y,y+3);
		nw+= y[0].fi, id[y[0].se]++;
		++cnt;
	}
	he = {{id[0]-1,id[1]-1},{id[2]-1,mn}}, ans = nw;
	
//	rep(i,0,3){
//		rep(j,1,z[i])cout<<x[i][j].fi<<' '; cout<<endl;
//	}
//	db(nw);
//	cout<<endl<<' '<<he.ff<<' '<<he.fs<<' '<<he.sf<<' '<<he.ss<<endl;
	
	rap(j,mn,1){
		if(k*2-j+1>m || min(z[1],z[2])<=k-j)break;
		nw-= x[3][j].fi, --cnt;
		if(id[1]<=k-j+1)++cnt, nw+= x[1][id[1]++].fi;
		if(id[2]<=k-j+1)++cnt, nw+= x[2][id[2]++].fi;
//		cout<<">> "<<id[1]<<' '<<id[2]<<endl;
		if(cnt<m){
			rep(i,0,2)y[i] = {id[i]<=z[i] ? x[i][id[i]].fi : INF , i};
			sort(y,y+3);
			if(y[0].fi==INF)break;
			nw+= y[0].fi, id[y[0].se]++;
			++cnt;
		}
		else if(cnt>m)--cnt, nw-= x[0][--id[0]].fi;
		if(nw<ans)he = {{id[0]-1,id[1]-1},{id[2]-1,j-1}}, ans = nw;
	}
	cout<<ans<<endl;
	rep(i,1,he.ff)cout<<x[0][i].se<<' ';
	rep(i,1,he.fs)cout<<x[1][i].se<<' ';
	rep(i,1,he.sf)cout<<x[2][i].se<<' ';
	rep(i,1,he.ss)cout<<x[3][i].se<<' ';
//	cout<<endl<<' '<<he.ff<<' '<<he.fs<<' '<<he.sf<<' '<<he.ss<<endl;
	return 0;
}