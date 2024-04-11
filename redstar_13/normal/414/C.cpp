#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
#define NN 22
#define MM 2000010
int a[MM];
INT f[NN],g[NN];
int b[MM];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d",&n);
	for(int i=1;i<=(1<<n);i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int x=1<<(i-1);
		int N=1<<n;
		for(int j=1;j<=N/2/x;j++){
			int st=2*x*(j-1)+1;
			int nn=0;
			for(int k=st;k<st+x;k++) b[++nn]=a[k];
			sort(b+1,b+nn+1);
			for(int k=st+x;k<st+2*x;k++){
				int id=upper_bound(b+1,b+nn+1,a[k])-b;
				int jd=lower_bound(b+1,b+nn+1,a[k])-b;
				f[i]+=nn-id+1;
				g[i]+=jd-1;
			}
		}
	}
	int m;
	scanf("%d",&m);
	while(m--){
		int x;
		scanf("%d",&x);
		for(int i=1;i<=x;i++) swap(f[i],g[i]);
		INT ans=0;
		for(int i=1;i<=n;i++) ans+=f[i];
		printf("%I64d\n",ans);
	}
    return 0;
}