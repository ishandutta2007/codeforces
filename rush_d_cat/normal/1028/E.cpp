#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 500000+10;
int n;
LL a[N], b[N], bb[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld", &bb[i]);
    for(int i=1;i<=n;i++) bb[i+n]=bb[i];
    int pos = 0;   
    for(int i=1;i<=n;i++) {
        if(bb[i]>bb[i+n-1]){
            for(int j=i;j<i+n;j++) b[j-i+1] = bb[j];
            pos = i; break;
        }
    }
    if(*max_element(bb+1,bb+1+n)==0) {
        printf("YES\n");
        for(int i=1;i<=n;i++) printf("%d ", 1); return 0;
    }
    if (!pos) return !printf("NO\n");

    a[1]=a[n+1]=b[1]; // b[1] > b[n]
    for(int i=n;i>=2;i--) {
        LL x = (b[i-1]-b[i])/a[i+1] + 1;
        if (b[i-1]<b[i]) x=0;
        if (b[i]==0 && x==0) x = 1;
        a[i] = a[i+1]*x + b[i];
    }
    printf("YES\n");
    for(int i=n-pos+2;i<=n;i++) {
        printf("%lld ", a[i]);
    }
    for(int i=1;i<n-pos+2;i++) {
        printf("%lld ", a[i]);
    }
    
}