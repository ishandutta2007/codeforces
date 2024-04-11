#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);

        int tot=0;
        for(int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            tot+=x;
        }

        printf("%d\n", min(tot, m));
    }
}