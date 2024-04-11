#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int x[maxn][2];
int n;
int s;
int cal(int a, int tp)
{
	int ans = 0;
	for(int j = 1; j <= s; j++)
		if(x[j][tp] == a) ans++;
	return ans;
}
int fd(int a, int tp)
{
	for(int j = 1; j <= s; j++)
		if(x[j][tp] == a)
			return j;
}
int main()
{
	int n;
	cin>>n;
	s = 4 * n + 1;
	int mx[2] = {0, 0}, mi[2] = {51, 51};
	for(int i = 1; i <= s; i++)
		cin>>x[i][0]>>x[i][1], 
		mx[0] = max(mx[0], x[i][0]), 
		mx[1] = max(mx[1], x[i][1]), 
		mi[0] = min(mi[0], x[i][0]), 
		mi[1] = min(mi[1], x[i][1]);
	int ans = 0;
	if(cal(mx[0], 0) == 1) ans = fd(mx[0], 0);
	else if(cal(mx[1], 1) == 1) ans = fd(mx[1], 1);
	else if(cal(mi[0], 0) == 1) ans = fd(mi[0], 0);
	else if(cal(mi[1], 1) == 1) ans = fd(mi[1], 1);
	else
	{
		for(int i = 1; i <= s; i++)
			if(x[i][0] == mx[0] || x[i][0] == mi[0] || x[i][1] == mx[1] || x[i][1] == mi[1]) continue;
			else 
			{
			//	cout<<"!@#!@#"<<i<<" "<<x[i][1]<<" "<<mx[1]<<endl;
				ans =i;
			}
	}
	cout<<x[ans][0]<<" "<<x[ans][1]<<endl;
	return 0;
}