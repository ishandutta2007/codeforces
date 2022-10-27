#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
int n,w,a[N];
int main(){
    scanf("%d%d",&n,&w);
    for(int i=1;i<=2*n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+2*n);
    double ans=min((double)a[1],a[n+1]/2.0);

    ans=ans*n + 2*ans*n;
    if(ans<w)
    printf("%.2f\n", ans);
    else
    printf("%d\n", w);
}