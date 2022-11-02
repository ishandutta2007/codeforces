#include<bits/stdc++.h>
using namespace std;
int n , sx , sy , x , y , num[30] , qwq;
void add( int x , int y )
{
	if(x < sx) num[1]++;
	if(x > sx) num[2]++;
	if(y < sy) num[3]++;
	if(y > sy) num[4]++;
	return ;
}
int main()
{
	scanf("%d%d%d" , &n , &sx , &sy);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d%d" , &x , &y);
		add(x , y);
	}
	qwq = 1;
	if(num[2] > num[qwq]) qwq = 2;
	if(num[3] > num[qwq]) qwq = 3;
	if(num[4] > num[qwq]) qwq = 4;
	printf("%d\n" , num[qwq]);
	if(qwq == 1) printf("%d %d" , sx - 1 , sy);
	if(qwq == 2) printf("%d %d" , sx + 1 , sy);
	if(qwq == 3) printf("%d %d" , sx , sy - 1);
	if(qwq == 4) printf("%d %d" , sx , sy + 1);
	return 0;
}