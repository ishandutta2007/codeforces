#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int OWO = 300;
int b[MAXN], cnt[MAXN], ans[MAXN], m, q, dq, bad, l, r;
bool upd;
deque<int> deq[MAXN];
map<int, int> dcnt[MAXN];

struct qry {
	int l, r, idx;

	bool operator< (const qry &oth) const {
		if(l/OWO != oth.l/OWO)
			return l/OWO < oth.l/OWO;
		return r < oth.r;
	}
};
vector<qry> queries;

void addr() {
	upd = false;
	r++;
	int x = b[r];
	if(cnt[x] == 0)
		dq++;
	cnt[x]++;
	if(!deq[x].empty()) {
		if(!dcnt[x].count(r - deq[x].back()))
			upd = true;
		dcnt[x][r - deq[x].back()]++;
	}
	deq[x].push_back(r);
	if(dcnt[x].size() == 2 && upd)
		bad++;
}

void subr() {
	upd = false;
	int x = b[r];
	deq[x].pop_back();
	if(!deq[x].empty()) {
		if(dcnt[x][r - deq[x].back()] == 1) {
			dcnt[x].erase(r - deq[x].back());
			upd = true;
		}
		else
			dcnt[x][r - deq[x].back()]--;
	}
	if(cnt[x] == 1)
		dq--;
	cnt[x]--;
	if(dcnt[x].size() == 1 && upd)
		bad--;
	r--;
}

void subl() {
	upd = false;
	l--;
	int x = b[l];
	if(cnt[x] == 0)
		dq++;
	cnt[x]++;
	if(!deq[x].empty()) {
		if(!dcnt[x].count(deq[x].front() - l))
			upd = true;
		dcnt[x][deq[x].front() - l]++;
	}
	deq[x].push_front(l);
	if(dcnt[x].size() == 2 && upd)
		bad++;
}

void addl() {
	upd = false;
	int x = b[l];
	deq[x].pop_front();
	if(!deq[x].empty()) {
		if(dcnt[x][deq[x].front() - l] == 1) {
			dcnt[x].erase(deq[x].front() - l);
			upd = true;
		}
		else
			dcnt[x][deq[x].front() - l]--;
	}
	if(cnt[x] == 1)
		dq--;
	cnt[x]--;
	if(dcnt[x].size() == 1 && upd)
		bad--;
	l++;
}

void solve() {
	sort(queries.begin(), queries.end());
	l = 1;
	r = 0;
	for(auto q : queries) {
		//cout << "[" << q.l << ", " << q.r << "]" << endl;
		while(r < q.r)
			addr();
		while(r > q.r)
			subr();
		while(l < q.l)
			addl();
		while(l > q.l)
			subl();
		ans[q.idx] = dq + (bad == dq);
		//cout << dq << " " << bad << endl;
		/*for(int i = 1; i <= 3; i++) {
			for(auto x : deq[i])
				cout << x << " ";
			cout << endl;
		}*/
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m;
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	cin >> q;
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back({l, r, i});
	}
	solve();
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}