#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 1e6 + 7;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    ll n, k;
    cin >> n >> k;
    ll x = n / k;
    if (x % 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}