#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long x;
int n, d;
vector<int> a;
vector<short> b;
int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return (int)x;
}
void initAB() {
	int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        b[i] = (i < d);
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main() {
	cin >> n >> d >> x;
	a.resize(n);
	b.resize(n);
	initAB();
	if (d > 1000) {
		set<pair<int, int> > a2;
		for (int c = 0; c < n; ++c) {
			a2.insert(make_pair(-a[c], c));
			for (auto pa : a2) {
				int av = -pa.first;
				int i = pa.second;
				if (b[c - i]) {
					cout << av << '\n';
					goto next;
				}
			}
			cout << 0 << '\n';
next:;
		}
	}
	else {
		vector<int> ones;
		for (int c = 0; c < n; ++c) {
			int best = 0;
			if (b[c])
				ones.push_back(c);
			for (int i : ones) {
				best = max(best, a[c - i]);
			}
			cout << best << '\n';
		}
	}
	flush(cout);
	return 0;
}