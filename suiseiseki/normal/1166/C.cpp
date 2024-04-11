#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define ll long long
int a[Maxn+5];
int n;
int find_l(int x){
	int left=1,right=n;
	int mid;
	while(left<right){
		mid=(left+right)>>1;
		if((a[mid]<<1)>=x){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}
int find_r(int x){
	int left=1,right=n;
	int mid;
	while(left<right){
		mid=(left+right+1)>>1;
		if((x<<1)>=a[mid]){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	return left;
}
int ab(int a){
	return a<0?-a:a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=ab(a[i]);
	}
	sort(a+1,a+1+n);
	int l,r;
	ll ans=0;
	for(int i=1;i<=n;i++){
		l=find_l(a[i]);
		r=find_r(a[i]);
		ans+=(r-l);	
	}
	cout<<(ans>>1)<<endl;
	return 0;
}