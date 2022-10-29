#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
    //ios_base::sync_with_stdio(0); cin.tie(0) <-- why does this get WA
	int x; cin >> x;
	int a, b, c; cin >> a >> b >> c;
	if(a == 0)a = x;
	if(b == 0)b = x;
	if(c == 0)c = x;
	if(a != 1 && b != 2 && c != 3)cout << "YES\n";
	else cout << "NO\n";
}
 
int main(){
	int t; cin >> t;
	while(t--)solve();
}