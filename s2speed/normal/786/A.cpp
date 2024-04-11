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

const ll maxn = 14e3 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

vector<int> adj , a , b , bfs;
bitset<maxn> mark;
int dp[maxn] , cnt[maxn] , ch[2];
int n , as , bs;

void adj_build(ll v , bool c){
	adj.clear();
	if(c){
		v -= n;
		for(auto i : a){
			ll h = v - i;
			if(h < 0) h += n;
			adj.push_back(h);
		}
	} else {
		for(auto i : b){
			ll h = v - i;
			if(h < 0) h += n;
			adj.push_back(h + n);
		}
	}
	return;
}

void BFS(){
	int x = 0;
	while(x < sze(bfs)){
		int v = bfs[x++] , l = (v >= n);
		adj_build(v , l);
		if(dp[v] == 0){
			for(auto i : adj){
				if(mark[i]) continue;
				mark[i] = dp[i] = true;
				bfs.push_back(i);
			}
		} else {
			for(auto i : adj){
				if(mark[i]) continue;
				cnt[i]++;
				if(cnt[i] != ch[l]) continue;
				dp[i] = 0;
				mark[i] = true;
				bfs.push_back(i);
			}
		}
	}
	return;	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , -1 , sizeof(dp));
	memset(cnt , 0  , sizeof(cnt));
	cin>>n;
	cin>>as; a.resize(as);
	for(int j = 0 ; j < as ; j++){
		cin>>a[j];
	}
	cin>>bs; b.resize(bs);
	for(int j = 0 ; j < bs ; j++){
		cin>>b[j];
	}
	ch[0] = bs; ch[1] = as;
	dp[0] = dp[n] = 0;
	bfs.push_back(0); bfs.push_back(n);
	mark[0] = mark[n] = true;
	BFS();
	for(int i = 1 ; i < n ; i++){
		if(dp[i] == 1){
			cout<<"Win";
		}
		if(dp[i] == 0){
			cout<<"Lose";
		}
		if(dp[i] == -1){
			cout<<"Loop";
		}
		cout<<' ';
	}
	cout<<'\n';
	for(int i = 1 + n ; i < (n << 1) ; i++){
		if(dp[i] == 1){
			cout<<"Win";
		}
		if(dp[i] == 0){
			cout<<"Lose";
		}
		if(dp[i] == -1){
			cout<<"Loop";
		}
		cout<<' ';
	}
	cout<<'\n';
	return 0;
}