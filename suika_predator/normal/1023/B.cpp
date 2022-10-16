#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	long long n,k;
	cin>>n>>k;
	long long mx=(k-1)/2;
	if(n>=k-1)cout<<mx<<endl;
	else cout<<max(0ll,mx-(k-n)+1)<<endl;
	return 0;
}