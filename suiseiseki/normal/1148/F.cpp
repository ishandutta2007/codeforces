#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 300000
#define ll long long
struct Node{
	int val;
	ll mask;
	int id;
}a[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		sum+=a[i].val;
		cin>>a[i].mask;
		for(int j=0;j<62;j++){
			if((1ll<<j)&a[i].mask){
				a[i].id=j;
			}
		}
	}
	if(sum<0){
		for(int i=1;i<=n;i++){
			a[i].val*=-1;
		}
		sum=-sum;
	}
	ll ans=0;
	ll tmp;
	for(int i=0;i<62;i++){
		tmp=0;
		for(int j=1;j<=n;j++){
			if(a[j].id==i){
				tmp+=a[j].val;
			}
		}
		if(tmp>0){
			ans|=(1ll<<i);
			for(int j=1;j<=n;j++){
				if((1ll<<i)&a[j].mask){
					a[j].val=-a[j].val;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}