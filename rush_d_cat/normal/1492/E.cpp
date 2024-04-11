#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 250 + 10;
int n, m;
int main() {
	scanf("%d%d",&n,&m);
	int a[n+2][m+2] = {0}, down[n+2][m+2] = {0};
	//int a[N][N]={0},down[N][N]={0};
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(a[i+1][j]==a[i][j])down[i][j]=down[i+1][j];else down[i][j]=i+1;
		}
	}
	if(m==1) {
		printf("Yes\n"); printf("1\n"); return 0;
	}
	vector<int> dangers; dangers.push_back(1); dangers.push_back(2);

	bool ac=1;
	for(int i=2;i<=n;i++){
		vector<int> tmp;
		for(int j=1;j<=m;j++)if(a[1][j]!=a[i][j])tmp.push_back(j);
		if(tmp.size()>4) return !printf("No\n");
		if(tmp.size()>=3) ac=0;
		for(auto x:tmp) dangers.push_back(x);
	}
	if(ac) {
		printf("Yes\n");
		for(int i=1;i<=m;i++) printf("%d ", a[1][i]); printf("\n");
		return 0;
	}
		//for(auto x:dangers)printf("#%d\n", x);
	
	sort(dangers.begin(),dangers.end());
	dangers.erase(unique(dangers.begin(),dangers.end()),dangers.end());

	for(int i=0;i<dangers.size();i++){
		for(int j=i+1;j<dangers.size();j++){
			int x=dangers[i],y=dangers[j];
			int fouls[n+2]={0};
			//int fouls[N]={0};
			bool ok=true;
			for(int col=1;col<=m;col++){
				if(col==x||col==y)continue;
				int row=1;
				while(row<=n){
					if(a[row][col]==a[1][col]){
						row=down[row][col];
					}else{
						for(int y=row;y<down[row][col];y++){
							fouls[y]++; if(fouls[y]>2) {
								ok=false; break;
							}
						}
						row=down[row][col];
					}
				}
				if(!ok) break;
			}
			if(ok){
				//printf("x=%d,y=%d\n", x,y);
				for(int row=2;row<=n;row++){
					//printf("! fous[%d]=%d\n", row,fouls[row]);
					if(fouls[row]==2){
						bool tmp=true; 
						for(int i_=1;i_<=n;i_++) {
							int dif=0;
							if(a[i_][x]!=a[row][x]) dif++;
							if(a[i_][y]!=a[row][y]) dif++;
							if(dif+fouls[i_]>2){
								//printf("i_=%d,f=%d,dif=%d\n", i_,fouls[i],dif);
								tmp=false;
							}
						}
						if(tmp==true){
							printf("Yes\n");
							for(int j_=1;j_<=m;j_++){
								if(j_==x||j_==y) printf("%d ", a[row][j_]); else printf("%d ", a[1][j_]); 
							}
							printf("\n"); return 0;
						}else{
							ok=false; break;
						}
					}
				}
				if(ok==false) continue;
				for(int row=2;row<=n;row++){
					if(fouls[row]==1){
						{
							int cor=-1; bool fail=false;
							for(int i_=2;i_<=n;i_++) if(a[i_][x]!=a[row][x]) {
								fouls[i_]++; if(fouls[i_]==2) {
									if(cor==-1) cor=a[i_][y];
									else if(cor!=a[i_][y]) fail=true;
								}
							}
							for(int i_=2;i_<=n;i_++) if(a[i_][x]!=a[row][x]) fouls[i_]--;
							if(!fail) {
								printf("Yes\n"); if(cor==-1) cor=1;
								for(int j_=1;j_<=m;j_++){
									if(j_==x||j_==y) printf("%d ", j_==x?a[row][j_]:cor); else printf("%d ", a[1][j_]); 
								}
								printf("\n"); return 0;
							}
						}

						{
							int cor=-1; bool fail=false;
							for(int i_=2;i_<=n;i_++) if(a[i_][y]!=a[row][y]) {
								fouls[i_]++; if(fouls[i_]==2) {
									if(cor==-1) cor=a[i_][x];
									else if(cor!=a[i_][x]) fail=true;
								}
							}
							for(int i_=2;i_<=n;i_++) if(a[i_][y]!=a[row][y]) fouls[i_]--;
							if(!fail) {
								printf("Yes\n"); if(cor==-1) cor=1;
								for(int j_=1;j_<=m;j_++){
									if(j_==x||j_==y) printf("%d ", j_==y?a[row][j_]:cor); else printf("%d ", a[1][j_]); 
								}
								printf("\n"); return 0;
							}
						}
					}
				}
			}else{
				continue;
			}
		}
	}
	printf("No\n");
}