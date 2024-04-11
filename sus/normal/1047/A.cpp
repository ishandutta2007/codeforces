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
    int n; cin >> n;
    ll a = 0;
    ll b = 0; 
    ll c = 0;
    if(n==3){
        cout << 1 << sp << 1 << sp << 1 << ln;
    }
    else {
        a = 1;
        b = 1;
        c = n-2;
        if(c%3==0){
            c--;
            b++;
        }
        cout << a << sp << b << sp << c << ln;
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