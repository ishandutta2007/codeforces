#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[201010];
ll bit[201010];
int main(){

	ll i,j,k,l,m,n,cnt=0,sum=0,ans=0,mb=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	for(i=1;i<=n;i++){
		m=arr[i];
		ll chk=0;
		while(m){
			bit[chk]+=(m%2);
			chk++;
			m/=2;
		}
	}

	for(i=100000;i>=1;i--){
		if(bit[i]==1) {
			mb=i;
			break;
		}
	}
	ll st=0;
	for(i=1;i<=n;i++){
		if(arr[i]&(1<<mb)){
			st=i;
			break;
		}
	}
	swap(arr[st],arr[1]);
	for(i=1;i<=n;i++)
		printf("%lld ",arr[i]);

	
}