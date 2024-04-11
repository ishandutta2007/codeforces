#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[N][3];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		char ch;
		for (int i=1;i<=n;i++) 
		{
			cin>>ch;
			if (ch<='2') a[i][1]=1;
			else
			a[i][1]=2;
		}
		getchar();
		for (int i=1;i<=n;i++) 
		{
			cin>>ch;
			if (ch<='2') a[i][2]=1;
			else
			a[i][2]=2;
		}
		getchar();
		bool reach=1;
		int line=1;
//		for (int i=1;i<=n;i++) cout<<a[i][1];cout<<endl;
//		for (int i=1;i<=n;i++) cout<<a[i][2];cout<<endl;
		for (int i=1;i<=n;i++)
		{
			if (a[i][1]==2 && a[i][2]==2)
			{
				if (line==1) line=2;else
				if (line==2) line=1;
			}
			else
			if (a[i][line]!=1) reach=0;
//			cout<<line<<endl;
		}
		if (line==1) reach=0;
		if (reach) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
}