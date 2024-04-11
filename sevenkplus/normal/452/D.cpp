#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int k, n1, n2, n3, t1, t2, t3;

int main()
{
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	queue<int> a1,a2,a3;
	int t = 0;
	int S = 0;
	for (int i = 0; i < k; i ++) {
		while (true) {
			while (!a1.empty() && a1.front()+t1 <= t) a1.pop();
			while (!a2.empty() && a2.front()+t2 <= t) a2.pop();
			while (!a3.empty() && a3.front()+t3 <= t) a3.pop();
			if ((int)a1.size() < n1 && (int)a2.size() < n2 && (int)a3.size() < n3) {
				a1.push(t);
				a2.push(t);
				a3.push(t);
				S = t+t1+t2+t3;
				break;
			}
			int nt = t+1;
			if ((int)a1.size() == n1) nt = max(nt, a1.front()+t1);
			if ((int)a2.size() == n2) nt = max(nt, a2.front()+t2);
			if ((int)a3.size() == n3) nt = max(nt, a3.front()+t3);
			t = nt;
		}
	}
	cout << S << endl;
	return 0;
}