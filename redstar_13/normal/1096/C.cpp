#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==180) {printf("-1\n");continue;}
		if(n==179) {printf("360\n");continue;}
		for(int i=3;i<=180;i++){
			if((n*i)%180==0){
				int t=n*i/180;
				if(t<=i-2) {cout<<i<<endl;break;}
			}
		}
	}
	return 0;
}