#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

int a[sz];

int main()
{
    int ans=0,ans2=0,i,n;
    cin >> n;
    for(i=0; i<n; i++) {
        cin >> a[i];
        ans=max(ans,a[i]);
    }
    for(i=1; i<=ans; i++) {
        if(ans%i==0) {
            for(int j=0; j<n; j++) {
                if(a[j]==i) {
                    a[j]=0;
                    break;
                }
            }
        }
    }
    for(i=0; i<n; i++) {
        ans2=max(ans2,a[i]);
    }
    printf("%d %d\n", ans, ans2);
}