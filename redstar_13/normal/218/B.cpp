#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
#define NN 1100
int a[NN],b[NN];
int main(){
#ifndef ONLINE_JUDGE
	freopen("e.txt","r",stdin);
#endif
	int n,m,i;
	cin>>n>>m;
	int p=n;
	for(i=0;i<m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+m);
	int s=0;
	for(i=0;i<m;i++){
		if(a[i]<=n){
			s+=a[i]*(a[i]+1)/2;
			n-=a[i];
		}
		else {
			int t=a[i]-n+1;
			s+=(t+a[i])*n/2;
			break;
		}
	}
	
	int k=0;
	while(p--){
		sort(b,b+m);
		k+=b[m-1];
		b[m-1]-=1;
	}
	cout<<k<<" "<<s<<endl;
}