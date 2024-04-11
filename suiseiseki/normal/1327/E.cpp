#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
const int Maxn=200000;
ll n,pw[Maxn+5];
int main(){
	cin>>n;
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*10%Mod;
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			puts("10");
		}
		else{
			cout<<(pw[n-i]*18ll+(n-i-1)*pw[n-i-1]*81ll)%Mod<<" ";
		}
	}
	return 0;
}