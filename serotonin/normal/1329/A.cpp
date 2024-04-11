#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz], ans[sz];

int main()
{
    int n, m;
    ll tot = 0;
    bool no = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        scanf("%d", &a[i]), tot += a[i];
        if(n-i < a[i]) no = 1;
    }

    if(tot < n || no) puts("-1");
    else {
        for(int i=m-1, j=n+1; i>=0; i--) {
            ans[i] = j = max(i+1, j-a[i]);
        }
        for(int i=0; i<m; i++) printf("%d ", ans[i]);
        puts("");
    }
}