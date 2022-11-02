#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, ans;

int arr[200000];
int dp[200000];
int ddp[2000000];
int main()
{
    int i, j, k,n,m,a,b,c,d,e,f,g,x,y,t,temp=0,cnt=0;
    char z;
    scanf("%d",&n);
    scanf("%1c",&z);
   for(i=1;i<=n;i++)
   {
   	 scanf("%1c",&z);
   	 if(z=='G') 
	 {
		arr[i]=1;
		cnt++;
	 }
   }
   int comcnt=1;
   int notcomcnt=1;
   for(i=1;i<=n;i++)
   {
		if(arr[i]==1)
		{
			dp[comcnt]++;
		}
		else
		{
			comcnt++;
		}
   }
   int maxi=0;
   for(i=1;i<=comcnt;i++)
   {
   //	printf("%d\n",dp[i]);
   	 maxi=max(maxi,dp[i]+dp[i+1]+1);
   }
  
   if(maxi==0)
   {
   	printf("0\n");
   	return 0;
   }
   
   
   if(maxi>=cnt)
   {
   	printf("%d\n",cnt);
   	return 0;
   }
   
   printf("%d\n",maxi);
   
   	
    
}