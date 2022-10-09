#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    int t; cin >> t;
    while(t--){
        bool test = false;
        int l, r, k; cin >> l >> r >> k;
        if(l==r&& r!=1) {
            yes;
            continue;
        }
        if (k >= (r - l + 1) / 2 && l % 2 != r % 2) test = true;
		if (l % 2 == 1) {
			if (k >= (r - l + 1)/2 + 1) test = true;
		} 
        else {
			if (k >= (r - l + 1)/2) test = true;
		}
		if (test) yes;
		else no;


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