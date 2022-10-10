#include <bits/stdc++.h>
using namespace std;

long long cnt[26] = {};
unordered_map<string, long long> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	int n = s.length();
//	vector<int> ranges;
//	char pred = '$';
//	int len = 0;
//	for (int i=0; i<n; i++) {
//        cnt[s[i]-'a']++;
//        if (s[i] != pred) {
//            ranges.push_back(len);
//            pred = s[i];
//            len = 0;
//        }
//        len++;
//	}
//	ranges.push_back(len);
//
//	long long ret = 0;
//	for (int i=0; i<26; i++)
//        ret = max(ret, (long long) cnt[i]);
//	for (int i=0; i<ranges.size(); i++) {
//        ret = max(ret, (long long) ranges[i] * (ranges[i] - 1) / 2);
//        if (i < ranges.size() - 1)
//            ret = max(ret, (long long) ranges[i] * ranges[i+1]);
//	}

    long long ret = 0;
    for (char c : s) {
        for (int i=0; i<26; i++) {
            string t(1, char(i + 'a'));
            t += c;
            mp[t] += cnt[i];
        }
        cnt[c-'a']++;
    }

    for (int i=0; i<26; i++)
        ret = max(ret, cnt[i]);
    for (auto p : mp)
        ret = max(ret, p.second);

	cout << ret << "\n";

	return 0;
}