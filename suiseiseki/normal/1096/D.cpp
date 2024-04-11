#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
int n;
ll f[Maxn+5];
int a[Maxn+5];
char s[Maxn+5];
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='h'){
			f[1]+=a[i];
		}
		else if(s[i]=='a'){
			f[2]=mn(f[1],f[2]+a[i]);
		}
		else if(s[i]=='r'){
			f[3]=mn(f[2],f[3]+a[i]);
		}
		else if(s[i]=='d'){
			f[4]=mn(f[3],f[4]+a[i]);
		}
	}
	cout<<mn(f[1],mn(f[2],mn(f[3],f[4])))<<endl;
	return 0;
}
//