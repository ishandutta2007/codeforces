#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2.5e3 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

string s[60];
vector<int> adj[MAXN] , tag;
bitset<MAXN> ch , mark;
int cnt;

void DFS(int r){
	cnt++;
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		DFS(i);
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>s[i];
		for(int j = 0 ; j < m ; j++){
			if(s[i][j] == '#'){
				tag.push_back(i * m + j);
				ch[i * m + j] = true;
			}
		}
	}
	int ts = tag.size();
	if(ts < 2){
		cout<<"-1\n";
		return 0;
	}
	if(ts == 2){
		int v = tag[0] , u = tag[1];
		if(v == u + m || v == u - m || v == u - 1 || v == u + 1){
			cout<<"-1\n";
		} else {
			cout<<"0\n";
		}
		return 0;
	}
	for(auto p : tag){
		int i = p / m , j = p % m;
		if(j < m - 1){
			if(ch[p + 1]){
				adj[p].push_back(p + 1); adj[p + 1].push_back(p);
			}
		}
		if(i < n - 1){
			if(ch[p + m]){
				adj[p].push_back(p + m); adj[p + m].push_back(p);
			}
		}
	}
	cnt = 0;
	DFS(tag[0]);
	if(cnt != ts){
		cout<<"0\n";
		return 0;
	}
	for(auto i : tag){
		mark.set(); mark.flip(); cnt = 0;
		mark[i] = true;
		DFS((tag[0] == i ? tag[1] : tag[0]));
		if(cnt != ts - 1){
			cout<<"1\n";
			return 0;
		}
	}
	cout<<"2\n";
	return 0;
}

/*
3 3
##.
.##
##.
*/