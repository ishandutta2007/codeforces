#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
ll a[Maxn+5];
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=(n>>1);i++){
		scanf("%d",&x);
		a[i<<1]=x;
	}
	ll now=0;
	ll sum=0;
	ll sq;
	for(int i=1;i<=n;i+=2){
		while(now*now<=sum){
			now++;
		}
		while(now<=100000){
			sq=(ll)sqrt(now*now*1.0+a[i+1]);
			if(sq*sq==now*now+a[i+1]){
				a[i]=now*now-sum;
				break;
			}
			if(now*now-sum>10000000000000ll){
				puts("No");
				return 0;
			}
			now++;
		}
		if(a[i]<1||a[i]>10000000000000ll||now>(a[i+1]-1)>>1){
			puts("No");
			return 0;
		}
		sum+=a[i]+a[i+1];
	}
	puts("Yes");
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}