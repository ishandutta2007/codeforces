#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;

template <typename A, typename B = less<A>> using ordered_set = tree<A, null_type, B, rb_tree_tag, tree_order_statistics_node_update>;
template <typename A, typename B, typename C = less<A>> using ordered_map = tree<A, B, C, rb_tree_tag, tree_order_statistics_node_update>;

void prep();
void solve(const int curt);

const int dx4[4] = {0, 0, 1, -1}, dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const bool isT = false;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prep();

	int t = 1; if(isT)cin >> t;
	for(int i = 1; i <= t; ++i)solve(i);
}

// :-)

void prep(){

}

void solve(const int curt){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	vector<int> p(33,0);
	for(int i = 0; i < n; ++i){
		int x = v[i];
		for(int j = 0; j < 33; ++j){
			if(x&1)p[j]++;
			x>>=1;
		}
	}
	vector<pair<int,int>> nv(n);
	for(int i = 0; i < n; ++i){
		int x = v[i];
		int ans = 0;
		for(int j = 0; j < 33; ++j){
			if(x&1 && p[j] == 1)ans|=(1<<j);
			x>>=1;
		}
		nv[i] = {ans,i};
	}
	sort(nv.rbegin(),nv.rend());
	for(auto x : nv)cout << v[x.second] << ' ';
	cout << '\n';
}