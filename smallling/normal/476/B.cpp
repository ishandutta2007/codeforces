#include<cstdio>
#include<cstring>

using namespace std;

int l,now,k,ans,o,a[100],b[100],p;
char s1[100],s2[100];

void dfs(int x)
{
    if(x>o)
    {
        if(k==now)ans++;
        p++;
        return;
    }
    for(int i=x;i<=o;i++)
    if(!b[i])
    {
        k++;
        b[i]=1;
        dfs(x+1);
        k--;
        b[i]=0;
        k--;
        b[i]=1;
        dfs(x+1);
        k++;
        b[i]=0;
    }
}

int main()
{
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    l=strlen(s1+1);
    for(int i=1;i<=l;i++)
        if(s1[i]=='+')now++;
        else now--;
    for(int i=1;i<=l;i++)
        if(s2[i]=='?')a[++o]=i;

    for(int i=1;i<=l;i++)
        if(s2[i]=='+')k++;
        else if(s2[i]=='-')k--;
    dfs(1);
    printf("%.9lf",1.0*ans/p);
}