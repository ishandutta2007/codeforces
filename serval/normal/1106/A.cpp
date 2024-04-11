#include <cstdio>
using namespace std;
const int N=505;
int n,cnt;
char m[N][N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%s",m[i]+1);
	for (int i=2;i<n;i++)
		for (int j=2;j<n;j++)
			if (m[i][j]=='X'&&m[i-1][j-1]=='X'&&
				m[i-1][j+1]=='X'&&m[i+1][j-1]=='X'&&
				m[i+1][j+1]=='X')
				cnt++;
	printf("%d\n",cnt);
	return 0;
}