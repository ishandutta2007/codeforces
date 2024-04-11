#include<cstdio>
#include<cstdlib>

using namespace std;

int n;
char s[7];

void work(char now[7])
{
    int o=0;
    for(int i=0;i<7;i++)
        if(now[i]==s[i]||s[i]=='.')o++;
    if(o==7)
    {
        puts(now);
        exit(0);
    }
}

int main()
{
    scanf("%d",&n);
    if(n==8)return puts("vaporeon"),0;
    if(n==6)return puts("espeon"),0;
    scanf("%s",s);
    work("jolteon");
    work("flareon");
    work("umbreon");
    work("leafeon");
    work("glaceon");
    work("sylveon");
}