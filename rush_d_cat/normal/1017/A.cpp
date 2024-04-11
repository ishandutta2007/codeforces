#include <iostream>
using namespace std;
const int N=1002;
int n,a[N][4],sum[N],ans;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++) {
            scanf("%d",&a[i][j]);
            sum[i]+=a[i][j];
        }
        if(sum[i]>sum[1])ans++;
    }
    printf("%d\n", ans+1);
}