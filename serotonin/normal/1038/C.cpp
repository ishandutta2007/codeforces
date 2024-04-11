#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
main()
{
    long long n,i,j;
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    i=n-1,j=n-1;
    long long x=0,y=0;
    for(int f=0;f<2*n;f++) {
        if(f%2) {
            if(i<0) {
                y+=b[j];
                j--;
            }
            else if(j>=0) {
                if(a[i]<b[j]) {
                    y+=b[j];
                    j--;
                }
                else i--;
            }
            else i--;
        }
        else {
            if(j<0) {
                x+=a[i];
                i--;
            }
            else if(i>=0) {
                if(a[i]>b[j]) {
                    x+=a[i];
                    i--;
                }
                else j--;
            }
            else j--;
        }
    }
    printf("%I64d\n", x-y);
}