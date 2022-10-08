#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[222];int n;
int main()
{
    scanf("%s",s);n=strlen(s);
    if(s[0]=='@'||s[n-1]=='@'){puts("No solution");return 0;}
    for(int i=0;i<n-1;i++)if(s[i]=='@'&&s[i+1]=='@'){puts("No solution");return 0;}
    for(int i=0;i<n-2;i++)if(s[i]=='@'&&s[i+2]=='@'){puts("No solution");return 0;}
    bool F=1;
    for(int i=0;i<n;i++)if(s[i]=='@')F=0;
    if(F){puts("No solution");return 0;}
    F=1;
    for(int i=0;i<n;i++)
    {
        putchar(s[i]);
        if(F){if(s[i]=='@')F=0;continue;}
        if(s[i+2]=='@')putchar(',');
    }
    puts("");
    return 0;
}