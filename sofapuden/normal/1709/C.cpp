#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
	int a = 0, b = 0;
	string t;
	cin >> t;
	for(auto x : t){if(x == '(')a++; else if(x == ')')b++;}
	int n = t.size();
	int ls = 0, fi = n;
	for(int i = 0; i < n; ++i){
		if(t[i] == '?'){
			if(a < n/2)t[i] = '(', a++, ls = i;
			else t[i] = ')', b++, fi = min(fi,i);
		}
	}
	if(!ls || fi == n){
		cout << "YES\n";
		return;
	}
	swap(t[ls],t[fi]);

	int cn = 0;
	for(int i = 0; i < n; ++i){
		if(t[i] == '(')cn++;
		else cn--;
		if(!(~cn)){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}