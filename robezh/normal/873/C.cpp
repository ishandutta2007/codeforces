#include<cstdio>
#include<iostream>
using namespace std;

int num[105][105];
int replace[105];
int maxv[105];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&num[i][j]);
		}
	}
	for(int j = 0; j < m; j++){
		int cnt1 = 0;
		maxv[j] = 0;
		replace[105] = 0;
		int v = 0;
		for(int i = 0; i < n; i++){
			if(num[i][j] == 1){
				cnt1++;
				v = 0;
				for(int t = 0; t < min(k,n-i+1); t++){
					v += num[i+t][j];
				}
				if(v > maxv[j]){
					maxv[j] = v;
					replace[j] = cnt1 - 1;
				}
			}
		}
	}
	int rep = 0;
	int totalscore = 0;
	for(int j = 0; j < m; j++){
		rep += replace[j];
		totalscore += maxv[j];
	}
	printf("%d %d", totalscore, rep);
}