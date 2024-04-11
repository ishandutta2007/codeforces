#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
char s[N],t[N]; int x;
int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%s%d", s+1, &x);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++) t[i]='1'; t[n+1]='\0';
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				if(i+x<=n) t[i+x]='0';
				if(i-x>=1) t[i-x]='0';
			}
		}
		bool ok=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				bool tmp=0;
				if(i+x<=n && t[i+x]=='1') tmp=1;
				if(i-x>=1 && t[i-x]=='1') tmp=1;
				ok &= tmp;
			}
		}
		if (! ok) printf("-1\n");
		else 
		printf("%s\n", t + 1);	
	}

}