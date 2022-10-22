#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)  {
        int x;
        cin >> x;
        sum += x - 1;
    }
    cout << ((sum&1)? "errorgorn" : "maomao90") << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--) solve();
}