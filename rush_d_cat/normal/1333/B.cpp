#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int t,n,a[N],b[N],f[N][2];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		f[0][0]=f[0][1]=0;
		for(int i=1;i<=n;i++){
			f[i][0]=f[i-1][0], f[i][1]=f[i-1][1];
			if(a[i]>0) f[i][0]=1;
			if(a[i]<0) f[i][1]=1;
		}
		bool flag=1;
		for(int i=n;i>=1;i--){
			if(a[i]==b[i])continue;
			if(a[i]>b[i] && f[i-1][1]==0) flag=0;
			if(a[i]<b[i] && f[i-1][0]==0) flag=0;
		}
		printf("%s\n", flag?"YES":"NO");
	}
}