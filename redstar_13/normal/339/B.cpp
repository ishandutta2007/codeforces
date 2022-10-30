#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[100100];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",a+i);
	int t=1;
	for(int i=2;i<=m;i++){
		if(a[i]<a[i-1]) t++;
	}
	cerr<<t;
	INT s=(INT)(t-1)*n+a[m]-1;
	cout<<s<<endl;
	return 0;
}