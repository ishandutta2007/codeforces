#include<cstdio>
typedef long long ll;
int main()
{
    ll A,B;
    scanf("%I64d%I64d",&A,&B);
    ll C=(A-B)/2;
    ll X=C,Y=A-X;
    if(Y>=0&&((X^Y)==B)&&((X&Y)==C))printf("%I64d %I64d\n",X,Y);else puts("-1");
    return 0;
}