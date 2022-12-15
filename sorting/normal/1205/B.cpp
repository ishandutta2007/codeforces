#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5 + 7;
const long long BITS = 63;
const long long inf = 1e9;

long long a[MAXN], par[MAXN];
bool used[MAXN];
long long dist[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 0; i < n; ++i){
		cin >> a[i];
		if(!a[i]){
			n--;
			i--;
		}
	}

	for(long long to = 0; to < BITS; ++to){
		long long cnt = 0;
		for(long long i = 0; i < n; ++i){
			if(a[i] & (long long)(1ll << to)){
				++cnt;
				if(cnt >= 3){
					cout << "3\n";
					return 0;
				}
			}
		}
	}

	long long ans = inf;

	for(long long i = 0; i < n; ++i){
		for(long long to = 0; to < n; ++to){
			used[to] = false;
			dist[to] = inf;
			par[to] = -1;
 		}

		queue<long long> q;

		q.push(i);
		dist[i] = 0;
		used[i] = true;

		while(!q.empty()){
			long long x = q.front();
			q.pop();

			for(long long to = 0ll; to < n; ++to){
				if(to == x){
					continue;
				}

				if((a[x] & a[to])){
					if(!used[to]){
						dist[to] = dist[x] + 1;
						used[to] = true;
						q.push(to);
						par[to] = x;
					}
					else{
						if(par[x] != to){
							ans = min(dist[x] + dist[to] + 1ll, ans);
						}
					}
				}
			}
		}
	}

	if(ans == inf){
		ans = -1;
	}

	cout << ans << "\n";

	return 0;
}