#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	vector<pair<int,int> > a;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.push_back(make_pair(x,y));
	}
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=0;i<n-1;i++){
		int d=2*a[i+1].first-2*a[i].first-a[i+1].second-a[i].second;
		if(d>=2*t)
			ans++;
		if(d>2*t)
			ans++;
	}
	cout<<ans+2;
	return 0;
}