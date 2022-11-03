#include <bits/stdc++.h>
using namespace std;

int n,a[300005];
int m;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	cin>>m;
	for(int i=0;i<m;i++){
		int q;
		cin>>q;
		cout<<sum-a[q-1]<<endl;
	}
	return 0;
}