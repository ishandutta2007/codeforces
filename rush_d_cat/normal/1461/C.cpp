#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int n,m,a[N],r[N]; double p[N];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++){
			scanf("%d%lf",&r[i],&p[i]);
		}

		int las=0;
		for(int i=n;i>=1;i--){
			if(a[i]!=i){
				las=i; break;
			}
		}
		if(las==0) {
			printf("1\n");
		}else{

			bool ok=0;
			for(int i=1;i<=m;i++){
				if(r[i]>=las){
					ok=1;
				}
			}
			if(!ok) {
				printf("0\n"); continue;
			}else{
				double res=1;
				for(int i=1;i<=m;i++){
					if(r[i]>=las){
						res *= (1-p[i]);
					}
				}
				printf("%.8f\n", 1 - res);
			}
		}
    }
}