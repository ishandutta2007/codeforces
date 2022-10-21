#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;

int main(){
    cin >> n;
    cin >> s;
    int t = 0, cnt1 = 0, cnt2 = 0;
    ll res = 1;
    while(t < n && s[t] == s[0]) t++, cnt1++;

    t = n-1;
    while(t >= 0 && s[t] == s[n-1]) t--, cnt2++;
    if(s[0] != s[n-1]) res = 1 + cnt1 + cnt2;
    else res = 1LL * (cnt1 + 1) * (cnt2 + 1);

    cout << res % 998244353 << endl;
}