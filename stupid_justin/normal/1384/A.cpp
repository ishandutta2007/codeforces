#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[N];
char ch[205];
void wt()
{
	for (int i=1;i<=200;i++) cout<<ch[i];
	cout<<endl;
}
int main()
{
	int n;
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=200;i++) ch[i]='a';
		wt();
		for (int i=1;i<=n;i++)
		{
			if (ch[a[i]+1]=='a') ch[a[i]+1]='b';else ch[a[i]+1]='a';
			wt();
		}
	}
}