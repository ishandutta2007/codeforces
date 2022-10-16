#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int T,n,k,cnt,c;
int vis[30];
string str;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt=-1;
		scanf("%d%d\n",&n,&k);
		cin>>str;
		sort(str.begin(),str.end());
		if(str[0]!=str[k-1]) {
			putchar(str[k-1]);
			puts("");
			continue;
		}
		putchar(str[0]);
		if(str[k]!=str[n-1]) {
			for(int i=k;i<n;i++)
				putchar(str[i]);
			puts("");
		}
		else {
			for(int i=1;i<=(n-k)/k;i++)
				putchar(str[n-1]);
			if((n-k)%k) putchar(str[n-1]);
			puts("");
		}
	}
	return 0;
}