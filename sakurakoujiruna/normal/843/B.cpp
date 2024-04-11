#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

int cnt = 0;

pair <int, int> ask(int i) {
	cnt ++; assert(cnt <= 2000);
	printf("? %d\n", i); fflush(stdout);
	int v, nxt; scanf("%d%d", &v, &nxt);
	return {v, nxt};
}

mt19937 myrand(time(0));

int main() {
	
	int n, start, x; cin >> n >> start >> x;
	
	int s = start, v = ask(s).fir;
	for(int i = 0; i < 1000; i ++) {
		int id = myrand() % n + 1;
		auto p = ask(id);
		if(p.fir <= x && p.fir > v) {
			s = id;
			v = p.fir;
		}
	}
	
	if(v < x) v = -1;
	
	for(;;) {
		auto p = ask(s);
		if(p.fir >= x) {
			v = p.fir;
			break;
		}
		
		if(p.sec != -1) s = p.sec;
		else break;
	}
	printf("! %d\n", v); fflush(stdout);
	
	return 0;
}