#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

int a[105];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        int bag=m,yes=1;
        for(int i=0; i<n-1; i++) {
            if(a[i]+k>=a[i+1]) bag+=min(a[i], a[i]+k-a[i+1]);
            else bag-=a[i+1]-k-a[i];
            if(bag<0) yes=0;
        }
        if(yes) puts("YES");
        else puts("NO");
    }
}