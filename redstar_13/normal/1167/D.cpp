#include <bits/stdc++.h>

using namespace std;
#define NN 200010
char s[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int f=0,g=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			f^=1;
			printf("%d",f);
		}
		else{
			g^=1;
			printf("%d",g);
		}
	}
    return 0;
}