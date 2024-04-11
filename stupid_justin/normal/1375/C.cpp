#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int inf=0x3f3f3f;
const int mod=1e9+7;


//k 
int n;
int a[N];
int be[N];int ed[N];int cnt;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cnt=0;cnt++;
		cin>>a[1];
		be[1]=1;
		for (int i=2;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]<a[i-1])
			{
				ed[cnt]=i-1;
				cnt++;be[cnt]=i;
			}
		}
		if (a[n]>a[1]) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
}