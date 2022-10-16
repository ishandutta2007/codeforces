#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 1000000
#define ll long long
int a[Maxn+5];
int n;
ll k;
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int main(){
	scanf("%d",&n);
	cin>>k;
	ll K=k;
	ll sum=0;
	for(int i=1;i<=n;i++){
		a[i]=i;
		sum+=i;
	}
	if(sum>k){
		puts("-1");
		return 0;
	}
	k-=sum;
	for(int i=1;i<=n/2;i++){
		if((n-2*i+1)>=k){
			int tmp=i+k;
			swap(a[i],a[tmp]);
			cout<<K<<endl;
			for(int j=1;j<=n;j++){
				printf("%d ",a[j]);
			}
			puts("");
			for(int j=1;j<=n;j++){
				printf("%d ",j);
			}
			puts("");
			return 0;
		}
		swap(a[i],a[n-i+1]);
		k-=(n-2*i+1);
	}
	cout<<K-k<<endl;
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	for(int i=1;i<=n;i++){
		printf("%d ",i);
	}
	puts("");
	return 0;
}