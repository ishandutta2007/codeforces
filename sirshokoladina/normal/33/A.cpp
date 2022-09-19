#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10000];

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<10000;i++)
		a[i]=1000000000;
	int s=0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x-1]=min(a[x-1],y);
	}
	for(int i=0;i<m;i++)
		if(a[i]<1000000000)
			s+=a[i];
	cout<<min(s,k);
	return 0;
}