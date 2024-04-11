#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,a[200500],l,r,md,res;

bool chk(int i){
	int y=m,z=k;
	for(;i<=n;i++){
		if(z>=a[i]){
			z-=a[i];
		}
		else{
			if(y==1)return 0;
			y--;z=k-a[i];
		}
		//printf("nmsl%d %d %d\n",i,y,z);
	}
	return 1;
}

int main() {
	cin.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	l=1;r=n;
	while(l<=r){
		md=(l+r)/2;
		if(chk(md))res=max(res,n-md+1),r=md-1;
		else l=md+1;
	}
	cout<<res;
}