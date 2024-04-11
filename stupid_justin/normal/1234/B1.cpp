#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int que[N];
int head=1e6+1,tail=1e6;
int n,k;
int id[N];
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>id[i];
	for (int i=1;i<=n;i++)
	{
		bool flag=0;
		for (int j=head;j<=tail;j++) if(que[j]==id[i]) flag=1;
		if (!flag)
		{
			head--;
			que[head]=id[i];
			if (tail-head+1>k) tail--;
		}
	}
	cout<<tail-head+1<<endl;
	for (int i=head;i<=tail;i++) cout<<que[i]<<" ";
}