#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int ce(int a,int b)
{
	return (a+b-1)/b;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		int kk=n/k;
//		cout<<kk<<endl;
		if(kk>=m)
			cout<<m<<endl;
		else
			cout<<kk-ce(m-kk,k-1)<<endl;
	}
	return 0;
}