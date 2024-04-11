#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int n,k,A,B;
int find_lower(int x){
	if(a[k]<x){
		return -1;
	}
	int left=1,right=k,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(a[mid]>=x){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}
int find_upper(int x){
	if(a[1]>x){
		return -1;
	}
	int left=1,right=k,mid;
	while(left<right){
		mid=(left+right+1)>>1;
		if(a[mid]<=x){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	return left;
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
ll work(int left,int right){
	if(left>right){
		return (1ll<<60);
	}
	int l=find_lower(left),r=find_upper(right);
	if(l==-1||r==-1||l>r){
		return A;
	}
	if(left<right){
		return mn(1ll*B*(right-left+1)*(r-l+1),work(left,(left+right)>>1)+work(((left+right)>>1)+1,right));
	}
	else{
		return 1ll*B*(right-left+1)*(r-l+1);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&k,&A,&B);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+k);
	cout<<work(1,(1<<n))<<endl;
	return 0;
}