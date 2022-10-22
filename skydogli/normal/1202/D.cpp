#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define int long long
int n,s[MN];
signed main(){
	int T;
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d",&n);
		putchar('1');
		int p=1;
		while(((p*(p-1))>>1)<=n)
			p++;
		p--;
		int c=0;
		while(n){
			n-=p*(p-1)/2;
			s[++c]=p;
			while(p*(p-1)/2>n)
				p--;
		}
		s[c+1]=0;
		for(int i=c;i;--i){
			for(int j=s[i+1]+1;j<=s[i];++j)
				putchar('3');
			putchar('7');
		}
		putchar('\n');
	}
	return 0;
}