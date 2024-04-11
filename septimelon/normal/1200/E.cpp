#include <bits/stdc++.h>

using namespace std;

int prefix(string s) {
	int n = s.length();
	vector<int> pr(n);
	for (int i = 1; i < n; i++) {
		int j = pr[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pr[j - 1];
		if (s[i] == s[j])
            j++;
		pr[i] = j;
	}
	return pr[pr.size()-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    int n, l2, pref;
    cin >> n;
    cin >> s1;
    for (int q = 1; q < n; q++) {
        cin >> s2;
        l2 = s2.length();
        s2 += '&';
        if (s1.length() > l2) {
            for (int i = s1.length() - l2; i < s1.length(); i++)
                s2 += s1[i];
        }
        else {
            s2 += s1;
        }
        pref = prefix(s2);
        for (int i = pref; i < l2; i++)
            s1 += s2[i];
    }
    cout << s1 << endl;
    return 0;
}