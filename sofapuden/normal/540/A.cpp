#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans+=min(abs(s1[i]-s2[i]),10-abs(s1[i]-s2[i]));
	}
	cout << ans << "\n";
			
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}