#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5000 + 10;
int f[N][N], las[N];
int t[N], x[N], n;
int dis(int i,int j){
	return abs(x[i] - x[j]);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&t[i],&x[i]);
		las[i] = t[i];
	}	
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(f[i][j]==0)continue;
			//printf("f[%d][%d]=%d\n", i,j,f[i][j]);
			if(j==0){
				//printf("las[%d] = %d\n", i, las[i]);
				for(int nex=i+2;nex<=n;nex++){
					int t1 = max(dis(i,nex), t[i] - las[i]);

					if(t1 + dis(nex,i+1) <= t[i+1] - las[i]) {
						f[i+1][nex] = 1;
						//printf("upd1 %d %d\n", i + 1, nex);
					}
				}
				int tot=0;
				for(int nex=i+1;nex<=n;nex++) {
					int need = tot + dis(nex - 1, nex); // arrive nex
					need = max(need, t[nex-1]-las[i]);
					if(need <= t[nex] - las[i]) {
						las[nex] = min(las[nex], t[i] + need);
						tot = need;
						// printf("bu %d %d\n", nex,0);
						f[nex][0] = 1;
					}else{
						break;
					}
				}
				if(dis(i,i+1) <= t[i+1]-t[i]){
					//printf("upd4 %d %d\n", i+1,0);
					f[i+1][0] = 1;
				}
			}else{
				if(i+1==j){
					for(int nex=i+2;nex<=n;nex++) {
						if(nex>i+2) {
							int t1 = max(dis(i,nex), t[i+1]-t[i]);
							int t2 = dis(nex,i+2);
							if(t1+t2 <= t[i+2]-t[i]) {
								//printf("upd4 %d %d\n", i+2,nex);
								f[i+2][nex] = 1;
							}
						}
					}

					int tot=0;
					for(int nex=i+2;nex<=n;nex++){
						int need=tot + ((nex==i+2)?dis(nex,i):dis(nex,nex-1));
						need=max(need,t[nex-1]-t[i]);
						if(need <= t[nex] - t[i]) {
							las[nex] = min(las[nex], t[i] + need);
							tot = need;
							
							f[nex][0] = 1;

						}else{
							break;
						}
					}

					// x[i]    x[i+2]
					if(dis(i+2, i) <= t[i+2]-t[i]) {
						//printf("upd6 %d %d\n", i+2,0);
						f[i+2][0]=1;
					}
				}else{
					if(dis(i,i+1) <= t[i+1]-t[i]){
						//printf("upd7 %d %d\n", i+1,j);
						f[i+1][j]=1;
					}
				}
			}
		
		
		}
	}
	bool win=false;
	for(int i=0;i<=n;i++) win |= f[n][i];
	if(f[n-1][n]) win |= 1;
	printf("%s\n", win?"YES":"NO");
}