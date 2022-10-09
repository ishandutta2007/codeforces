// sus sus amongu, this code was made by sathu
// copy it if you wish, but your coding skills will perish
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    int t; cin >> t;
    while(t--){
        int a; cin >> a;
        int b; cin >> b;
        int c; cin >> c;
        if(a + b + c < 7){
            no;
        }
        else{
            ll sum = 0;
		    sum += a; sum += b; sum += c;
		    if (!(sum % 9) && (min(a, min(b, c)) >= (sum / 9))) {
			    yes;
		    }
		    else {
			    no;
		    }
        }
    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}