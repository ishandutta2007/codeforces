#include<stdio.h>
#include<cstring>
using namespace std;
long have[27]={0};
char a[3000];long lena=0;
char b[3000];long lenb=0;
int main()
{
    scanf("%s",a+1);lena=strlen(a+1);
    scanf("%s",b+1);lenb=strlen(b+1);
    for(long i=1;i<=lena;i++)have[a[i]-'a'+1]++;
    for(long i=1;i<=lenb;i++)if(have[b[i]-'a'+1]==0){printf("-1");return 0;}
    long ans=0;
    for(long i=1;i<=lenb;i++)
    if(have[b[i]-'a'+1])
    {
                        ans++;
                        have[b[i]-'a'+1]--;
                        }
    if(ans>0)
    printf("%ld\n",ans);
    else printf("-1");
    //for(;;);
    return 0;
}