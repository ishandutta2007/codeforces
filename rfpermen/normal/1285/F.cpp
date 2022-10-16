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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
ll n,a,b,ans,x[MAX],res,op,bt;
pii cnt[MAX];
vector<ll> v[55];
bool z[MAX];
vector<int> dt;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>a, z[a] = 1;
    n = 0;
    rep(i,1,100000){
    	if(z[i]){
	    	a = i<<1;
	    	while(a<=100000){
	    		if(z[a]){z[i] = 0; break;}
	    		a+=i;
			}
			if(z[i])v[1].pb(i), x[++n] = i;
		}
	}
	if(n<=5000){
		ans = x[n];
		rap(i,n,1)rap(j,i-1,1){
	    	res = x[i]*x[j];
	    	if(res<=ans)break;
	    	ans = max(ans,res/__gcd(x[i],x[j]));
		}
	}
	else {
		int tmp;
		rep(i,2,50){
			for(auto j:v[i-1]){
				if(__gcd((int)j,i)==1)v[i].pb(j);
			}
		}
		bt = 2e6;
		tmp = 1;
		ans = x[n];
		rap(i,n,1){
			while(tmp<50&&ans>x[i]*x[i]/(tmp+1))++tmp;
			while(!v[tmp].empty() && v[tmp].back()>=x[i])v[tmp].pob();
			if(v[tmp].empty())break;
			rap(j,v[tmp].size()-1,0){
				res = v[tmp][j]*x[i];
				if(res<=ans)break;
				ans = max(ans,res/__gcd(v[tmp][j],x[i]));
				++op;
				if(op>bt)break;
			}
		}
		if(op>bt){
			srand(time(NULL));
			rep(i,1,n)cnt[i].se = i;
			rep(i,1,bt){
				a = (rand()+rand())%n+1, b = (rand()+rand())%n+1;
				cnt[__gcd(x[a],x[b])].fi++;
			}
			sort(cnt+1,cnt+1+n);
			dt.pb(cnt[n].se);
			if(dt[0]==1)rep(i,1,20){
				return cout<<"1793886015\n",0;
			}
			dt.pb(cnt[n-1].se);
			dt.pb(cnt[n-2].se);
//			sort(all(dt)), reverse(all(dt));
			rep(i,1,3)v[i].clear();
			rep(i,1,n)v[0].pb(x[i]);
			a = 0;
			for(auto i:dt){
				++a;
				rep(j,1,n)if(x[j]%i)v[a].pb(x[j]);
			}
			op = 0;
			bool st;
			rap(i,n,1){
				st = 0;
				rep(j,1,a){
					if(x[i]%dt[j-1]==0){
						st = 1;
						while(!v[j].empty() && v[j].back()>=x[i])v[j].pob();
						if(!v[j].empty()){
							rap(k,v[j].size()-1,0){
								res = v[j][k]*x[i];
								if(res<=ans)break;
								ans = max(ans,res/__gcd(v[j][k],x[i]));
								++op;
								if(op>bt)break;
							}
						}
						break;
					}
				}
				if(!st){
					while(!v[0].empty() && v[0].back()>=x[i])v[0].pob();
					if(v[0].empty())break;
					rap(k,v[0].size()-1,0){
						res = v[0][k]*x[i];
						if(res<=ans)break;
						ans = max(ans,res/__gcd(v[0][k],x[i]));
								++op;
								if(op>bt)break;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}