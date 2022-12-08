#include <bits/stdc++.h>
using namespace std;
#define N n
int n, k;
int main(void) {
	deque<int> d;
	cin >> n >> k; k++;
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp; d.push_back(tmp);
	}
	while (d.size()) {
		if(d.front()<k) d.pop_front();
		else if(d.back() < k) d.pop_back();
		else break;
	}
	cout << N - d.size() << endl;
}