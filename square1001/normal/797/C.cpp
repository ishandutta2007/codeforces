#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> last(26, 0);
	for (int i = 0; i < n; ++i) {
		last[s[i] - 'a'] = max(last[s[i] - 'a'], i + 1);
	}
	stack<char> st;
	int ptr = 0;
	string ans;
	for (int i = 0; i < 26; ++i) {
		while (!st.empty() && st.top() <= 'a' + i) ans += st.top(), st.pop();
		for (int j = ptr; j < last[i]; ++j) {
			if (s[j] == 'a' + i) ans += s[j];
			else st.push(s[j]);
		}
		ptr = max(ptr, last[i]);
	}
	while (!st.empty()) ans += st.top(), st.pop();
	cout << ans << endl;
	return 0;
}