#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
char str[MAXN];
LL ans1=0;LL ans2=0;
int main()
{
    scanf("%s",str+1);
    int len=strlen(str+1);
    int odda,evena;
    odda=0;evena=0;
    int oddb=0;int evenb=0;
    for(int i=1;i<=len;i++)
    if(i&1)
    {
           if(str[i]=='a')
           {
                          odda++;
                          ans1+=odda*1ll;
                          ans2+=evena*1ll;
                          }
           else
           {
                          oddb++;
                          ans1+=oddb*1ll;
                          ans2+=evenb*1ll;
                          }
                          }
    else
    {
        if(str[i]=='a')
           {
                          evena++;
                          ans1+=evena*1ll;
                          ans2+=odda*1ll;
                          }
           else
           {
                          evenb++;
                          ans1+=evenb*1ll;
                          ans2+=oddb*1ll;
                          }
                          }
    printf("%I64d %I64d\n",ans2,ans1);
    return 0;
}