#include <bits/stdc++.h>
#define bptl(x) (__builtin_popcountll(x))
#define bit(x, y) (((x)>>(y))&1)
#define bpt(x) (__builtin_popcount(x))

using namespace std;
typedef double DO;
typedef long long INT;
#define NN 55
#define MM 22
char s[NN][MM];
DO f[MM];
INT g[1<<22];
int m;
void pre(){
	f[0]=1;
	for(int i=1;i<=m;i++) f[i]=f[i-1]*i/(m-i+1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	m=strlen(s[0]);
	pre();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int x=0;
			for(int k=0;k<m;k++){
				if(s[i][k]==s[j][k]){
					x|=1<<k;
				}
			}
			g[x]|=1LL<<i;
			g[x]|=1LL<<j;
		}
	}
	for(int i=(1<<m)-1;i>=0;i--){
		for(int j=0;j<m;j++){
			if(!bit(i,j)){
				g[i]|=g[i|(1<<j)];
			}
		}
	}
	DO ans=0;
	for(int i=0;i<1<<m;i++){
		for(int j=0;j<m;j++){
			if(!bit(i,j)){
				INT x=g[i]^g[i|(1<<j)];
				ans+=bptl(x)*f[bpt(i)+1];
			}
		}
	}
	printf("%.12lf\n",ans/n);
    return 0;
}