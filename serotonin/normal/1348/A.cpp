#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 1 << n;
        for(int i=1; i<n; i++) {
            if(i < n/2) ans += 1 << i;
            else ans -= 1 << i;
        }
        printf("%d\n", ans);
    }
}