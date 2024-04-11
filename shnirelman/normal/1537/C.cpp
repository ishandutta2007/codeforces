#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int mn = INF, ind = 1;
    for(int i = 1; i < n; i++) {
        int x = a[i] - a[i - 1];
//        cout << i << ' ' << x << endl;
        if(mn > x) {
            mn = x;
            ind = i;
        }
    }

//    cout << mn << ' ' << ind << endl;

//    if(a[1] - a[0] == mn) {
//        cout << a[0] << ' ';
//        for(int i = 2; i < n; i++) {
//            cout << a[i] << ' ';
//        }
//        cout << a[1] << endl;
//        return;
//    }
//
//    if(a[n - 1] - a[n - 2] == mn) {
//        cout << a[n - 2] << ' ';
//        for(int i = 0; i < n - 2; i++) {
//            cout << a[i];
//        }
//
//        cout << a[n - 1] << endl;
//        return;
//    }

    cout << a[ind - 1] << ' ';
    for(int i = ind + 1; i < n; i++)
        cout << a[i] << ' ';
    for(int i = 0; i < ind - 1; i++)
        cout << a[i] << ' ';
    cout << a[ind] << endl;

//    cout << a[ind - 1] << ' ';
//    for(int i = 0; i < n; i++) {
//        if(i < ind - 1 || i > ind)
//            cout << a[i] << ' ';
//    }
//    cout << a[ind] << endl;

}

int main() {

    int t;
    cin >> t;

    while(t--)
        solve();
}