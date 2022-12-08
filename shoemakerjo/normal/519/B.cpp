#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> first;
	int cur;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if (first.count(cur) > 0) {
			first[cur] = first[cur]+1;
		}
		else first[cur] = 1;
	}
	map<int, int> second;
	for (int i = 0; i < n-1; ++i) {
		cin >> cur;
		if (second.count(cur) > 0) {
			second[cur] = second[cur]+1;
		}
		else
			second[cur] = 1;
	}


	map<int, int> third;
		for (int i = 0; i < n-2; ++i) {
			cin >> cur;
			if (third.count(cur) > 0) {
				third[cur] = third[cur]+1;
			}
			else
				third[cur] = 1;
		}
	for (map<int, int>::iterator it = first.begin(); it != first.end(); ++it) {
		int cur = it->first;
		if (second.count(cur) == 0 || second[cur]!=first[cur]) {
			cout << cur << endl;
			break;
		}
	}

	for (map<int, int>::iterator it = second.begin(); it != second.end(); ++it) {
		int cur = it->first;
		if (third.count(cur) == 0 || second[cur]!=third[cur]) {
			cout << cur << endl;
			break;
		}
	}

}