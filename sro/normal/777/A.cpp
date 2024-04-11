#include <cstdio>
#include <iostream>
using namespace std;

int qk[100][3],cnt=1,n,m;
int main()
{
	scanf("%d%d",&n,&m);
	qk[0][0]=0;qk[0][1]=1;qk[0][2]=2;
	qk[1][0]=1;qk[1][1]=0;qk[1][2]=2;
	while(qk[cnt][0]!=0||qk[cnt][1]!=1||qk[cnt][2]!=2)
	{
		cnt++;
		for(int i=0;i<3;i++)qk[cnt][i]=qk[cnt-1][i];
		if(cnt&1)swap(qk[cnt][0],qk[cnt][1]);
		else swap(qk[cnt][2],qk[cnt][1]);
	}
	printf("%d",qk[n%cnt][m]);
	return 0;
}