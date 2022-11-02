#include <bits/stdc++.h>
using namespace std;
template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
typedef long long INT;
#define NN 200010
int a[NN];
int r[5];
int mx[NN];
int f[NN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	gn(n);
	for(int i=0;i<n;i++) gn(a[i]);
	INT ans=0;
	for(int d=1;d<n;d++){
		if(n%d!=0) continue;
		for(int i=0;i<d;i++){
			mx[i]=0;
			for(int j=i;j<n;j+=d) mx[i]=max(mx[i],a[j]);
			for(int j=i;j<n;j+=d){
				if(a[j]==mx[i]) f[j]=1;
				else f[j]=0;
			}
		}
		for(int i=n;i<2*n;i++) f[i]=f[i-n];
		for(int i=0;i<n;i++){
			if(!f[i]) continue;
			int st=i;
			while(f[st]==f[i]) st++;
			st--;
			int len=st-i+1;
			for(int j=d;j<=len;j+=d){
				if(j>=n) break;
				if(__gcd(j/d,n/d)!=1) continue;
				int ed=min(st-j+1,n-1);
				if(ed>=i) ans+=ed-i+1;
			}
			i=st;
		}
	}
	printf("%I64d\n",ans);
    return 0;
}