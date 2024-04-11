#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	int am[10];
	for(int i = 0; i < 10; ++i)am[i] = 0;
	for(int i = 0; i < n; ++i){
		am[v[i]%10]++;
	}
	for(int i = 0; i < 10; ++i){
		if(!am[i])continue;
		am[i]--;
		for(int j = 0; j < 10; ++j){
			if(!am[j])continue;
			am[j]--;
			for(int k = 0; k < 10; ++k){
				if(!am[k])continue;
				am[k]--;
				if((i+j+k)%10 == 3){
					cout << "YES\n";
					return;
				}

				am[k]++;

			}
			am[j]++;
		}
		am[i]++;
	}
	cout << "NO\n";
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}