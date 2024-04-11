#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	char t;
	int ans = 0;
	int x = 0;
	int y = 0;
	int wh = 0;
	cin >> t;
	if (t=='R') x+=1,wh = 0;
	else y += 1, wh = 1;
	for(int i = 1;i<n;i++)
	{
		cin >> t;
		if (t=='R') x+= 1;
		else y += 1;
		if (wh == 0&&y>x) ans ++, wh = 1;
		if (wh == 1&&x>y) ans ++, wh = 0;  
	}
	printf("%d\n",ans);
	return 0;
}