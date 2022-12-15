#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 5e4 + 7;
const long long MAXC = 1e8 + 7;
const long long inf = 1e18 + 3;

array<long long, 4> p[MAXN];
bool used[MAXN];

long long dist(long long x, long long y){
	long long ret = 0;
	for(int i = 0; i < 3; ++i){
		ret += (p[x][i] - p[y][i]) * (p[x][i] - p[y][i]); 
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n; 

	for(long long i = 0; i < n; ++i){
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		p[i][3] = i;
	}
	
	for(long long i = 0; i < n; ++i){
		if(used[i]){
			continue;
		}
		long long best = inf, p;
		for(long long j = 0; j < n; ++j){
			if(used[j] || i == j){
				continue;
			}
			long long d = dist(i, j);
			if(d < best){
				best = d;
				p = j;
			}
		}
		used[i] = true;
		used[p] = true;

		cout << i + 1 << " " << p + 1 << "\n"; 
	}

	return 0;
}