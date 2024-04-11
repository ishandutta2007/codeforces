#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<deque>
#define LL long long int
#define MOD 1000000007
char arm[200];
int arr[100];
using namespace std;

void swap(int p,char *arm)
{
	char temp;
	int x=0,y=p-1;
	while(y>x)
	{
		temp=arm[x];
		arm[x]=arm[y];
		arm[y]=temp;
		x++;
		y--;
		
	}
}

int main()
{
    int i,j=1,k=1,n,m,a,b,c,ans=0,arr[100]={};
    char arm[200];
    scanf("%d",&n);
    getchar();
    scanf("%s",arm);
    for(;k<=n;j++)
    {
    	while(1)
    	{
    		if(n%k==0)
    		{
    			
    			arr[j]=n/k;
    			k++;
    			break;
			}
			k++;
		}
	
	}
	for(k=1;j-1>=1;j--)
	{
		swap(arr[j-1],arm);
	}
	
	printf("%s",arm);
}