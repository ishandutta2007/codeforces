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

int arr[MAXN], lt[MAXN], rt[MAXN];

int main() {    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> arr[i];

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        ++cur;
        cur = min(cur, arr[i]);
        lt[i] = cur;
    }
    
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        ++cur;
        cur = min(cur, arr[i]);
        rt[i] = cur;
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, min(lt[i], rt[i]));
    }

    cout << mx << '\n';

    return 0;
}