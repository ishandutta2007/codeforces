#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
int a[200200];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,t,c;
	scanf("%d%d%d",&n,&t,&c);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int r=0;
	for(int i=1;i<=n;i++) {
		if(a[i]<=t) {
			int e=0,j;
			for(j=i;j<=n;j++){
				if(a[j]>t) {i=j-1;break;}
				else e++;
			}
			cerr<<e<<endl;
			if(e>=c) r+=e-(c-1);
			if(j==n+1) break;
		}
	}
	cout<<r<<endl;
	return 0;
}