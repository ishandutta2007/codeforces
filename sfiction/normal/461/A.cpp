/*
ID: Sfiction
OJ: CF
PROB: 461A
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=300000+10;

int n;
int num[MAXN];

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&num[i]);
    sort(num,num+n);

    long long ans=0;
    for (int i=n-2;i>=0;--i)
        ans+=num[i]*(long long)(i+2);
    ans+=num[n-1]*(long long)n;
    printf("%I64d",ans);
    return 0;
}