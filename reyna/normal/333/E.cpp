//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define sqr(a) ((a) * (a))
const int N = 3005;
const int S = 38;
int x[N],y[N],n;
double dis[N][N];
pair<double,pair<int,int> > d[N * N];
int t;
bitset<N> mat[N];
bool check(int i,int j) {
	return (mat[i] & mat[j]).any();
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			dis[i][j] = sqrt(sqr(x[i]-x[j]) + sqr(y[i] - y[j]));
			dis[i][j] /= 2;
			dis[j][i] = dis[i][j];
			d[t++] = {dis[i][j],{i,j}};
		}
	}
	sort(d,d + t);
	reverse(d,d + t);
	for (int i = 0; i < t; ++i) {
		int u = d[i].second.first,v = d[i].second.second;
		if(check(u,v)) {
			cout << setprecision(10) << fixed << d[i].first << endl;
			return 0; 
		}
		mat[u][v] = 1;
		mat[v][u] = 1;
	}
	return 0;
}