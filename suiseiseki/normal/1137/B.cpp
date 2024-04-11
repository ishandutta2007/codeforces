#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[500005],t[500005],res[500005];
int nxt[500005];
void getnext()
{
 nxt[1]=0;
 int len=strlen(t+1);
 for(int i=2,j=0;i<=len;i++)
 {
  while(j&&t[i]!=t[j+1])
   j=nxt[j];
  if(t[i]==t[j+1])j++;
  nxt[i]=j;
 }
}
int main()
{
 scanf("%s",s+1);
 scanf("%s",t+1);
 getnext();
 int cnt1=0,cnt0=0,lens=strlen(s+1),lent=strlen(t+1);
 for(int i=1;i<=lens;i++)
  if(s[i]=='0')cnt0++;
  else cnt1++;
 for(int i=1,j=1;i<=lens;i++,j++)
 {
  if(t[j]=='0'&&(!cnt0))res[i]='1',cnt1--;
  else if(t[j]=='1'&&(!cnt1))res[i]='0',cnt0--;
  else
  {
   res[i]=t[j];
   if(t[j]=='0')cnt0--;
   else cnt1--;
  }
  if(j==lent)j=nxt[j];
 }
 printf("%s\n",res+1);
 return 0;
}