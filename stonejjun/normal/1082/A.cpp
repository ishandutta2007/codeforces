#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, ans;
int main()
{
    int i, j, k,n,m,a,b,c,d,e,f,g,x,y,t,temp=0;
    scanf("%d",&t);
    while(t--)
    {
    	int mini=1000000000;
	   	scanf("%d %d %d %d",&n,&x,&y,&d );
	   	if( abs(y-x)%d==0 )
	   	{
	   		printf("%d\n",abs(y-x)/d);
	   		continue;
		}
	   	if( abs(y-1)%d==0 )
	   	{
	   		mini=min(mini, (abs(y-1)/d)+( abs(x-1)/d )+1 );	
		}
		if( abs( n-y )%d==0 )
	   	{
	   		mini=min(mini, ( abs(n-y)/d)+( abs(n-x)/d )+1 );	
		}
		
		if(mini==1000000000)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",mini);
		}
   	
   	}
   	
    
}