#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    int x; int y; int z; cin >> x >> y >> z; 
    if(x > y){
		if(z >= x-y) cout << '?' << ln;
		else cout << '+' << ln;
	}
	else if(y > x){
		if(z >= y-x) cout << '?' << ln;
		else cout << '-' << ln;
	}
	else{
		if(z == 0) cout << 0 << ln;
		else cout << '?' << ln;
	}
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}