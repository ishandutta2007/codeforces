/*
ID: Sfiction
OJ: CF
PROB: 442B
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=100+5;
const double EPS=1E-10;

int n;
double p[MAXN];
double ans;

void Init(){
    int i;
    scanf("%d",&n);
    for (i=1;i<=n;++i)
        scanf("%lf",&p[i]);
}
double Work(){
    int i;
    double prod,sum;
    prod=1;
    sum=0;
    sort(p+1,p+n+1);
    if (-EPS<1-p[n]&&1-p[n]<EPS)
        return 1;
    for (i=n;i>0&&sum<1;--i){
        sum+=p[i]/(1-p[i]);
        prod*=1-p[i];
    }
    return sum*prod;
}
int main(){
    Init();
    printf("%.12lf",Work());
    return 0;
}