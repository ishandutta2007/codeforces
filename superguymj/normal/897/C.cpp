#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cctype>
#include<cmath>
#define rep(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int A=75,B=34,C=32;
const char a[]=" What are you doing at the end of the world? Are you busy? Will you save us?";
const char b[]=" What are you doing while sending \"";
const char c[]=" \"? Are you busy? Will you send \"";
int T,n;
LL lng[60],k;

char calc(int n,LL k)
{
    if(k<=B*n)
        return b[(k-1)%B+1];
    if(n>53)
        return calc(53,k-B*(n-53));
    if(k>lng[n])
        return '.';
    if(!n)
        return a[k];
    if ((k-=B)<=lng[n-1])
        return calc(n-1,k);
    if((k-=lng[n-1])<=C)
        return c[k];
    if((k-=C)<=lng[n-1])
        return calc(n-1,k);
    return (k-=lng[n-1]+1)? '?':'\"';
}

int main()
{
    lng[0]=75;
    rep(i,1,53) lng[i]=lng[i-1]*2+B+C+2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%I64d",&n,&k);
        putchar(calc(n,k));
    }
    return 0;
}