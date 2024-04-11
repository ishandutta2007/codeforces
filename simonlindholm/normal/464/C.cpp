#include <iostream>
#include <vector>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
	cin.sync_with_stdio(false);
	string start;
	cin >> start;
	int N;
	cin >> N;
	vector<int> qfrom(N);
	vector<string> qto(N);
	for (int i = 0; i < N; ++i) {
		cin >> qfrom[i];
		cin.ignore(2);
		getline(cin, qto[i]);
	}

	vector<long long> dval(10), dmult(10);
	for (int i = 0; i < 10; ++i) {
		dval[i] = i;
		dmult[i] = 10;
	}
	for (int i = N; i --> 0; ) {
		int affected = qfrom[i];
		const string& to = qto[i];
		long long ndval = 0;
		long long ndmult = 1;
		for (int j = (int)to.size(); j --> 0; ) {
			int d = to[j] - '0';
			ndval += (ndmult * dval[d]) % MOD;
			ndmult *= dmult[d];
			ndmult %= MOD;
		}
		ndval %= MOD;
		dval[affected] = ndval;
		dmult[affected] = ndmult;
	}
	long long ndval = 0;
	long long ndmult = 1;
	for (int j = (int)start.size(); j --> 0; ) {
		int d = start[j] - '0';
		ndval += (ndmult * dval[d]) % MOD;
		ndmult *= dmult[d];
		ndmult %= MOD;
	}
	ndval %= MOD;
	cout << ndval << endl;
	return 0;
}