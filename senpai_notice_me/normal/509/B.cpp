#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct PileInt
{
    int maxi,mini;
    PileInt()
    {
        maxi=-0x7fffffff;
        mini=0x7fffffff;
    }
}peb[101];
int n,k,pil[101];
bool noans;
void Refresh(int i,int p_i)
{
    peb[i].maxi=max(peb[i].maxi,p_i);
    peb[i].mini=min(peb[i].mini,p_i);
    if(peb[i].maxi-peb[i].mini>1)
        noans=true;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n && !noans;i++)
	{
	    scanf("%d",&pil[i]);
	    for(int j=1;j<=k && !noans;j++)
	    {
	        if(pil[i]<j)
	            Refresh(j,0);
	        else
	            Refresh(j,(pil[i]-j)/k+1);
        }
    }
    if(noans)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<pil[i];j++)
                printf("%d ",j%k+1);
            printf("\n");
        }
    }
	return 0;
}