#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e3+5;

typedef pair <int,int> pii;
#define x first
#define y second

pii a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d %d", &a[i].x, &a[i].y);

        bool ok = a[0].x >= a[0].y;
        for(int i=1; i<n; i++) {
            int x = a[i].x - a[i-1].x;
            int y = a[i].y - a[i-1].y;
            if(x < 0 || y < 0 || x < y) ok = 0;
        }

        if(ok) puts("YES");
        else puts("NO");
    }
}