#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;

int a[105], b[105];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) scanf("%d", &b[i]);
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0; i<n; i++) printf("%d ", a[i]);
        puts("");
        for(int i=0; i<n; i++) printf("%d ", b[i]);
        puts("");
    }
}