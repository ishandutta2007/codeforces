#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

int q, m;
priority_queue<pair<int,int>> a, b;
bool vis[maxn];

int main() {
	int q; scanf("%d",&q);
	for(int i=1;i<=q;i++) {
		int type; scanf("%d",&type);
		if(type == 1) {
			int val; scanf("%d",&val);
			m++;
			a.push({-m, val});
			b.push({val, -m});
		}
		if(type == 2) {
			while(!a.empty()) {
				int x = -a.top().first; a.pop();
				if(vis[x]) continue;
				vis[x] = 1;
				printf("%d ",x);
				break;
			}
		}
		if(type == 3) {
			int x;
			while(!b.empty()) {
				int x = -b.top().second; b.pop();
				if(vis[x]) continue;
				vis[x] = 1;
				printf("%d ",x);
				break;
			}
		}

	}
}