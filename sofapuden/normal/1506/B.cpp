#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int x = 0;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == '*'){
				x = i;
				break;
			}
		}
		set<int> vi;
		while(!(vi.count(x))){
			vi.insert(x);
			if(x < n && s[x] == '*'){
				ans++;
				x+=k+1;
			}
			x--;
		}
		cout << ans << "\n";
	}
}