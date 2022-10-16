#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,m,le,ri,mid,res,a,b,mask[(1<<8)+5],z,x[MAX][10],bt;
bool st;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m; bt = (1<<m)-1, m--;
    rep(i,1,n)rep(j,0,m)cin>>x[i][j];
    le = 0, ri = 1e9;
    while(le<=ri){
    	mid = le+ri>>1;
    	memset(mask,0,sizeof mask);
    	rep(i,1,n){
    		z = 0;
    		rep(j,0,m)if(x[i][j]>=mid)z|=1<<j;
    		mask[z] = i;
		}
		st = 0;
		rep(i,0,bt){
			if(st)break;
			if(!mask[i])continue;
			rep(j,i,bt){
				if(mask[j] && (i|j)==bt){
					a = mask[i], b = mask[j];
					st = 1;
					break;
				}
			}
		}
		if(st)le = mid+1;
		else ri = mid-1;
	}
	cout<<a<<' '<<b<<endl;
    return 0;
}