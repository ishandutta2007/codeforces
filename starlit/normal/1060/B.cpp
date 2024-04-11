#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int ans,x,f;
int main(){
	scanf("%lld",&n);
	for(;n;){
		x=n%10-f,n/=10;
		if(x==9||!n)ans+=x,f=0;
		else ans+=10+x,f=1;
	}
	printf("%d",ans);
}