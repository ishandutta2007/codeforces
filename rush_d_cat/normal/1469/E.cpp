#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
int q,n,k;
char s[N];
int pre[N];
const int B=20;
int ban[1<<B],C;

int main() {
	scanf("%d",&q);
	while(q--) {
		++C;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		int prefix = max(k-B,0);
		int suffix = min(k,B);
		for(int i=1;i<=n;i++){
			if(s[i]=='0') pre[i]=0;
			else pre[i]=pre[i-1]+1;
		}
		//printf("pre = %d, suf = %d\n", prefix, suffix);
		for(int i=0;i<=n;i++){
			if(pre[i]>=prefix) {
				if(i+suffix>n) continue;
				int mask=0;
				for(int j=i+1;j<=i+suffix;j++){
					mask=mask<<1 | (s[j]=='0'?1:0);
				}
				//printf("i = %d, mask = %d\n", i, mask);
				ban[mask] = C;
			}
		}
		int val=-1;
		for(int i=0;i<1<<suffix;i++){
			if(ban[i] != C) {
				val=i; break;
			}
		}
		if(val==-1) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for(int i=1;i<=prefix;i++) printf("0");
			int high = suffix - 1;
			for(int i=high;i>=0;i--) printf("%c", val>>i&1?'1':'0');
			printf("\n");
		}
	}	
}