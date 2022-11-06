#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int a[sz];

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        vector <int> ara;
        for(int i=0; i<n; i++) {
            if(a[i]<0) {
                if(i && a[i-1]>=0) ara.push_back(a[i-1]);
                if(i<n-1 && a[i+1]>=0) ara.push_back(a[i+1]);
            }
        }

        sort(ara.begin(), ara.end());

        int ans=0;
        if(ara.size()) ans=(ara[0]+ara.back())>>1;

        int big=0;
        for(int i=0; i<n; i++) if(a[i]<0) a[i]=ans;
        for(int i=1; i<n; i++) big=max(big, abs(a[i]-a[i-1]));

        printf("%d %d\n", big, ans);
    }
}