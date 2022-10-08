#include<cstdio>
typedef long long ll;
ll ff(ll a){return (a%2)*a-a%2+(a%4)/2;}
int main()
{
    int n;
    ll x,m,s=0;
    for(scanf("%d",&n);n--;)
    {
        scanf("%I64d%I64d",&x,&m);
        s^=ff(x)^ff(x+m);
    }
    puts(s?"tolik":"bolik");
    return 0;
}