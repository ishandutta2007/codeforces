#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define INF 2000000005
LL cost[8], C1, C2, C3, C4, C5, C6;
LL dr[] = {1, 1, 1, 0, -1, -1, -1, 0};
LL dc[] = {1, 0, -1, -1, -1, 0, 1, 1};

typedef long long LL;
typedef pair<LL, LL> pii;
map<pii, LL> mp;
queue<LL> Q;

void doit() {
	while(!Q.empty()) Q.pop();
	
//	Q.push(0); Q.push(0); Q.push(0);
	for(LL i = 0; i < 8; i ++) {
		Q.push(dr[i]); Q.push(dc[i]);
		Q.push(cost[i]);
	}
	while(!Q.empty()) {
		LL r = Q.front(); Q.pop();
		LL c = Q.front(); Q.pop();
		LL d = Q.front(); Q.pop();
		for(LL i = 0; i < 8; i ++) {
			LL rr = r + dr[i], cc = c + dc[i];
			LL dd = d + cost[i];
			if(rr == 0 && cc == 0) continue;
			if(rr < -1 || cc < -1 || rr > 1 || cc > 1) continue;
//			cout << r << ' ' << c << ' ' << rr << ' ' << cc << endl;
			LL id = mp[pii(rr, cc)];
//			cout << id << ' ' << cost[id] << ' ' << dd << endl;
			if(cost[id] > dd) {
				cost[id] = dd;
				Q.push(rr); Q.push(cc); Q.push(dd);
			}
		}
	}	
}

int main() {
//	freopen("in.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	mp.clear();
	for(LL i = 0; i < 8; i ++) mp[pii(dr[i], dc[i])] = i;

	LL Tc; cin >> Tc;
	while(Tc --) {
		LL X, Y; cin >> X >> Y >> C1 >> C2 >> C3 >> C4 >> C5 >> C6;
		cost[0] = C1, cost[1] = C6, cost[2] = INF, cost[3] = C5;
		cost[4] = C4, cost[5] = C3, cost[6] = INF, cost[7] = C2;
		
		doit();
	//	for(int i = 0; i < 8; i ++) cout << i << ' ' << cost[i] << endl;
		LL ans = 0;
		if(X >= 0 && Y >= 0) {
			ans += min(X, Y) * cost[0];
			if(X < Y) ans += (Y - X) * cost[7];
			else ans += (X - Y) * cost[1];
		}
		else if(X >= 0 && Y <= 0) {
			Y = -Y;
			ans += min(X, Y) * cost[2];
			if(X < Y) ans += (Y - X) * cost[3];
			else ans += (X - Y) * cost[1];
		}
		else if(X <= 0 && Y <= 0) {
			X = -X, Y = -Y;
			ans += min(X, Y) * cost[4];
			if(X < Y) ans += (Y - X) * cost[3];
			else ans += (X - Y) * cost[5];
		}
		else {
			X = -X;
			ans += min(X, Y) * cost[6];
			if(X < Y) ans += (Y - X) * cost[7];
			else ans += (X - Y) * cost[5];
		}
		cout << ans << endl;
	}
	
	return 0;
}