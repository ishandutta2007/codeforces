#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n,a[N];

bool cac() {
    LL sum=0;
    for(int i=1;i<=n;i++){
        sum += a[i]-(i-1);
    }
    return sum%2;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    if(n==1) {
        return !printf("%s\n", a[1]%2==1?"sjfnb":"cslnb");
    }
    int c=0;for(int i=1;i<n;i++)if(a[i]==a[i+1])c++;
    if(c>=2) return !printf("cslnb\n");
    if(c==1){
        for(int i=1;i<n;i++){
            if(a[i]==a[i+1]){
                if(a[i]==0) return !printf("cslnb\n");
                if(i>=2 && a[i-1]==a[i]-1) return !printf("cslnb\n");
                a[i]--; break;
            }
        }
        return !printf("%s\n", cac()?"cslnb":"sjfnb");
    }
    return !printf("%s\n", cac()?"sjfnb":"cslnb");
}