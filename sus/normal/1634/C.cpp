#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n';
#define no  cout << "NO" << '\n';
#define sp " "
#define ln '\n'
ll a[100200], b[100200];
 
void solve(){
    int t; cin >> t;
    while(t--){
        ll k, n;
        cin >> k >> n;
		bool test = true;
		a[0] = b[0] = 1;
		for(int i = 1; i < n; i++){
			a[i] = a[i - 1] + k;
			b[i] = b[i - 1] + a[i];
			if(b[i] % (i + 1)) test = 0;
		} 
		if(!test) no
		else {
			yes
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= n; j++) cout << (j - 1) * k + i << sp;
				cout << ln;
			}
		}
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