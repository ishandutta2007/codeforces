#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M, L, R, ans;
int x1[60], x2[60], y1[60], y2[60];
int C[300][300];
int P[300];
bool visit[300];
queue<pii> Q;

vector<int> xcom, ycom;

int main(){
	scanf("%d %d", &N, &M);
	for (int i=1; i<=M; i++){
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		xcom.push_back(x1[i]);
		xcom.push_back(x2[i]+1);
		ycom.push_back(y1[i]);
		ycom.push_back(y2[i]+1);
	}
	sort(xcom.begin(), xcom.end());
	xcom.erase(unique(xcom.begin(), xcom.end()), xcom.end());
	sort(ycom.begin(), ycom.end());
	ycom.erase(unique(ycom.begin(), ycom.end()), ycom.end());
	L = xcom.size(), R = ycom.size();
	for (int i=1; i<=M; i++){
		int p = lower_bound(xcom.begin(), xcom.end(), x2[i]+1)-xcom.begin()+1;
		for (int x = lower_bound(xcom.begin(), xcom.end(), x1[i])-xcom.begin()+1; x<p; x++){
			int q = lower_bound(ycom.begin(), ycom.end(), y2[i]+1)-ycom.begin()+1;
			for (int y = lower_bound(ycom.begin(), ycom.end(), y1[i])-ycom.begin()+1; y<q; y++){
				C[x][L+y] = 1000000010; 
			}
		}
	}
	for (int i=1; i<L; i++) C[0][i] = xcom[i] - xcom[i-1];
	for (int i=1; i<R; i++) C[L+i][L+R+1] = ycom[i] - ycom[i-1];
	while (1){
		while (!Q.empty()) Q.pop();
		memset(P, 0, sizeof P);
		memset(visit, 0, sizeof visit);
		Q.push(pii(0, 1000000010));
		bool tf = true;
		while (!Q.empty()){
			pii u = Q.front();
			Q.pop();
			if (u.first == L+R+1){
				ans += u.second;
				for (int x = u.first; x; x=P[x]){
					C[P[x]][x] -= u.second;
					C[x][P[x]] += u.second; 
				}
				tf = false;
				break;
			}
			
			for (int i=1; i<=L+R+1; i++){
				if (C[u.first][i] <= 0 || visit[i]) continue;
				visit[i] = true;
				P[i] = u.first;
				Q.push(pii(i, min(C[u.first][i], u.second)));
			}
		}
		if (tf) break;
	}
	printf("%d\n", ans);
	return 0;
}