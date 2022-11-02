#include<cstdio>
#include<algorithm>

using namespace std;

int n,m;

int gcd(int a,int b)
{
    if(!b)return a;
    return a%b?gcd(b,a%b):b;
}

int main()
{
    scanf("%d%d",&n,&m);
    if(n>m)swap(n,m);
    printf("%d",gcd(n-1,m-1)+1);
}