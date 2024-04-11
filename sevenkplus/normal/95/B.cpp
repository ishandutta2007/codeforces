#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
char s[N];int n;bool v[N];char a[N];int t=0;
void tle(){while(1);}
bool ff()
{
    for(int i=0;i<t/2;i++)
        if(a[i]<'7')return 1;
    for(int i=t/2;i<t;i++)
        if(a[i]>'4')return 0;
    return 1;
}
int main()
{
    scanf("%s",s);n=strlen(s);
    for(int i=n-1;i>=0;i--)
        if(s[i]>'7')v[i]=1;else
        if(s[i]<'7')v[i]=0;else
        if(v[i+1])v[i]=1;
    if(v[0]){for(int i=0;i<=n;i++)a[t++]='4';}else
    {
        bool F=0;
        for(int i=0;i<n;i++)
            if(F)a[t++]='4';else
            if(s[i]<'4'){a[t++]='4';F=1;}else
            if(s[i]=='4'){if(v[i+1])a[t++]='7',F=1;else a[t++]='4';}else
            if(s[i]<'7'){a[t++]='7';F=1;}else
            if(s[i]=='7'){if(v[i+1])tle();else a[t++]='7';}else tle();
    }
    if(t&1)
    {
        t++;
        for(int i=0;i<t/2;i++)a[i]='4';
        for(int i=t/2;i<t;i++)a[i]='7';
        printf("%s\n",a);
        return 0;
    }
    if(!ff())
    {
        t++;
        for(int i=0;i<t;i++)a[i]='4';
    }
    if(t&1)
    {
        t++;
        for(int i=0;i<t/2;i++)a[i]='4';
        for(int i=t/2;i<t;i++)a[i]='7';
        printf("%s\n",a);
        return 0;
    }
    int z=0;
    for(int i=0;i<t;i++)
        if(a[i]=='4')z++;else z--;
    if(z==0){printf("%s\n",a);return 0;}
    for(int i=t-1;i>=0;)
    {
        if(z==0)break;
        if(z>0){if(a[i]=='4')a[i]='7',z-=2;i--;}else
        if(z<0)
        {
            if(a[i]=='7')
            {
                int j=i;
                while(a[j]=='7')a[j]='4',z+=2,j--;
                a[j]='7',z-=2;
                if(z<0)i=j;
                if(z>0)i=t;
            }else i--;
        }
    }
    printf("%s\n",a);
    return 0;
}