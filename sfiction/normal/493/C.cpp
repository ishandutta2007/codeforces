/*
ID: Sfiction
OJ: CF
PROB: 493C
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=200000+100;

int n,a[MAXN];
int m,b[MAXN];

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
    scanf("%d",&m);
    for (int i=0;i<m;++i)
        scanf("%d",&b[i]);
    sort(b,b+m);

    int s1=2*n,s2=2*m;
    int max=s1-s2,ansa=s1,ansb=s2;
    for (int j=m-1,i=n-1;i>=0;--i){
        ++s1;
        for (;j>=0 && b[j]>=a[i];--j)
            ++s2;
        if (max<=s1-s2){
            max=s1-s2;
            ansa=s1;
            ansb=s2;
        }
    }
    printf("%d:%d",ansa,ansb);
    return 0;
}