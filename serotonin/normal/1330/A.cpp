#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 305;

bitset <sz> a;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        for(int i=0; i<n; i++) {
            int y;
            scanf("%d", &y);
            a[y] = 1;
        }

        int ans = 0;
        for(int i=1; ; i++) {
            if(!a[i]) {
                if(x) x--;
                else break;
            }
            ans = i;
        }

        a.reset();
        printf("%d\n", ans);
    }
}