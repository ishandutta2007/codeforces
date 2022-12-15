#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5 + 7;
const long long kInf = LONG_LONG_MAX;

int n[3];
long long a[3][kN];
long long tmp[kN];

long long get_answer_for_numbers(long long x, long long y, long long z){
	return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
}

long long get_answer(){
	for(int i = 0; i < 3; ++i)
		sort(a[i], a[i] + n[i]);

	long long answer = kInf;
	int idx[3];

	for(int mid = 0; mid < 3; ++mid){
		for(int mx = 0; mx < 3; ++mx){
			if(mid == mx)
				continue;

			int mn = 3 ^ mid ^ mx;
			for(int i = 0; i < 3; ++i)
				idx[i] = 0;

			for(idx[mid] = 0; idx[mid] < n[mid]; ++idx[mid]){
				if(a[mn][idx[mn]] > a[mid][idx[mid]])
					continue;

				while(idx[mn] != n[mn] && a[mn][idx[mn]] <= a[mid][idx[mid]])
					++idx[mn];
				--idx[mn];

				while(idx[mx] != n[mx] && a[mx][idx[mx]] < a[mid][idx[mid]])
					++idx[mx];

				if(idx[mx] == n[mx])
					break;

				answer = min(answer, get_answer_for_numbers(a[mn][idx[mn]], a[mid][idx[mid]], a[mx][idx[mx]]));
			}
		}
	}

	return answer;
}

void read(){
	for(int i = 0; i < 3; ++i)
		cin >> n[i];

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < n[i]; ++j)
			cin >> a[i][j];
}

void solve_test(){
	read();
	cout << get_answer() << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve_test();
}