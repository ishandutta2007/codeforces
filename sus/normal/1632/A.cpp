#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n';
#define no  cout << "NO" << '\n';
#define sp " "
#define ln '\n'
 
void solve(){
    int t; cin >> t;
    while(t--){
        int n; string s; cin >> n >> s;
        if(n>2) no
		else{
			if(n==1) yes
			else{
				if(s[0]==s[1]) no
				else yes
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