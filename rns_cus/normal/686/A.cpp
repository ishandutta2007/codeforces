#include<cstdio>
long long b;
char s[5];
main(){int n,a=0,x;scanf("%d%I64d",&n,&b);while(n--){scanf("%s%d",s,&x);if(s[0]=='+')b+=x;else if(b>=x)b-=x;else a++;}printf("%I64d %d\n",b,a);}