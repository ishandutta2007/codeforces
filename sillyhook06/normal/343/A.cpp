#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;i++)
long long a,b,ans;
int main()
{
	cin>>a>>b;
	while (b) ans+=a/b,a%=b,swap(a,b);
	cout<<ans<<endl;
	return 0;
}