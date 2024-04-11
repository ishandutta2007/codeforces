#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,len,anslen,top,minn,kmp[N];
char c[N],ans[N];
int main()
{ 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c+1);
		len=strlen(c+1);
		minn=min(anslen,len);
		top=len;
		c[++top]='#';
		kmp[0]=0;
		kmp[1]=0;
		for(int j=1;j<=minn;j++)c[++top]=ans[anslen-(minn-j)];
		for(int j=1;j<top;j++)
		{
			int k=kmp[j];
			while(k && c[k+1] !=c[j+1]) k=kmp[k];
			if(c[k+1]==c[j+1]) k++;
			kmp[j+1]=k;
		}
		for(int j=kmp[top]+1;j<=len;j++) ans[++anslen]=c[j];
	}
	for(int i=1;i<=anslen;i++)cout<<ans[i];
	return 0;
}