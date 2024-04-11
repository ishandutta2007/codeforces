#include <stdio.h>
#include <memory.h>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;
#define M 100100
int deg[M];
int num[M];
vector<int> v[M];
int a[M], b[M];

int main(){
///	freopen("1.in", "r", stdin);
	int i, j, k, n, m;
	int x, y;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		deg[x]++, deg[y]++;
	}

	if(n<20 and n*(n-1)<4*m){
		puts("-1");
		return 0;
	}
	if(n==4 and m==3){
		for(i=1; i<=4; i++)if(!deg[i])break;
		if(i<=4){
			puts("-1");	return 0;
		}
	}

	while(1){
		int ans = 0;
		memset(num, 0, sizeof(num));
		int t = rand()%n + 1;
		for(int ii=t; ii<n+t; ii++){
			if(ii>n)i=ii-n; else i=ii;
			if(num[i]<2){
				int I=v[i].size();
				if(I>0)x=v[i][0]; else x=0;
				if(I>1)y=v[i][1]; else y=0;
		///		printf("i=%d, cur=%d\n", i, cur);
				for(j=i+1; j<=n; j++)if(i!=j and num[j]<2 and j!=x and j!=y){
					a[ans] = i, b[ans++] = j;
					num[i]++;
					num[j]++;
					if(ans==m){
						for(k=0; k<ans; k++){
							printf("%d %d\n", a[k], b[k]);
						}
						return 0;
					}
					if(num[i]==2)break;
				}
			}
		}

		ans = 0;
		memset(num, 0, sizeof(num));
		t = rand()%n + 1;
		for(int ii=t+n; ii>t; ii--){
			if(ii>n)i=ii-n; else i=ii;
			if(num[i]<2){
				int I=v[i].size();
				if(I>0)x=v[i][0]; else x=0;
				if(I>1)y=v[i][1]; else y=0;
		///		printf("i=%d, cur=%d\n", i, cur);
				for(j=i+1; j<=n; j++)if(i!=j and num[j]<2 and j!=x and j!=y){
					a[ans] = i, b[ans++] = j;
					num[i]++;
					num[j]++;
					if(ans==m){
						for(k=0; k<ans; k++){
							printf("%d %d\n", a[k], b[k]);
						}
						return 0;
					}
					if(num[i]==2)break;
				}
			}
		}

		if(clock()>2800000.){
			puts("-1");
			return 0;
		}
	}
	return 0;
}