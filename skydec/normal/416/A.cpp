#include<stdio.h>
#include<cstring>
using namespace std;
long n;long down;long up;
int main()
{
    scanf("%ld",&n);up=2000000000;down=-2000000000;
    for(long i=1;i<=n;i++)
    {
             char f[5];char q[5];long key;char flag[5];
             scanf("%s",q+1);
             scanf("%ld",&key);
             scanf("%s",flag+1);int len1=2;
             if(flag[1]=='N')
             {
                         if(q[1]=='<')
                         {
                                      if(strlen(q+1)==2)
                                      {
                                                        f[1]='>';
                                                        len1=2;
                                                        }
                                      else {f[1]='>';f[2]='=';len1=3;}
                                                        }
             else                                     
                         {
                                       if(strlen(q+1)==2)
                                      {
                                                        f[1]='<';
                                                        len1=2;
                                                        }
                                      else {f[1]='<';f[2]='=';len1=3;}
                                                        }
                                                        }
             else {len1=strlen(q+1)+1;for(long s=1;s<=strlen(q+1);s++)f[s]=q[s];}
                                            
             if(f[1]=='<')
             {
                          if(len1==3)
                          {
                                            if(up>key)up=key;
                                            }
                          else if(up>=key)up=key-1;
                          }
             else
             {
                          if(len1==3)
                          {
                                            if(down<key)down=key;
                                            }
                          else if(down<=key)down=key+1;
                          }
    }
    if(down>up)printf("Impossible\n");else printf("%ld\n",down);
    return 0;
}