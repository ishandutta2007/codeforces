#include <bits/stdc++.h>
using namespace std;

struct dt {
	long long a, b;
} d[100005];

class num {
	private:
		int m_n[1000];
	public:
		void mutiply(long long x) {
			long long res = 0;
			int i;
			for (i = 0; i < 1000; ++i) {
				res += m_n[i] * x;
				m_n[i] = res % 10;
				res /= 10;
			}
			return;
		}
		void add(num x) {
			int i;
			for (i = 0; i < 1000; ++i) {
				m_n[i] += x.getbit(i);
				if (m_n[i] >= 10) {
					m_n[i] -= 10;
					++m_n[i + 1];
				}
			}
			return;
		}
		void set(long long x) {
			int i = 0;
			memset(m_n, 0, sizeof(m_n));
			while (x) {
				m_n[i] = x % 10;
				++i;
				x /= 10;
			}
			return;
		}
		int getbit(int i) {
			return m_n[i];
		}
		void print() {
			int i = 999;
			while (m_n[i] == 0)
				--i;
			for (; i >= 0; --i) {
				cout << m_n[i];
			}
			return;
		}
		int cmp(num x) {
			int i = 999;
			while (i + 1) {
				if (m_n[i] > x.getbit(i))
					return 1;
				if (m_n[i] < x.getbit(i))
					return -1;
				--i;
			}
			return 0;
		}
};

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, A, B, n, i, maxi;
	num sum, temp;
	cin >> t;
	while (t--) {
		cin >> A >> B >> n;
		for (i = 0; i < n; ++i) {
			cin >> d[i].a;

		}
		for (i = 0; i < n; ++i) {
			cin >> d[i].b;
		}
		maxi = 0;
		for (i = 1; i < n; ++i) {
			if (d[i].a > d[maxi].a)
				maxi = i;
		}
		sum.set(0);
		for (i = 0; i < n; ++i) {
			if (d[i].b % A == 0) {
				temp.set(d[i].b / A * d[i].a);
				sum.add(temp);
			} else {
				temp.set((d[i].b / A + 1) * d[i].a);
				sum.add(temp);
			}
		}
		temp.set(B + d[maxi].a);
		if (temp.cmp(sum) > 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}