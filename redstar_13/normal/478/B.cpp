#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	INT mx=0,mi=0;
	INT t=n-(m-1);
	mx=(t-1)*t/2;
	INT y=n/m;
	int l=(n-m*y);
	for(int i=1;i<=l;i++){
		mi+=(y+1)*y/2;
	}
	for(int i=l+1;i<=m;i++) mi+=(y-1)*y/2;
	cout<<mi<<" "<<mx<<endl;
	return 0;
}