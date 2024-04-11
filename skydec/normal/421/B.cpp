#include<stdio.h>
#include<cstring>
using namespace std;
bool chars[200]={false};
char p[100005];
long len;
int main()
{
    chars['A']=1;
    chars['H']=1;
    chars['I']=1;
    chars['M']=1;
    chars['O']=1;
    chars['T']=1;
    chars['U']=1;
    chars['V']=1;
    chars['W']=1;
    chars['X']=1;
    chars['Y']=1;
    scanf("%s",p+1);len=strlen(p+1);
    for(long i=1;i<=len;i++)if((!chars[p[i]])||p[i]!=p[len+1-i]){printf("NO\n");return 0;}
    printf("YES\n");
    return 0;
}