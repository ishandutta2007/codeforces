#include<cstdio>
#include<cstring>

using namespace std;

int b[10][10]=
{
    1,0,0,0,0,0,0,0,1,0,
    1,1,0,1,1,0,0,1,1,1,
    0,0,1,0,0,0,0,0,1,0,
    0,0,0,1,0,0,0,0,1,1,
    0,0,0,0,1,0,0,0,1,1,
    0,0,0,0,0,1,1,0,1,1,
    0,0,0,0,0,0,1,0,1,0,
    1,0,0,1,0,0,0,1,1,1,
    0,0,0,0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,0,1,1
};
int len,ans,ans2,o;
char s[10];

int main()
{
    scanf("%s",s+1);
    len=strlen(s+1);
    if(len==1)
    {
        o=s[1]-'0';
        for(int i=0;i<10;i++)
            if(b[o][i])ans++;
        printf("%d",ans);
    }
    else
    {
        o=s[1]-'0';
        for(int i=0;i<10;i++)
            if(b[o][i])ans++;
        o=s[2]-'0';
        for(int i=0;i<10;i++)
            if(b[o][i])ans2++;
        printf("%d",ans*ans2);
    }
}