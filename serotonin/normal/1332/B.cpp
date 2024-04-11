#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int p[] = {2,3,5,7,11,13,17,19,23,29,31};

int a[sz], vis[15];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) {
            for(int j=0; j<11; j++) {
                if(a[i]%p[j]==0) {
                    vis[j] = 1;
                    break;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<15; i++) {
            if(vis[i]) vis[i]=++cnt;
        }

        printf("%d\n", cnt);
        for(int i=0; i<n; i++) {
            for(int j=0; j<11; j++) {
                if(a[i]%p[j]==0) {
                    printf("%d ", vis[j]);
                    break;
                }
            }
        }
        puts("");
        memset(vis, 0, sizeof vis);
    }
}