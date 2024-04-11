#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;
typedef long long ll;

int t;
char a[110],b[110],c[110];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%s%s%s",a+1,b+1,c+1);
		int n = strlen(a+1);
		int flag = 0;
		for(int i=1;i <= n;i++)
			if(a[i] != c[i] && b[i] != c[i]){
				puts("NO");
				flag = 1;
				break;
			}
		if(!flag)
			puts("YES");
	}
}