#include <iostream>
#include <algorithm>
using namespace std;
const int N=102;
int n; double p[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
    sort(p+1,p+1+n);
    double ans=p[n],A=1-p[n];
    for(int i=n-1;i>=1;i--){
        double nex = ans + p[i]*(A-ans);
        if(nex<ans)break;
        ans=nex, A=A*(1-p[i]);
    }
    printf("%.12f\n", ans);
}