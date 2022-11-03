/*
ID: Sfiction
OJ: CF
PROB: 492B
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=10000+10;

int n,l;
int a[MAXN];

int main(){
    scanf("%d%d",&n,&l);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=max(a[0],l-a[n-1])*2;
    for (int i=1;i<n;++i)
        ans=max(ans,a[i]-a[i-1]);
    printf("%.6lf",ans/2.0);
    return 0;
}