#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'

int firstDigit(ll n)
{
    while (n >= 10) n /= 10;
    return n;
}

bool getParity(ll n)
{ 
    return n%2;
}
void solve(){
   int t; cin >> t;
   while(t--){
        ll n, x, y; cin >> n >> x >> y;
        ll a[n];
        ll sum = 0;
        //cout << getParity(x) << sp << getParity(x+3) << sp << getParity(y) << ln;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            sum+=a[i];
        }
        //bool e = getParity(sum);
        if(getParity(sum + x) == getParity(y)) cout << "Alice" << ln;
        else cout << "Bob" << ln;
        //if(getParity(x)) cout << "Alice" << ln;
        //else cout << "Bob" << ln;
        
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