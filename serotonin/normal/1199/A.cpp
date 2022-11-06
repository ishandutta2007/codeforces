#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[sz];

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) {
        bool yes=1;
        for(int j=max(i-x,0); j<=min(n-1,i+y); j++) {
            if(j==i) continue;
            if(a[j]<=a[i]) yes=0;
        }
        if(yes) {
            printf("%d\n", i+1);
            return 0;
        }
    }
}