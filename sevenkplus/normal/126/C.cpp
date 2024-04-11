#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2010
char s[N][N];int n,S=0;bool v1[N],v2[N],w1[N],w2[N];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=n-1;i>0;i--)
		for(int j=i;j<n;j++)
			if((s[j][j-i]-'0')^v1[j]^v2[j-i])S++,v1[j]^=1,v2[j-i]^=1;
	for(int i=n-1;i>0;i--)
		for(int j=i;j<n;j++)
			if((s[j-i][j]-'0')^w1[j-i]^w2[j])S++,w1[j-i]^=1,w2[j]^=1;
	for(int i=0;i<n;i++)
		if((s[i][i]-'0')^v1[i]^v2[i]^w1[i]^w2[i])S++;
	printf("%d\n",S);
	return 0;
}