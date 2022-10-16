#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=500;
const int Mod=1000000007;
int n;
int cnt[Maxn+5];
int main(){
    int x;
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x>0){
			cnt[x]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]){
			ans=(ans+quick_power(2,cnt[i],Mod)-1)%Mod;
		}
	}
	printf("%d\n",(quick_power(2,n-1,Mod)-1-ans+Mod)%Mod);
    return 0;
}