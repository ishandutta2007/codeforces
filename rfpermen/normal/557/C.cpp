#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
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

int n,cnt[205],ls,y,z,ans,tmp,k,kk;
pii x[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi;
    rep(i,1,n)cin>>x[i].se, cnt[x[i].se]++;
    sort(x+1,x+1+n);
    reverse(x+1,x+1+n);
    ls = x[1].fi;
    n++;
    ans = 1e9;
    rep(i,1,n){
    	if(x[i].fi!=ls){
    		ls = x[i].fi;
    		y = max(0,n-z+1-i);
    		tmp = k;
    		rep(j,1,200){
    			if(cnt[j]>=y){
    				tmp+=y*j;
    				break;
				}
				tmp+=cnt[j]*j;
				y-=cnt[j];
			}
			ans = min(ans,tmp);
    		k+=kk;
    		kk=z=0;
		}
		z++;
		kk+=x[i].se;
		cnt[x[i].se]--;
	}
	cout<<ans<<endl;
	return 0;
}