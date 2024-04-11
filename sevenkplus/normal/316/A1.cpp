#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
char s[N];int n,p0=0,sa=0;bool c[10];
int main()
{
    scanf("%s",s);n=strlen(s);
    for(int i=1;i<n;i++)if(s[i]=='?')p0++;
    for(int i=0;i<n;i++)if('A'<=s[i]&&s[i]<='J')c[s[i]-'A']=1;
    for(int i=0;i<10;i++)if(c[i])sa++;
    int S=1;
    if(s[0]=='?')S*=9;
    if('A'<=s[0]&&s[0]<='J')
    {
        S*=9;
        for(int i=1;i<sa;i++)S*=(10-i);
    }else
    {
        for(int i=0;i<sa;i++)S*=(10-i);
    }
    printf("%d",S);
    for(int i=0;i<p0;i++)printf("0");puts("");
    return 0;
}