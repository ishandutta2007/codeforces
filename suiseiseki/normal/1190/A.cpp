#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxm 100000
ll n,k;
int m;
ll p[Maxm+5];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	ll t=0;
	int left,right,mid;
	ll num;
	int ans=0;
	for(int i=1,j;i<=m;i=j+1){
		num=(p[i]-t-1)/k;
		num++;
		num*=k;
		left=i,right=m;
		while(left<right){
			mid=(left+right+1)/2;
			if((p[mid]-t)<=num){
				left=mid;
			}
			else{
				right=mid-1;
			}
		}
		j=left;
		t+=j-i+1;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}