#include<bits/stdc++.h>
using namespace std;

const int N=105;


int a[N];
int b[N];
bool l[N];
bool cmp(int x,int y){return x>y;}
int n;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		int cnt=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>l[i];
		for (int i=1;i<=n;i++)
		{
			if (!l[i]) b[++cnt]=a[i];
		}
		sort(b+1,b+cnt+1,cmp);
		int cnt2=0;
		for (int i=1;i<=n;i++)
		{
			if (l[i]) cout<<a[i]<<" ";
			else cout<<b[++cnt2]<<" ";
		}
		cout<<endl;
		for (int i=1;i<=100;i++) a[i]=b[i]=l[i]=0;
	}
}