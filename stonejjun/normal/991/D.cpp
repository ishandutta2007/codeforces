#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
	int i,j,k,ans=0,cnt[2000]={};
   char line1[100000],line2[100000],real[100000];
   scanf("%s",line1);
   scanf("%s",line2);
   for(i=0;line1[i];i++)
   {
 		if(line1[i]=='0')
 		{
 			cnt[i]++;
		}
		if(line2[i]=='0')
 		{
 			cnt[i]++;
		}
   }
   
   for(i=0;line1[i+1];i++)
   {
 		if(cnt[i]==1&&cnt[i+1]==2)
 		{
 			ans++;
 			cnt[i]=0;
 			cnt[i+1]=0;
		}
		if(cnt[i]==2&&cnt[i+1]==2)
 		{
 			ans++;
 			cnt[i]=0;
 			cnt[i+1]=1;
		}
 		if(cnt[i]==2&&cnt[i+1]==1)
 		{
 			ans++;
 			cnt[i]=0;
 			cnt[i+1]=0;
		}
   }
   printf("%d",ans);
   
}