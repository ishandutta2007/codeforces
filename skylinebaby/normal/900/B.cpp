#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int t = a % b;
	int iden = 0;
	for(int i = 1;i<=b+5;i++)
	{
		if ((c+1)*b>10*t&&10*t>=c*b) {iden = i;break;}
		else t = (t*10)%b;
	}
	if (iden == 0) printf("-1\n");
	else printf("%d\n",iden);
	return 0; 
}