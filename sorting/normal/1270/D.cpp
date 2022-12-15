#include <bits/stdc++.h>

using namespace std;

pair<int, int> query(const vector<int> &idx){
	cout << "?";
	for(int x: idx)
		cout << " " << x;
	cout << "\n";
	fflush(stdout);

	pair<int, int> ret;
	cin >> ret.first >> ret.second;
	return ret; 
}

void answer(int x){
	cout << "! " << x << "\n";
	fflush(stdout); 
}

int main(){
	int n, k;
	cin >> n >> k;

	if(k == 1){
		answer(1);
		return 0;
	}

	vector<int> idx;
	for(int i = 1; i <= k; ++i)
		idx.push_back(i);

	pair<int, int> q1 = query(idx);
	int same = 0;
	for(int i = 1; i <= k; ++i){
		if(i == q1.first)
			continue;

		vector<int> idx2;
		for(int j = 1; j <= k + 1; ++j){
			if(j == i)
				continue;
			idx2.push_back(j);
		}

		pair<int, int> q2 = query(idx2);
		if(q2.first == q1.first)
			++same;
	}

	vector<int> idx2;
	for(int i = 1; i <= k + 1; ++i){
		if(i == q1.first)
			continue;

		idx2.push_back(i);
	}

	pair<int, int> q2 = query(idx2);
	if(q2.second < q1.second)
		answer(same + 1);
	else
		answer(k - same);

	return 0;
}