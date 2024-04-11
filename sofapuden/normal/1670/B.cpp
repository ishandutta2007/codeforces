#include<bits/stdc++.h>

using namespace std;

void solve(int testID){
	int n; cin >> n;
	string s; cin >> s;
	int m; cin >> m;
	int v[30];
	memset(v,0,sizeof v);
	for(int i = 0; i < m; ++i){char x; cin >> x; v[x-'a']++;}
	int ls = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(v[s[i]-'a'])ans = max(ans,i-ls), ls = i;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}