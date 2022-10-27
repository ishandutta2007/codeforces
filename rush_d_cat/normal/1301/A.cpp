#include <bits/stdc++.h>
using namespace std;
int t;
const int N=102;
char a[N],b[N],c[N];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%s%s%s",a+1,b+1,c+1);
		bool ok=1;
		for(int i=1;a[i];i++){
			if(!(a[i]==c[i]||b[i]==c[i])) ok=0;
		}
		printf("%s\n", ok?"YES":"NO");
	}
}