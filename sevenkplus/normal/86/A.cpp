#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int a[9]={4,49,499,4999,49999,499999,4999999,49999999,499999999};
int l,r;ll S=0;
void chk(int x)
{
    ll p=1;
    while(x>=p)p*=10;
    S=max(S,x*(p-x-1));
}
int main()
{
    scanf("%d%d",&l,&r);
    for(int i=0;i<9;i++)if(l<=a[i]&&a[i]<=r)chk(a[i]);
    chk(l);chk(r);
    printf("%I64d\n",S);
    return 0;
}