#include <cstdio>
using namespace std;
char s[255];
int i,ans;
int main()
{
    scanf("%s",s);
    ans=0;
    for (i=0;s[i];i++)
        ans+=(s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')||(('0'<=s[i])&&(s[i]<='9')&&(s[i]%2==1));
    printf("%d\n",ans);
    return 0;
}