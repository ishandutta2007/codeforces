#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=100000+10;

int n,nn,a[3],b[3];
int main(){
    scanf("%d",&n);nn=n;
    for(int i=0;i<3;i++) scanf("%d%d",&a[i],&b[i]);
    int c1=min(n-(a[1]+a[2]),b[0]); 
    n -= c1;
    int c2=min(n-a[2],b[1]);
    printf("%d %d %d\n", c1,c2,nn-c1-c2);
}