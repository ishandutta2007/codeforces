#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 17 , maxa = 1e7 + 17 , md = 1e9 + 7 , inf = 2e16;

int gcd(int a , int b){
	if(a < b) swap(a , b);
	return (b == 0 ? a : gcd(b , a % b));
}

bitset<maxa> g;
int pr[maxa];

void prime(){
	g.set();
	for(int i = 2 ; i < maxa ; i++){
		if(!g[i]) continue;
		pr[i] = i;
		for(ll j = 1ll * i * i ; j < maxa ; j += i){
			pr[j] = i;
			g[j] = false;
		}
	}
	return;
}

int a[maxn] , d[maxn] , cnt[maxa];
vector<int> av[maxn] , v;
vector<pii> dv[maxn];
bitset<maxn> mark;

void add(int i){
	for(auto p : dv[i]){
		cnt[p.first]++;
	}
	return;
}

void del(int i){
	for(auto p : dv[i]){
		cnt[p.first]--;
	}
	return;
}

int get_deg(int i){
	int res = 0;
	for(auto p : dv[i]){
		int f = p.second , h = p.first;
		res += cnt[h] * (1 - (f << 1));
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	int n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		int h , res = 1;
		cin>>h;
		while(h > 1){
			int x = pr[h];
			av[i].push_back(x);
			res *= x;
			while(h % x == 0){
				h /= x;
			}
		}
		a[i] = res;
		int vs = sze(av[i]) , lm = (1 << vs);
		for(int mask = 0 ; mask < lm ; mask++){
			int h = 1 , f = 0;
			for(int j = 0 ; j < vs ; j++){
				if(mask & (1 << j)){
					h *= av[i][j];
					f ^= 1;
				}
			}
			dv[i].push_back({h , f});
		}
		add(i);
	}
	int x = -1 , y = -1 , z;
	for(int i = 0 ; i < n ; i++){
		int h = get_deg(i);
		d[i] = h;
		if(h >= 2){
			x = i;
			for(int j = 0 ; j < n ; j++){
				if(gcd(a[i] , a[j]) == 1){
					if(y == -1){
						y = j;
					} else {
						z = j;
						break;
					}
				}
			}
			break;
		}
	}
	if(x == -1){
		int t = 0;
		for(int i = 0 ; i < n && t < k ; i++){
			int h = get_deg(i);
			if(h == 0){
				t++;
				cout<<i + 1<<' ';
				continue;
			}
			del(i);
		}
		cout<<'\n';
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		if(i == x || i == y || i == z){
			del(i);
			continue;
		}
		v.push_back(i);
	}
	int vs = n - 3 , t = 0;
	for(auto i : v){
		d[i] = get_deg(i);
		t += (d[i] == 0);
	}
	if(t >= k){
		t = 0;
		for(auto i : v){
			if(d[i] == 0){
				cout<<i + 1<<' ';
				if(++t == k) break;
			}
		}
		cout<<'\n';
		return 0;
	}
	for(auto i : v){
		del(i);
	}
	int l = -1 , r = n - 2;
	while(l < r - 1){
		int m = (l + r) >> 1;
		for(int j = 0 ; j <= m ; j++){
			add(v[j]);
		}
		t = 0;
		for(int j = 0 ; j <= m ; j++){
			int i = v[j];
			t += (get_deg(i) > 0);
		}
		for(int j = 0 ; j <= m ; j++){
			del(v[j]);
		}
		if(t >= k - 3){
			r = m;
		} else {
			l = m;
		}
	}
	for(int j = 0 ; j <= r ; j++){
		add(v[j]);
	}
	t = 0;
	for(int j = 0 ; j <= r ; j++){
		int i = v[j];
		d[i] = get_deg(i);
		t += (d[i] > 0);
		mark[i] = (d[i] > 0);
	}
	if(t <= k - 2){
		for(int j = 0 ; j <= r ; j++){
			int i = v[j];
			if(d[i] > 0){
				cout<<i + 1<<' ';
			}
		}
		cout<<x + 1<<' '<<y + 1;
		if(t == k - 3) cout<<' '<<z + 1;
		cout<<'\n';
		return 0;
	}
	for(int j = 0 ; j < r && t > k - 2 ; j++){
		int i = v[j];
		if(d[i] == 1 && gcd(i , v[r]) == 1){
			mark[i] = false;
			t--;
		}
	}
	for(int j = 0 ; j <= r ; j++){
		int i = v[j];
		if(mark[i]){
			cout<<i + 1<<' ';
		}
	}
	cout<<x + 1<<' '<<y + 1<<'\n';
	return 0;
}