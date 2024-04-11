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

const int MAXN = 1e5 + 1;
int arr[MAXN];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    arr[n] = 0;
    int mx = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans.pb(max(0, mx - arr[i] + 1));
        mx = max(arr[i], mx);
    }
    
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << ' ';        
    
    return 0;
}