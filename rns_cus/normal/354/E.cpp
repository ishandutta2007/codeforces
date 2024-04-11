#include <bits/stdc++.h>
using namespace std;

#define N 50100

int dp[N][10], cnt, p[110][10], val[110];
bool fg[N];
int T;
long long m;

void pre(){
	for(int i = 0; i <= 6; i ++){
		for(int j = 0; j <= 6 - i; j ++){

			for(int id = 0; id < 6; id ++){
				if(id < i){ p[cnt][id] = 0; continue; }
				if(id < i + j){ p[cnt][id] = 4; val[cnt] += 4;  continue; }
				p[cnt][id] = 7; val[cnt] += 7;
			}

			cnt ++;
		}
	}
///	cout << cnt << endl;

//	for(int i = 0; i < cnt; i ++) printf("%d ", val[i]); puts("");

	fg[0] = 1;

	for(int dit = 1; dit <= 4; dit ++) {
		for(int j = 0; j < N; j ++) if( fg[j] ){
			for(int k = 0; k < cnt; k ++){
				int xx = j * 10 + val[k];
				if(xx >= N || fg[xx]) continue;
				fg[xx] = true;
				for(int t = 0; t < 6; t ++) dp[xx][t] = dp[j][t] * 10 + p[k][t];
			}
		}
	}

}

long long ans[10];

bool can(long long x){
	if(x <= 50000 && fg[x]){
		for(int i = 0; i < 6; i ++) ans[i] = dp[x][i];
		return true;
	}

	if(x < 10000) return false;

	int y = x % 10000;
	x /= 10000;
	for(int i = 0; i <= 4; i ++) if(fg[y + i * 10000]){
		if( can(x - i) ){
			for(int j = 0; j < 6; j ++) ans[j] = ans[j] * 10000 + dp[y + i * 10000][j];
			return true;
		}
	}

	return false;

}

int main() {
//	freopen("a.in", "r", stdin);
	pre();
//	return 0;
	for(scanf("%d", &T); T --;){
		scanf("%I64d", &m);
	///	cout << m << endl;
		if(can(m)){
			for(int i = 0; i < 6; i ++) printf("%I64d ", ans[i]); puts("");
		}
		else puts("-1");
	}
	return 0;
}