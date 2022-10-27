#include <bits/stdc++.h>
using namespace std;
const int N=1002;
int t,n,x,a[N];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&x);
		int c1=0,c2=0,s=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]%=2;
			if(a[i]==0)c1++;else c2++;
			s+=a[i];
		}
		s%=2;
		if(x==n) {
			printf("%s\n", s==1?"Yes":"No");
		} else {
			if(c1==n) {
				printf("No\n");
			} else if(c2==n) {
				printf("%s\n", x%2==1?"Yes":"No");
			} else {
				printf("Yes\n");
			}
		}

	}
}