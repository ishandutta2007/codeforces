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

    vector<li> a(n);
    bool b0 = false, b1 = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b0 = b0 || (a[i] % 2 == 0);
        b1 = b1 || (a[i] % 2 == 1);
    }

    if(b0 && b1) {
        sort(a.begin(), a.end());
//        for(int i = 0; i < n; i++)
//            cout << a[i] <<' ';
    }

       for(int i = 0; i < n; i++)
            cout << a[i] <<' ';



//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();
}