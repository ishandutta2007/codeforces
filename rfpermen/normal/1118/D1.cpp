#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,m,x[MAX],y[MAX],z,le,ri,mid,lp,res;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i], z+=x[i];
    if(z<m)cout<<-1;
    else {
    	sort(x+1,x+1+n);
    	reverse(x+1,x+1+n);
    	rep(i,1,n)y[i] = x[i]+y[i-1];
    	rap(i,n-1,1){
    		lp = (n-1)/i, z = 0;
    		rep(j,0,lp){
    			le = j*i+1, ri = min(n,(j+1)*i);
    			if(x[ri]>=j)z+=(y[ri]-y[le-1])-(ri-le+1)*j;
    			else if(x[le]>=j){
    				while(le<=ri){
    					mid = le+ri>>1;
    					if(x[mid]>=j)le = mid+1, res = mid;
    					else ri = mid-1;
					}
					le = j*i+1, ri = res;
    				z+=(y[ri]-y[le-1])-(ri-le+1)*j;
    				break;
				}
				else break;
			}
			if(z<m)return cout<<i+1,0;
		}
		cout<<1;
	}
	return 0;
}