// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 4e6 + 10;

bool B = false;
pll v;
int t, c = 1, mv = 0;

inline void NextTest();

inline void move(pll e) {
	if (mv >= 130) assert(false);
	cout << e.X << sep << e.Y << endl;
	v = e;
	string s;
	cin >> s;
	if (s != "Up" && s != "Down") B = !B;
	if (s == "Done") {
		c++;
		NextTest();
	}

	mv++;
}

inline void Next() {
	if (v.X != 1 && v.X != 8) move({1, v.Y});
	if (v.X == 8) {
		while (v.X > 1 && !B) {
			v.X--;
			move(v);
		}

		v.Y++;
		move(v);
	} else {
		while (v.X < 8 && !B) {
			v.X++;
			move(v);
		}

		v.Y++;
		move(v);
	}

	B = !B;
}

inline void NextTest() {	
	mv = 0;
	if (c > t) exit(0);
	v = {1, 1};
	move(v);

	while (v.Y < 8) Next();
	v.Y = 1;
	move(v);
	if (v.X != 1 && v.X != 8) {
		v.X = 1;
		move(v);
	}

	while (v.Y < 8) Next();
}

int main() {
	cin >> t;
	NextTest();
	return 0;
}