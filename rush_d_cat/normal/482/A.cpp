#include <iostream>
using namespace std;
typedef long long LL;
int n,k;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<n-k;i++){
        printf("%d ", i);
    }
    int l=n-k,r=n;
    for(int i=1;i<=k+1;i++){
        if(i%2==1) {
            printf("%d ", l); l++;
        } else {
            printf("%d ", r); r--;
        }
    }
}