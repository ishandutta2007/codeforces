#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int cur = 1;
	while (v.size() < n) {
		vector<int> temp;
		int tempo = cur;
		while (tempo > 0) {
			temp.push_back(tempo%10);
			tempo/=10;
		}
		for (int i = temp.size()-1; i >= 0; i--) {
			v.push_back(temp[i]);
		}
		cur++;
	}
	cout << v[n-1] << endl;
	// cin >> n;
}