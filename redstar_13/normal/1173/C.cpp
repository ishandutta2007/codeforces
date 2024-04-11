#include<bits/stdc++.h>
using namespace std;
int f[200200],a[200200],b[200200];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	if(n==0){
		cout<<0<<endl;return 0;
	}
	for(int i=1;i<=n;i++) {scanf("%d",a+i);f[a[i]]=1;}
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	for(int i=1;i<=n;i++) {
		if(b[i]!=i) break;
		if(i==n) {
			printf("0\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++) {
		if(b[i]) break;
		if(i==n){
			cout<<n<<endl;
			return 0;
		}
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1) {t=i;break;}
	}
	int fg=0;
	if(t) for(int i=t;i<=n;i++){
		if(b[i]!=i-t+1) break;
		if(i==n) fg=1;
	}
	if(fg) for(int i=n-t+2;i<=n;i++){
		if(f[i]) {
			f[b[i-(n-t+1)]]=1;
			if(i==n) {cout<<t-1<<endl;return 0;}
		}
		else break;
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(b[i]) s=max(s,i+1-b[i]);
	}
	cout<<s+n<<endl;
	return 0;
}