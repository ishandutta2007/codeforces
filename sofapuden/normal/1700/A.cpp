#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

void solve(){
	ll n, m; cin >> n >> m;
	swap(n,m);
	cout << (n*(n-1)/2) + (m*(m+1)/2)*n << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}