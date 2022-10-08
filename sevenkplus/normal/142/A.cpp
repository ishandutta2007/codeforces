#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000LL
ll MA=-INF,MI=INF;
void add(int x,int y,int z)
{
    ll S=(ll)(x+1)*(y+2)*(z+2)-(ll)x*y*z;
    MA=max(MA,S),MI=min(MI,S);
}
void ff(int x,int n)
{
    add(x,1,n);
    int p=(int)((double)sqrt(n+0.0)+0.1);
    if(p*p>n)p--;
    for(int i=p;i>=1;i--)
        if(n%i==0){add(x,i,n/i);break;}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i*i<=n;i++)if(n%i==0)ff(i,n/i),ff(n/i,i);
    cout<<MI<<" "<<MA<<endl;
    return 0;
}