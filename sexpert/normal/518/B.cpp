#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int cnt[255], done[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	for(auto c : t)
		cnt[c]++;
	int y = 0, w = 0;
	for(int i = 0; i < s.size(); i++) {
		if(cnt[s[i]]) {
			cnt[s[i]]--;
			done[i] = 1;
			y++;
		}
	}
	for(int x = 'a'; x <= 'z'; x++)
		cnt[x] += cnt[x - 'a' + 'A'];
	for(int i = 0; i < s.size(); i++) {
		if(done[i])
			continue;
		int c = s[i];
		if(c >= 'A' && c <= 'Z')
			c = c + 'a' - 'A';
		if(cnt[c]) {
			cnt[c]--;
			w++;
		}
	}
	cout << y << " " << w << endl;
}