#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=505;

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        int n,k;
        scanf("%d %d", &n, &k);
        for(int i=1; i<n; i++) {
            k-=i;
            if(k<=0) {
                k+=i;
                for(int j=0; j<n; j++) {
                    if(j==n-1-i || j==n-k) printf("b");
                    else printf("a");
                }
                puts("");
                break;
            }
        }
    }
}