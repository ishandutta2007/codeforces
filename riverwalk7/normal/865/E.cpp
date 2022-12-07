#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<time.h>
clock_t start,finish;
using namespace std; 
const long long inf=1e18;
long long ex[15];
int low[15],high[15];
int num_state;
char str[16];
int len,stk[15][15],cnt_stk[15],sum[15],bs[15];
int ve[1<<14],vis[15],times,list[1<<14],cnt_list,f[1<<14],oe[1<<14],bn[15];
long long dp[1<<14][16],ans;
long long gs[1<<14],g[1<<14];
int fir[1<<14],gm[1<<14],ls[15],cnt_ls,adj[16];
int ss[12345678];
long long cg[16];
int change(char ch)
{
	if(ch<='9'&&ch>='0')
	   return ch-'0';
    return ch-'a'+10;
}
int main()
{
	int i,j,s,p,q;
    start=clock();
	for(i=0;i<=14;i++)
	{
		if(i==0)
		   ex[i]=1;
        else
           ex[i]=ex[i-1]*16;
	}
	scanf("%s",str); 
	len=strlen(str);
//	len=14;
	//num_state=0;
	//int i,j,s,p,q;
	memset(cnt_stk,0,sizeof(cnt_stk));
	int nc=0,tot=0;
	for(i=0;i<len;i++)
	   oe[1<<i]=i;
	 for(int i=0; i<12345678; i++)
	 {
	     ss[i]++;
	 }
    ans=inf;
    for(i=(1<<len)-1;i>=0;i--)
    {
    	if(i&1)
    	    continue;
	    int sum=0;
	    for(j=0;j<len;j++)
	       bs[j]=change(str[j]);
	    for(j=len-1;j>=0;j--)
	    {
    		if((!(i&(1<<j))))
    		{
		    	low[j]=0;
		    	high[j]=15-bs[j];
		    }
		    else
		    {
		    	bs[j-1]++;
    			low[j]=16-bs[j];
    			high[j]=15;
    		}
    		sum=(sum+bs[j])%16;
    	}
    	bool ok=(sum==0);
    	if(ok)
    	{
	    	for(j=0;j<len;j++)
	    	{
	    		if(low[j]>high[j])
	    		   ok=false;
	    	}
	    }
		if(ok)
    	{
    		if(ans<inf)
    		{
    		    for(j=0;j<len;j++)
    	    	{
		        	if(low[j]!=(ans/ex[len-1-j])%16)
		        	    break;
		        }
		        if(j>=len||low[j]>(ans/ex[len-1-j])%16)
		           continue;
    		}
 	         cnt_list=0;
 	         for(j=0;j<(1<<len);j++)
 	         {
 	         	   if(j)
 	         	   {
					    f[j]=(f[j^(j&(-j))]+bs[oe[j&-j]])%16;
 	         	        if(f[j]==0)
 	         	           list[cnt_list++]=j;
    			   }
         	 }
         	 for(j=0;j<cnt_list;j++)
         	 {
 	         	for(s=j+1;s<cnt_list;s++)
 	         	{
	         	     if((list[j]&list[s])==list[j])
					      break;	
         	    }
         	    if(s<cnt_list)
         	    {
    	         	for(s=j+1;s<cnt_list;s++)
    	         	   list[s-1]=list[s];
 	         	    cnt_list--;
    	        }
 	         }
 	         times++;
 	         for(s=0;s<cnt_list;s++)
 	            ve[list[s]]=times;
         	 for(j=0;j<(1<<len);j++)
         	 {
			      g[j]=inf;
         	      for(s=0;s<16;s++)
         	         dp[j][s]=inf;
			  }
			 for(j=0;j<len;j++)
		     { 
		          for(s=low[j];s<=high[j];s++)
		          	   dp[1<<j][(s+bs[j])%16]=s*ex[len-1-j];
			 }
			 //if(i==6)
			// {
 		//		for(j=0;j<len;j++)
 	//			   printf("low=%d,high=%d,j=%d\n",low[j],high[j],j);
 	//		}
 	         for(j=0;j<16;j++)
 	         {
 	         	adj[j]=0;
         	 	for(s=0;s<len;s++)
         	 	{
	 	         	if(j>=low[s]&&j<=high[s])
	 	         	   adj[j]|=(1<<s);
	 	         }
         	 }
			 for(j=0;j<(1<<len);j++)
		     {
		     	  for(s=0;s<16;s++)
		     	  {
  	     			  if(dp[j][s]>=ans)
						continue;
				      int state=((1<<len)-1-j)&adj[s];
				   //  if(i==6)
				    //    printf("dp[%d][%d]=%lld\n",j,s,dp[j][s]);
				      for(;state>0;state-=(state&-state))//for(p=0;p<cnt_ls;p++)
				      {
      					   q=oe[state&-state];
							 dp[j|(1<<q)][(s+bs[q])%16]=min(dp[j|(1<<q)][(s+bs[q])%16],dp[j][s]+s*ex[len-1-q]);
      				     //   if(j==8&&s==15&&q==2)
      				        //    printf("orz=%lld\n",dp[j|(1<<q)][(s+bs[q])%16]);
						}
  	     		  }
     		 }
     		 for(j=0;j<(1<<len);j++)
     		 {
     		 	gs[j]=inf;
 		     	for(s=0;s<16;s++)
 		     	{
	     		 	if(gs[j]>dp[j][s])
	     		 	   gs[j]=dp[j][s];
	     		 }
 		     }
     		 g[0]=0;
     		 for(j=0;j<(1<<len);j++)
     		 {
     		 	  if(g[j]==inf)
     		 	      continue;
 		     	   int state=(1<<len)-1-j;
 		     	   for(s=state;;s=(s-1)&state)
 		     	   {
   	     		 	     if(ve[s]==times)
   	     		 	     {
     	 		     	     g[j|s]=min(g[j|s],g[j]+gs[s]);  	
 		     	         }
 		     	         if(s==0)
 		     	            break;
   	     		   }
 		     }
 		     if(ans>g[(1<<len)-1])
 		        ans=g[(1<<len)-1];
             tot++;
		}
        //printf("ans=%lld\n",ans);
    } 
    if(ans<inf)
    {
       for(i=0;i<len;i++)
       {
        	int vl=(ans/ex[len-1-i])%16;
        	if(vl<10)
        	   printf("%d",vl);
 	        else
 	          putchar(vl-10+'a');
        }
        printf("\n");
    }
    else
       puts("NO");
   // printf("tot=%d\n",tot);
    //printf("times=%d\n",times);
	return 0;
}