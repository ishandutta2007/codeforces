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
    ll a; 
    ll b; 
    cin >> a >> b;
    ll x = 1;
    ll ans;
    if(b-a>=10){
        cout << 0 << ln;
    }
	else
	{
        for(ll i=a+1;i<=b;i++)  {
           x*=(i%10);
        }
        ans = x%10;
        cout << ans << ln;
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