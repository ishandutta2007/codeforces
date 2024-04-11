#include<stdio.h>
#include<cstring>
using namespace std;
bool have[255]={false};
char str[150];
int ans=0;
int main()
{
    scanf("%s",str+1);
    for(int i=1;i<=strlen(str+1);i++)
    if(!have[str[i]])
    {
                     ans++;
                     have[str[i]]=true;
                     }
    if(ans&1)printf("IGNORE HIM!\n");
    else printf("CHAT WITH HER!\n");
    return 0;
}