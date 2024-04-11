#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 13;
const int A = 26;
const int N = 1013;
const int M = 53;

vector<vector<int>> get(string s) {
//	s += '#';
	int n = s.size();
    vector<vector<int>> go(n + 1, vector<int>(A, -1));

    vector<int> p(n, 0);
    for(int i = 1; i < n; i++) {
		char c = s[i];
		int j = p[i - 1];
//		cout << s << ' ' << i << ' ' << j << endl;
		while(j > 0 && s[j] != c)
			j = p[j - 1];
		if(c == s[j])
			j++;
		p[i] = j;
    }

    for(int i = 0; i <= n; i++) {
		for(int k = 0; k < A; k++) {
			char c = k + 'a';
			int j = i;
			while(j > 0 && s[j] != c)
				j = p[j - 1];
			if(c == s[j])
				j++;
			go[i][k] = j;
		}
    }

    return go;
}

int dp[N][M][M];

int main() {
    string s;
    cin >> s;

    int n = s.size();

    string t1, t2;
    cin >> t1 >> t2;

    auto go1 = get(t1);
    auto go2 = get(t2);

//    for(int i = 0; i <= t1.size(); i++) {
//		for(int j = 0; j < 5; j++)
//			cout << go1[i][j] << ' ';
//		cout << endl;
//    }

    for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= t1.size(); j++) {
			for(int k = 0; k <= t2.size(); k++)
				dp[i][j][k] = -INF;
		}
    }
	dp[0][0][0] = 0;

    for(int i = 0; i < n; i++) {
		for(int j = 0; j <= t1.size(); j++) {
			for(int k = 0; k <= t2.size(); k++) if(dp[i][j][k] > -INF) {
                if(s[i] != '*') {
					int j1 = go1[j][s[i] - 'a'];
					int k1 = go2[k][s[i] - 'a'];
                    dp[i + 1][j1][k1] = max(dp[i + 1][j1][k1], dp[i][j][k] + (j1 == t1.size()) - (k1 == t2.size()));
                } else for(int c = 0; c < A; c++) {
					int j1 = go1[j][c];
					int k1 = go2[k][c];
                    dp[i + 1][j1][k1] = max(dp[i + 1][j1][k1], dp[i][j][k] + (j1 == t1.size()) - (k1 == t2.size()));
                }
			}
		}
    }

    int mx = -INF;
    for(int j = 0; j <= t1.size(); j++)
		for(int k = 0; k <= t2.size(); k++)
			mx = max(mx, dp[n][j][k]);

	cout << mx << endl;
}