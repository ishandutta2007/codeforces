#include <bits/stdc++.h>
using namespace std;

#define N 505

vector <int> vs[N], clr[N], cls[N], vr[N];
char s[N];
int ans[N][5][5];
int a[2][30], id[30], b[30], up[N][2][5][5];
stack <int> stkr, stks;

bool cmp1(int i, int j){
	return a[0][i] > a[0][j];
}

bool cmp2(int i, int j){
	return a[1][i] > a[1][j];
}

int main(){
//	freopen("00.in", "r" ,stdin);
//	freopen("01.in", "r" ,stdin);
	int n, m, sts, str, i, j, u, v, mx, ups, upr, k;
	scanf("%d %d", &m, &n);
	for(i = 0; i < m; i++){
		scanf("%s", s);
		memset(a, 0, sizeof a);
		for(j = 0; j < n; j++){
			a[j % 2][s[j] - 'a']++;
		}
		for(j = 0; j < 26; j++) id[j] = j;
		sort(id, id + 26, cmp1);
		for(j = 0; j < 4; j++){
			clr[i].push_back(id[j]);
			vr[i].push_back(a[0][id[j]]);
		}
		for(j = 0; j < 26; j++) id[j] = j;
		sort(id, id + 26, cmp2);
		for(j = 0; j < 4; j++){
			cls[i].push_back(id[j]);
			vs[i].push_back(a[1][id[j]]);
		}
	}
//	for(i = 0; i < m; i++){
//		for(j = 0; j < 4; j++) printf("row %d ::::   %c ----- %c\n", i, cls[i][j] + 'a', clr[i][j] + 'a');
//	}
	for(j = 0; j < 4; j++){
		for(k = 0; k < 4; k++){
			if(clr[0][j] == cls[0][k]) ans[0][j][k] = -1;
			else ans[0][j][k] = vr[0][j] + vs[0][k];
		}
	}
	for(i = 1; i < m; i++){
		for(j = 0; j < 4; j++){
			for(k = 0; k < 4; k++){
				if(clr[i][j] == cls[i][k]) ans[i][j][k] = -1;
				else{
					mx = -1;
					for(u = 0; u < 4; u++){
						for(v = 0; v < 4; v++){
							if(ans[i - 1][u][v] == -1) continue;
							if(clr[i - 1][u] == clr[i][j]) continue;
							if(cls[i - 1][v] == cls[i][k]) continue;
							if(mx < ans[i - 1][u][v]){
								mx = ans[i - 1][u][v];
								upr = u; ups = v;
							}
						}
					}
					if(mx == -1) ans[i][j][k] = -1;
					else{
						up[i][1][j][k] = ups;
						up[i][0][j][k] = upr;
						ans[i][j][k] = mx + vr[i][j] + vs[i][k];
					}
				}
			}
		}
	}
	mx = -1;
	for(j = 0; j < 4; j++){
		for(k = 0; k < 4; k++){
			if(mx < ans[m - 1][j][k]){
				mx = ans[m - 1][j][k];
				str = j; sts = k;
			}
		}
	}
	printf("%d\n", m * n - mx);
//	cout << ans[m - 1][0][1] << endl;
//	cout << "sts - " << sts << "  str - " << str << endl;
	stks.push(sts); stkr.push(str);
	for(j = m - 1; j > 0; j--){
		ups = stks.top(); upr = stkr.top();
		sts = up[j][1][upr][ups];
		str = up[j][0][upr][ups];
		stks.push(sts); stkr.push(str);
	}
	for(i = 0; i < m; i++){
		sts = stks.top(); str = stkr.top(); stks.pop(); stkr.pop();
//		cout << sts << "     " << str << endl;
		for(j = 0; j < n / 2; j++) printf("%c%c", clr[i][str] + 'a', cls[i][sts] + 'a');
		if(n % 2) printf("%c", clr[i][str] + 'a');
		puts("");
	}
}