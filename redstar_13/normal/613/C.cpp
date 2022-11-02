#include <bits/stdc++.h>

using namespace std;
#define NN 30
int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	int cnt=0,d=0,id=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d=__gcd(d,a[i]);
		if(a[i]&1){
			id=i;
			cnt++;
		}
	}
	if(cnt>1){
		puts("0");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++) printf("%c",'a'+i-1);
		}
		return 0;
	}
	printf("%d\n",d);
	if(!cnt){
		for(int ii=1;ii<=d/2;ii++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=a[i]/d;j++) printf("%c",'a'+i-1);
			}
			for(int i=n;i>=1;i--){
				for(int j=1;j<=a[i]/d;j++) printf("%c",'a'+i-1);
			}
		}
	}
	else{
		for(int ii=1;ii<=d;ii++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=a[i]/d/2;j++) printf("%c",'a'+i-1);
			}
			printf("%c",'a'+id-1);
			for(int i=n;i>=1;i--){
				for(int j=1;j<=a[i]/d/2;j++) printf("%c",'a'+i-1);
			}
		}
	}
    return 0;
}