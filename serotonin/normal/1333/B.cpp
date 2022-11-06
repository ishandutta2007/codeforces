#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], b[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) scanf("%d", &b[i]);
        bool pos = 0, neg = 0, ok = 1;
        for(int i=0; i<n; i++) {
            if(a[i]!=b[i]) {
                if(b[i]>a[i] && !pos) ok = 0;
                if(b[i]<a[i] && !neg) ok = 0;
            }
            if(a[i]>0) pos = 1;
            if(a[i]<0) neg = 1;
        }
        if(ok) puts("YES");
        else puts("NO");
    }
}