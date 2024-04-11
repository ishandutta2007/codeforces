#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100 + 10;
int a[N],n,ans;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    a[0]=0,a[n+1]=1001;
    for(int i=0;i<=n;i++) {
        int r=-1;
        for(int j=i+1;j<=n+1;j++){
            if(j-i==a[j]-a[i])r=j;
        }
        //printf("[%d,%d]\n", i,r);
        if(r!=-1){
            ans=max(r-i-1,ans);i=r;
        }
    }
    printf("%d\n",ans);
}