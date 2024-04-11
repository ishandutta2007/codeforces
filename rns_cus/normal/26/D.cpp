#include<stdio.h>
#include<algorithm>
using namespace std;
double calc(int a, int b, int c, int d){
    double ret = 1.;
    int cc = c;
    for(int i = a; i <= b; i ++) {
        ret *= 1. * i / cc ;
        cc ++;
    }
    return ret;
}
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(m < k + 1) {puts("1.0000");return 0;}
    double ans = calc(m - k, m,n + 1, k+n+1);
    ans  = min(1., ans);
    printf("%.6lf\n", 1. - ans);
}