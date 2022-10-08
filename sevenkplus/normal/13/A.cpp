#include<cstdio>
int g(int a,int b){return b?g(b,a%b):a;}
int cc(int a,int b)
{
    int r=0;
    for(;a;r+=a%b,a/=b);
    return r;
}
int main()
{
    int a,S=0,T=0;
    scanf("%d",&a);
    for(int i=2;i<a;S+=cc(a,i),T++,i++);
    printf("%d/%d\n",S/g(S,T),T/g(S,T));
    return 0;
}