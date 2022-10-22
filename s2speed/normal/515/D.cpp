#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 4e6 , MXN = 2e3 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

char s[MXN][MXN];
int8_t d[MAXN];
vector<int> adj;
bitset<MXN> ver[MXN] , hor[MXN];
bitset<MAXN> mark;
priority_queue<pii , vector<pii> , greater<pii> > pq;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(d , -1 , sizeof(d));
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>s[i][j];
		}
	}
	int v;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '*') continue;
			v = i * m + j;
			d[v]++;
			if(i > 0){
				if(s[i - 1][j] == '.'){
					hor[i][j] = true;
					d[v]++; d[v - m]++;
				}
			}
			if(j > 0){
				if(s[i][j - 1] == '.'){
					ver[i][j] = true;
					d[v]++; d[v - 1]++;
				}
			}
		}
	}
	int lm = n * m;
	for(int i = 0 ; i < lm ; i++){
		if(d[i] == -1) continue;
		pq.push({d[i] , i});
	}
	int u , i1 , i2 , j1 , j2;
	adj.reserve(4);
	while(!pq.empty()){
		pii p = pq.top(); pq.pop();
		v = p.second;
		if(mark[v]) continue;
		if(d[v] >= 2) break;
		if(d[v] == 0){
			cout<<"Not unique\n";
			return 0;
		}
		j1 = v % m; i1 = v / m;
		if(ver[i1][j1] && !mark[v - 1]){
			u = v - 1;
		}
		if(hor[i1][j1] && !mark[v - m]){
			u = v - m;
		}
		if(i1 < n - 1){
			if(hor[i1 + 1][j1] && !mark[v + m]){
				u = v + m;
			}
		}
		if(j1 < m - 1){
			if(ver[i1][j1 + 1] && !mark[v + 1]){
				u = v + 1;
			}
		}
		i2 = u / m; j2 = u % m;
		if(v == u - 1){
			s[i1][j1] = '<';
			s[i2][j2] = '>';
		}
		if(v == u + 1){
			s[i1][j1] = '>';
			s[i2][j2] = '<';
		}
		if(v == u + m){
			s[i1][j1] = 'v';
			s[i2][j2] = '^';
		}
		if(v == u - m){
			s[i1][j1] = '^';
			s[i2][j2] = 'v';
		}
		mark[u] = true;
		mark[v] = true;
		adj.clear();
		if(ver[i2][j2]){
			adj.push_back(u - 1);
		}
		if(hor[i2][j2]){
			adj.push_back(u - m);
		}
		if(i2 < n - 1){
			if(hor[i2 + 1][j2]){
				adj.push_back(u + m);
			}
		}
		if(j2 < m - 1){
			if(ver[i2][j2 + 1]){
				adj.push_back(u + 1);
			}
		}
		for(auto i : adj){
			if(mark[i]) continue;
			d[i]--;
			pq.push({d[i] , i});
		}
	}
	for(int i = 0 ; i < lm ; i++){
		if(d[i] != -1 && !mark[i]){
			cout<<"Not unique\n";
			return 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<s[i][j];
		}
		cout<<'\n';
	} 
	return 0;
}

/*

*/