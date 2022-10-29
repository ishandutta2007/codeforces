#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << ((b > a) + (c>a) + (d>a)) << '\n';

}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}