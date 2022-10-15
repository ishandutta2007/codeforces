#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int n;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&n);
    int x=(n+1)/2-1,y=n-x;
    while(x>0&&gcd(x,y)!=1)
    {
        x--;
        y++;
    }
    printf("%d %d\n",x,y);
    return 0;
}