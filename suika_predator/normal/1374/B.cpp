#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a=0,b=0;
		while(n%2==0)n/=2,a++;
		while(n%3==0)n/=3,b++;
		if(n!=1||a>b)cout<<-1<<endl;
		else cout<<b+(b-a)<<endl;
	}
	return 0;
}