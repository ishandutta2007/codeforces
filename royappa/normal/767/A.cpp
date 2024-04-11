#include <bits/stdc++.h>

//http://codeforces.com/contest/767/problem/0

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;

int main()
{
	int n;
	cin >> n;
	vector<int> v, r;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	priority_queue<int> q;
	int numPrinted = 0;
	for (int i = 0; i < n; i++) {
		q.push(v[i]);
		bool first = true;
		while (q.size() > 0 && q.top() >= n-numPrinted) {
			if (!first) cout << " "; first = false;
			cout << q.top();
			q.pop();
			numPrinted++;
		}
		cout << endl;
	}
	exit(0);
}