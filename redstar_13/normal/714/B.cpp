#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[100100],f[10];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	f[1]=a[1];
	int g=0;
	for(int i=2;i<=n;i++) {
		if(g==0 and a[i]!=f[1]) {f[2]=a[i];g=1;}
		if(g==1 and a[i]!=f[1] and a[i]!=f[2]) {f[3]=a[i];g=2;}
	}
	if(g==0 or g==1) {
		cout<<"YES"<<endl;
		return 0;
	}
	sort(f+1,f+4);
	for(int i=1;i<=n;i++){
		if(a[i]!=f[1] and a[i]!=f[2] and a[i]!=f[3]) {cout<<"NO"<<endl;return 0;}
	}
	if(f[2]*2!=f[1]+f[3]) {cout<<"NO"<<endl;return 0;}
	cout<<"YES"<<endl;
	return 0;
}