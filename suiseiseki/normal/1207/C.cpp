#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 200000
#define Inf (1ll<<60)
char s[Maxn+5];
ll f[Maxn+5][2];
int n,a,b;
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&a,&b);
		scanf("%s",s+1);
		f[0][0]=b;
		f[0][1]=Inf;
		for(int i=1;i<=n;i++){
			f[i][0]=mn(f[i-1][0]+a,f[i-1][1]+(a<<1))+b;
			f[i][1]=mn(f[i-1][0]+(a<<1),f[i-1][1]+a)+(b<<1);
			if(s[i]=='1'||s[i+1]=='1'){
				f[i][0]=Inf;
			}
		}
		cout<<f[n][0]<<endl;
	}
	return 0;
}