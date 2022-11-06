//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int t; 
int a[3]; 
int ans;

int main()
{
	cin>>t;
	while(t--)
	{
		ans = 0;
		cin>>a[0]>>a[1]>>a[2];
		if(a[0] < a[1]) swap(a[0], a[1]);
		if(a[0] < a[2]) swap(a[0], a[2]);
		if(a[1] < a[2]) swap(a[1], a[2]);
		if(a[0]) --a[0], ++ans;
		if(a[1]) --a[1], ++ans;
		if(a[2]) --a[2], ++ans;
		if(a[0] && a[1]) --a[0], --a[1], ++ans;
		if(a[0] && a[2]) --a[0], --a[2], ++ans;
		if(a[1] && a[2]) --a[1], --a[2], ++ans;
		if(a[0] && a[1] && a[2]) --a[0], --a[1], --a[2], ++ans;
		cout<<ans<<endl;
	}
	return 0;
}