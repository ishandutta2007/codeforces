//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 205; 

int n, m, a[5][N];
tuple<int, int> s[N], t[N];
vector<tuple<int, int, int> > ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
tuple<int, int> getNext(const tuple<int, int>& pos) {
	int x = get<0>(pos), y = get<1>(pos);
	if(x == 2) {
		if(y == n) return make_tuple(3, n);
		return make_tuple(2, y+1);
	}
	if(y == 1) return make_tuple(2, 1);
	return make_tuple(3, y-1);
}
bool isEmpty(const tuple<int, int>& pos) {
	return !a[get<0>(pos)][get<1>(pos)];
}
bool checkPark(const int& id) {
	if(abs(get<0>(s[id])-get<0>(t[id])) == 1 && get<1>(s[id]) == get<1>(t[id])) {
		ans.push_back(make_tuple(id, get<0>(t[id]), get<1>(t[id])));
		a[get<0>(s[id])][get<1>(s[id])] = a[get<0>(t[id])][get<1>(t[id])] = 0;
		return 1;
	}
	return 0;
}
bool rotateR() {
	bool ok = 0;
	rep(i, 2, 3) {
		rep(j, 1, n) {
			if(!a[i][j]) continue;
			tuple<int, int> nxt = getNext(make_tuple(i, j));
			if(checkPark(a[i][j])) ok = 1;
			else if(isEmpty(nxt)) {
				int id = a[i][j];
				ans.push_back(make_tuple(id, get<0>(nxt), get<1>(nxt)));
				a[i][j] = 0;
				a[get<0>(nxt)][get<1>(nxt)] = id;
				s[id] = nxt;
				ok = 1;
			}
		}
	}
	return ok;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, 4) rep(j, 1, n) {
		scanf("%d", &a[i][j]);
		if(a[i][j]) {
			if(i == 1 || i == 4) t[a[i][j]] = make_tuple(i, j);
			else s[a[i][j]] = make_tuple(i, j);
		}
	}
	while(rotateR())
		;
	bool tag = 1;
	rep(i, 1, 4) {
		rep(j, 1, n) if(a[i][j]) {tag = 0; break;}
		if(!tag) break;
	}
	if(!tag) puts("-1");
	else {
		int sz = ans.size();
		printf("%d\n", sz);
		for(auto p : ans) printf("%d %d %d\n", get<0>(p), get<1>(p), get<2>(p));
	}
	return 0;
}