#include <cstdio>
using namespace std;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    if(n==1)puts("1");else{
        if(m-1>=n-m)printf("%d\n",m-1);else printf("%d\n",m+1);
    }
    return 0;
}