#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using  pii = pair<int, int>;

const int N = 2e5 + 13;



int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    li ans = 0;
    int lst = -1;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] - a[i + 1] <= 1) {
            if(lst == -1) {
                lst = a[i + 1];
                i++;
            } else {
                ans += lst * 1ll * a[i + 1];
                lst = -1;
                i++;
            }
        }
    }

    cout << ans << endl;
}