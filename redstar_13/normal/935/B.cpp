#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char a[100100];
int f[100100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	cin>>a+1;
	int t=0,u=0,r=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='U') u++;
		else r++;
		if(u>r) {
			t++;
			f[t]=1;
		}
		if(u<r){
			t++;
			f[t]=0;
		}
	}
	int s=0;
	for(int i=2;i<=t;i++){
		if(f[i]!=f[i-1]) s++;
	}
	cout<<s<<endl;
	return 0;
}