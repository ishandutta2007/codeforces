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
	vector<ll> v(n);
	for(auto &x : v)cin >> x;
	vector<pair<ll,ll>> v2;
	reverse(v.begin(),v.end());
	for(int i = 0; i < n; ++i){
		pair<ll,ll> nw = {v[i], 1};
		while(v2.size() && nw.first * v2.back().second > nw.second * v2.back().first){
			nw.first+=v2.back().first;
			nw.second+=v2.back().second;
			v2.pop_back();
		}
		v2.push_back(nw);
	}
	reverse(v2.begin(),v2.end());
	for(auto x : v2){
		for(int i = 0; i < x.second; ++i){
			printf("%.10Lf\n", (ld)x.first / (ld)x.second); 
		}
	}
}