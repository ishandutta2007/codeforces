#include<bits/stdc++.h>
using namespace std;

int n,z,x[200005];

bool check(int mid){
	for(int i=1;i<=mid;++i)
		if(x[i+n-mid]-x[i]<z)return false;
	return true;
}

int main(){
	scanf("%d%d",&n,&z);
	for(int i=1;i<=n;++i)scanf("%d",x+i);
	sort(x+1,x+1+n);
	int l=0,r=n/2;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}