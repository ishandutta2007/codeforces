#include<stdio.h>
#include<cstring>
using namespace std;
char str[110000];
int n;int len;
int now=0;
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    len=strlen(str+1);
    now=len;
    for(int i=1;i<n;i++)
    {
            scanf("%s",str+now+1);
            now+=len;
            }
    for(int i=1;i<=len;i++)
    {
            int cc=0;
            for(int j=0;j<n;j++)
            if(str[j*len+i]!='?')
            {
              if(cc==0)cc=str[j*len+i];
              else
              {
                  if(cc!=str[j*len+i])
                  {
                                      cc='?';
                                      break;
                                      }
                                      }
                                      }
              if(cc==0)cc='a';
            putchar(cc);
            }
    return 0;
}