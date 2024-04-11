#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll { ll first , second , third; };
typedef pair<int , pii> piii;

const int MAXN = 5e5 + 20 , md = 1e9 + 7 , inf = 1061109567;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

struct segtree {

	int sz = 1 , def = -1;
	vector<int> val;

	void init(int n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , inf);
		return;
	}

	void build(vector<int> &a , int x , int lx , int rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				val[x] = a[lx];
			}
			return;
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void build(vector<int> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	void kill(int i , int x , int lx , int rx){
		if(rx - lx == 1){
			val[x] = inf;
			return;
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		if(i < m){
			kill(i , ln , lx , m);
		} else {
			kill(i , rn , m , rx);
		}
		val[x] = min(val[ln] , val[rn]);
		return;
	}

	void kill(int i){
		kill(i , 0 , 0 , sz);
		return;
	}

	int cal(int l , int r , int k , int x , int lx , int rx){
		if(rx <= l || lx >= r || val[x] >= k){
			return -1;
		}
		if(rx - lx == 1){
			return lx;
		}
		int m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		int h = cal(l , r , k , ln , lx , m);
		if(~h){
			return h;
		}
		return cal(l , r , k , rn , m , rx);
	}

	int cal(int l , int r , int k){
		if(l >= r) return -1;
		return cal(l , r , k , 0 , 0 , sz);
	}

};

int a[MAXN] , p[MAXN] , nt[MAXN] , lt[MAXN] , l[MAXN] , dp[MAXN] , o , par[MAXN];
vector<int> v , y , pos[MAXN];
vector<pii> d;
segtree st;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ifstream fin("C:\\Users\\S2\\Desktop\\Testcase.txt");
	memset(par , -1 , sizeof(par));
	memset(lt , 63 , sizeof(lt));
	memset(nt , -1 , sizeof(nt));
	memset(l , -1 , sizeof(l));
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	for(int i = 0 ; i < n ; i++){
		vector<int>::iterator it = lower_bound(all(v) , a[i]);
		int u = it - v.begin();
		p[u] = a[i];
		a[i] = u;
		pos[u].push_back(i);
	}
	for(int i = 0 ; i < n ; i++){
		if(l[a[i]] == -1){
			l[a[i]] = i;
			continue;
		}
		nt[l[a[i]]] = i;
		lt[i] = l[a[i]];
		l[a[i]] = i;
	}
	for(int i = 0 ; i < n ; i++){
		y.push_back(lt[i]);
		d.push_back({lt[i] , i});
	}
	d.push_back({inf , n - 1});
	int b = 0 , r = 0;
	sort(all(d));
	st.init(n);
	st.build(y);
	for(int i = 0 ; i < n ; i++){
		if(i == 0){
			dp[i] = 0;
			o = 0;
			continue;
		} else {
			if(dp[i - 1] >= dp[i]){
				par[i] = -1;
				dp[i] = dp[i - 1];
			}
		}
		if(dp[i] > dp[o]){
			r = i;
			if(~par[i]) continue;
			o = i;
			while(d[b].first < o){
				st.kill(d[b].second);
				b++;
			}
			continue;
		}
		int h = st.cal(i + 1 , n , i) , f , ps;
		if(~h){
			f = upper_bound(all(pos[a[i]]) , h) - pos[a[i]].begin();
			ps = pos[a[i]].size();
			if(f < ps){
				f = pos[a[i]][f];
				if(dp[f] < dp[o] + 1){
					dp[f] = dp[o] + 1;
					if(dp[f] == dp[r]){
						r = min(r , f);
					}
					if(dp[f] > dp[r]){
						r = f;
					}
					par[f] = lt[h];
				}
			}
		}
		int q = lt[i];
		if(q != inf){
			if(par[q] == -1){
				int t = nt[i];
				if(~t){
					if(t != r){
						t = nt[t];
						if(~t){
							if(dp[t] < dp[q] + 1){
								dp[t] = dp[q] + 1;
								if(dp[t] == dp[r]){
									r = min(r , t);
								}
								if(dp[t] > dp[r]){
									r = t;
								}
								par[t] = i;
							}
						}
					}
				}
			}
		}
	}
	v.clear();
	int x = n - 1;
	while(x >= 0){
		while(x >= 0){
			if(~par[x]) break;
			x--;
		}
		if(x < 0) break;
		v.push_back(p[a[x]]);
		x = par[x];
		v.push_back(p[a[x]]);
		x--;
	}
	reverse(all(v));
	int ans = dp[n - 1] * 2;
	cout<<ans * 2<<'\n';
	for(int i = 0 ; i < ans ; i += 2){
		cout<<v[i]<<' '<<v[i + 1]<<' '<<v[i]<<' '<<v[i + 1]<<' ';
	}
	cout<<'\n';
	return 0;
}

/*

*/