#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct data{
	int x, id;
	data(int x = 0, int id = 0) : x(x), id(id) {}
};
bool operator < (const data &A, const data &B) {
	return A.x < B.x;
}
struct Ans {
	int u, v;
	Ans(int u = 0, int v = 0) : u(u), v(v) {}
};
vector<Ans> V;
priority_queue<data> Q;
int Tc, N;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int soc, rlt;
	for (cin >> Tc; Tc--; ) {
		rlt = 0;
		V.clear();
		while(!Q.empty()) Q.pop();
		cin >> N;
		for(int i = 0 ; i < N ; i ++) {
			cin >> soc;
			if(!soc) continue;
			Q.push(data(soc, i + 1));
		}
		while(Q.size() >= 2) {
			data tp1 = Q.top(); Q.pop();
			data tp2 = Q.top(); Q.pop();
			tp1.x -= 1;
			tp2.x -= 1;
			V.push_back(Ans(tp1.id, tp2.id));
			if(tp1.x > 0) Q.push(tp1);
			if(tp2.x > 0) Q.push(tp2);
			rlt ++;
		}
		cout << rlt << endl;
		for(auto RES : V) cout << RES.u << ' ' << RES.v << endl;
	}

	return 0;

}