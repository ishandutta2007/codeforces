#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;

long long a[N];
priority_queue<long long> q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long k, n;

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	string s;

	cin >> s;

	long long res = 0;

	for(int i = 0; i < n; i++){
		if(i == 0 || s[i] != s[i-1]){
			for(int j = 0; j < k && !q.empty(); j++){
				long long x = q.top();
				q.pop();

				res += x;
			}
			while(!q.empty()){
				q.pop();
			}
		}

		q.push(a[i]);
	}

	for(int j = 0; j < k && !q.empty(); j++){
		long long x = q.top();
		q.pop();

		res += x;
	}

	cout << res << "\n";

	return 0;
}