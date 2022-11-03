/*
ID: Sfiction
OJ: CF
PROB: 512A
*/
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int SIGMA=26,MAXN=1E2+10;

char name[MAXN][MAXN];

vector<int> E[SIGMA];
int in[SIGMA];

int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%s",name[i]);
	memset(in,0,sizeof(in));
	for (int i=1;i<n;++i){
		int j;
		for (j=0;name[i][j] && name[i-1][j] && name[i][j]==name[i-1][j];++j);
		if (!name[i-1][j])
			continue;
		if (!name[i][j]){
			puts("Impossible");
			return 0;
		}
		E[name[i-1][j]-'a'].push_back(name[i][j]-'a');
		++in[name[i][j]-'a'];
	}
	char ans[30],r=0;
	for (int i=0;i<SIGMA;++i){
		int j;
		for (j=0;j<SIGMA;++j)
			if (in[j]==0)
				break;
		if (j==SIGMA){
			puts("Impossible");
			return 0;
		}
		in[j]=-1;
		ans[r++]='a'+j;
		for (int k=E[j].size()-1;k>=0;--k)
			--in[E[j][k]];
	}
	ans[r]=0;
	puts(ans);
	return 0;
}