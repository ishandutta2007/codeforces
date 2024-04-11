#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1007;

long long c[MAXN], dist[MAXN], pos[MAXN];
long long used[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, d, sum = 0;
	cin >> n >> m >> d;

	for(long long i = 0; i < m; ++i){
		cin >> c[i];
		pos[i] = d * (i + 1) + sum;
		sum += c[i] - 1;
	}

	if(n + 1 - sum > (m + 1) * d){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	long long pr = n + 1;
	for(long long i = m - 1; i >= 0; --i){
		if(d * (i + 1) + c[i] - 1 >= pr){
			dist[i] = pos[i] - ((pos[i] + c[i] - 1) - pr + 1); 
		}
		else{
			dist[i] = pos[i];
		}
		pr = dist[i];
	}

	for(long long i = 0; i < m; ++i){
		for(long long j = dist[i]; j < dist[i] + c[i]; ++j){
			used[j] = i + 1;
		}
	}

	for(long long i = 1; i <= n; ++i){
		cout << used[i] << " ";
	}
	cout << "\n";

	return 0;
}