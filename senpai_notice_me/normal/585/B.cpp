#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 105
using std::max;
using std::min;

bool can[MAX_N][5],arr[MAX_N][5];
int n,k,s;

int main() {
	int T; scanf("%d",&T); int k; bool flag;
	char ch;
	while (T--) {
		memset(can,true,sizeof(can));
		memset(arr,false,sizeof(arr));
		scanf("%d%d",&n,&k);
		for (int i=1;i<=3;i++) {
			getchar();
			for (int j=1;j<=n;j++) {
				ch=getchar(); if (ch=='s') s=i; can[j][i]=(ch=='.' || ch=='s');
			}
		}
		arr[1][s]=1;
		for (k=1;k-3<n;k+=3) {
			if (k==1) continue; flag=false;
			for (int i=1;i<=3;i++) {
				if (!can[k][i]) continue;
				for (int j=-1;j<=1;j++) {
					if (i+j<1 || i+j>3) continue;
					if (!arr[k-3][i+j] || !can[k-2][i+j] || !can[k-2][i] || !can[k-1][i]) continue;
					arr[k][i]=flag=true;
				}
			}
			if (!flag) {
				puts("NO"); goto while_end;
			}
		}
		puts("YES");
		while_end:;
	}
	return 0;
}