#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=5e5+5;

pair <int,int> a[sz];
int ans[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,x,y,i;
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%d %d", &x, &y);
            a[2*i].first=x;
            a[2*i].second=0-(1+i);
            a[2*i+1].first=y;
            a[2*i+1].second=1+i;
        }
        sort(a,a+2*n);
        x=0;
        for(i=0; i<2*n; i++) {
            if(a[i].second<0) x++;
            else x--;
            if(a[i].second>0) ans[a[i].second]=1;
            if(!x && i<2*n-1) break;
        }
        if(i<2*n) {
            for(i=1; i<=n; i++) {
                if(ans[i]) printf("1");
                else printf("2");
                if(i<n) printf(" ");
                ans[i]=0;
            }
            puts("");
        }
        else {
            puts("-1");
            for(i=0; i<=n; i++) ans[i]=0;
        }
    }
}