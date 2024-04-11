#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[1010],t[1010][21];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+1;i++) {
		scanf("%d",a+i);
		int r=20;
		while(a[i]){
			t[i][r]=a[i]%2;
			a[i]/=2;
			r--;
		}
	}
	int s=0;
	for(int i=1;i<=m;i++){
		int r=0;
		for(int j=0;j<=20;j++){
			if(t[i][j]!=t[m+1][j]) r++;
		}
		if(r<=k) s++;
	}
	cout<<s<<endl;
	return 0;
}