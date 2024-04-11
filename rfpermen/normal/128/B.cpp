#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,sa[18][MAX],z[MAX],stp,jmp,le,ri;
ll k,x[MAX],tmp;
piii sid[MAX];
string s;
vector<int> v[MAX];

int ret,nx;
inline int getlcp(int x,int y){
	if(y>x)x^=y^=x^=y;
	ret = 0, nx = jmp;
	rap(i,stp,0){
		if(y+nx<=n && sa[i][x]==sa[i][y]){
			ret+= nx;
			x+= nx, y+= nx;
			if(y>=n)break;
		}
		nx>>=1;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size();
    asd(i,0,n)sa[0][i] = s[i];
    
    stp = 0, jmp = 1;
    while(jmp<n){
    	asd(i,0,n)sid[i] = {{sa[stp][i],i+jmp<n ? sa[stp][i+jmp] : -1},i};
    	sort(sid,sid+n);
    	++stp;
    	sa[stp][sid[0].se] = 0;
    	asd(i,1,n)sa[stp][sid[i].se] = sid[i].fi==sid[i-1].fi ? sa[stp][sid[i-1].se] : i;
    	jmp<<=1;
	}
	
	asd(i,0,n)z[sa[stp][i]] = i;
	x[0] = n-z[0];
	asd(i,1,n)v[getlcp(z[i-1],z[i])].pb(i), x[i] = x[i-1]+(n-z[i]);
	
	ri = n-1;
	cin>>k;
	if(k>(ll)n*(n+1)/2)return cout<<"No such line.\n",0;
	
	asd(i,0,n){
		for(int j:v[i])if(j>le&&j<=ri){
			tmp = x[j-1]-(le?x[le-1]:0) - (ll)(j-le)*i;
			if(k <=  tmp){
				ri = j-1;
				break;
			}
			else k-= tmp, le = j;
		}
		
		if(k<=ri-le+1){
			rep(j,z[le],z[le]+i)cout<<s[j];
			cout<<endl;
			return 0;
		}
		k-= ri-le+1;
	}
	return 0;
}