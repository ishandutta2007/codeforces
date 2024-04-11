#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;

int a[10001],i,j,ans;
char ch;

int main()
{
	ch=getchar();
	while(ch!=-1)a[ch]++,ch=getchar();
	ans=INT_MAX;
	ans=min(ans,(a['n']-1)/2);
	ans=min(ans,a['i']);
	ans=min(ans,a['e']/3);
	ans=min(ans,a['t']);
	if(ans<0)ans=0;
	printf("%d\n",ans);
}