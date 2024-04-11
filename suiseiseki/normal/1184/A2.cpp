#include <bits/stdc++.h>
using namespace std;
#define Maxn 200000
int n,f[Maxn+5],s,ans;
char c[Maxn+5];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	scanf("%s",c+1);
	for(int i=1,j;i<=n;i++){
		if(n%i==0){
			for(j=1;j<=i;j++){
				s=0;
				for(int k=j;k<=n;k+=i){
					s^=(c[k]^48);
				}
				if(s==1){
					break;
				}
			}
			if(j>i){
				f[i]=1;
			}
		}
	}
	int tmp;
	for(int i=1;i<=n;i++){
		tmp=gcd(i,n);
		ans+=f[tmp];
	}
	cout<<ans<<endl;
	return 0;
}