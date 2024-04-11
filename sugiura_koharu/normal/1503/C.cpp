#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
pair <int,int> a[100005];
int main(int argc, char** argv) {
	long long ans=0;
	int n;
	cin >>n ;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first >> a[i].second;
		ans+=a[i].second;
	}
	sort(a+1,a+n+1);
	int mx=a[1].first;
	for(int i=1;i<=n;i++)
	{
		ans+=max(0,a[i].first-mx);
		mx=max(mx,a[i].second+a[i].first);
	}
	cout << ans;
	return 0;
}