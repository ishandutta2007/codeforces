#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxn,k,n,t,ans;
bool numlist[100000001];
int prime[20000001], cnt;
void work(int n){
	for(int i=2; i<=n; i++){
		if(numlist[i]==false){
			prime[++cnt] = i ;
			for(int j=i; i*j<=n; j++)
				numlist[i*j] = true;
		}
	}
	return;
}
signed main()
{
	work(1000000);
	cin>>t;
	while(t--)
	{
		k=0;
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			if(prime[i]>sqrt(n))
			break;
			int sum=0;
			int m=n;
			while(m%prime[i]==0)
			{
				sum++;
				m/=prime[i];
			}
			if(sum>k)
			{
				k=sum;
				maxn=prime[i];
				ans=m;
			}	
		}
		if(k==0)
			cout<<1<<endl<<n<<endl;
		else
		{
			cout<<k<<endl;
			for(int i=1;i<k;i++)
				cout<<maxn<<" ";
			cout<<ans*maxn<<endl;
		}
	}
	return 0;
}