#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;

void solve() {
	int n;
	cin >> n;
	int currv = 1;
	vector<int> seq;
	vector<int> q;
	int change = n % 2;
	int last = -1;
	bool ok = 1;
	rep(i, 0, n) {
		int tmp;
		cin >> tmp;
		if (tmp != last && last != -1) {
			ok = 0;
		}
		else {
			last = tmp;
		}
		q.push_back(tmp);
	}
	if (ok) {
		cout << 1 << endl;
		rep(i, 0, n) {
			cout << 1 << " ";

		}
		cout << endl;
		return;
	}

	if (change == 1) {
		if (q[n - 1] == q[0]) {
			change = 0;
		}
	}
	rep(i, 0, n - 1) {
		seq.push_back(currv);
		if (change == 1) {
			if (q[i] != q[i + 1]) {
				if (currv == 1) {
					currv = 2;
				}
				else {
					currv = 1;
				}
			}
			else {
				change = 0;
			}
		}
		else {
			if (currv == 1) {
				currv = 2;
			}
			else {
				currv = 1;
			}
		}
	}
	seq.push_back(currv);

	if (change == 0) {
		cout << 2 << endl;
		LOG_vec(seq, " ");
	}
	else {
		cout << 3 << endl;
		seq[n - 1] = 3;
		LOG_vec(seq, " ");
	}
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}