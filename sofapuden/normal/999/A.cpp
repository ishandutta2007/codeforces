#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
	int n, k; cin >> n >> k;
	vi v;
	for(int i = 0; i < n; ++i){
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	int ans = 0;
	for(int i : v){
		if(i > k){
			break;
		}
		ans++;
	}
	reverse(v.begin(),v.end());
	for(int i : v){
		if(i > k){
			break;
		}
		ans++;
	}
	cout << min(n,ans) << "\n";
}