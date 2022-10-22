#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;


void solve() {

}

int main() {
    int n;
    cin >> n;

    vector<li> a(n * 2);
    for(int i = 0; i < n * 2; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    li s = 0;
    for(int i = 0; i < n * 2; i++)
        s += a[i] * (i < n ? 1 : -1);

    if(s == 0)
        cout << -1;
    else
        for(auto a1 : a)
            cout << a1 << ' ';

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();
}