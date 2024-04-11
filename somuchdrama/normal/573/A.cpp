#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5;

int arr[MAXN];

int main() {    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        while (!(arr[i] % 2))
            arr[i] /= 2;
        while (!(arr[i] % 3))
            arr[i] /= 3;
    }

    bool ok = true;
    for (int i = 1; i < n; ++i)
        ok &= (arr[i] == arr[i - 1]);

    cout << (ok ? "Yes\n" : "No\n");

    return 0;
}