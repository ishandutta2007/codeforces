#include <bits/stdc++.h>
using namespace std;

int main() {
	string line; cin>>line;
	vector<bool> f(line.size(), false);
	stack<int> s;
	for (int i=0; i<line.size(); i++) {
		if (line[i]=='0') {
			if (!s.empty()) {
				f[s.top()]=true;
				s.pop();
			}
		}
		else
			s.push(i);
	}
	for (int i=0; i<line.size(); i++)
		cout<<(f[i]?'1':'0');
	cout<<endl;
	return 0;
}