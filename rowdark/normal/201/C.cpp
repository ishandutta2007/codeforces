#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
vector<int> V;
long long A[100001][2];//0 a->b 1 a->a
int a[100001];
int ll;
int n,f;
long long ans,now;
long long cc;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		scanf("%d",a+i);
		if(a[i]==1)
		{
			now=0;
		}
		else
		{
			if(a[i]&1) now+=a[i]-1;
			else now+=a[i];
		}
		A[i+1][0]=now;
	}
	now=0;
	for(int i=n-1;i;--i)
	{
		if(a[i]==1)
		{
			now=0;
		}
		else
		{
			if(a[i]&1) now+=a[i]-1;
			else now+=a[i];
		}
		A[i][1]=now;
	}
	ans=A[1][1]+A[1][0];
	cc=A[1][0];
	for(int i=2;i<=n;++i)
	{
		if(a[i-1]&1) cc+=a[i-1];
		else cc+=a[i-1]-1;
		if(cc<A[i][0]) cc=A[i][0];
		if(cc+A[i][1]>ans) ans=cc+A[i][1];
	}
	cout<<ans<<endl;
	cin>>n;
	return 0;
}