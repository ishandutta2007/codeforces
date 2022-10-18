#include<bits/stdc++.h>
using namespace std;
const int N=405;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		bool flag=0;
		int n;
		cin>>n;
		int a[10005],b[N];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=1;i<=4*n;i++) 
		{
			int m;
			cin>>m;
			a[m]++;
		}
//		for (int i=1;i<=10;i++) printf("a[%d]=%d\n",i,a[i]);
		for (int i=1;i<=10000;i++)
		{
			if (a[i]%2==1) flag=1; 
		}
//		cout<<flag<<endl;
		if (!flag)
		{
			int tmp=0;
			for (int i=1;i<=10000;i++)
			{
				
				if (a[i]!=0)
					for (int j=1;j<=a[i]/2;j++)
					{
						tmp++;
						b[tmp]=i;
					}
			}
//			for (int i=1;i<=tmp;i++) printf("b[%d]=%d\n",i,b[i]);
			int s=b[1]*b[tmp];
			for (int i=1;i<=n;i++)
			{
				if (b[i]*b[tmp-i+1]!=s) flag=1;
			}
		}
		if (flag) cout<<"NO"<<endl;else cout<<"YES"<<endl;
	}
}