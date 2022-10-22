#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> b(n);
    int l = -1;
    for(int i = 0; i < n; i++) {
        while(a[i] > a[l + 1])
            l++;
        b[i] = l;
    }

    int ans = n;
    for(int i = n - 1; i >= 0; i--) {
        ans = min(ans, b[i] + n - i);
    }

    cout << ans;
}