#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

char forbidden[26];
int dp[100001][27];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    int k;
    cin >> s >> k;
    for (int i=0; i<k; i++) {
        string p;
        cin >> p;
        forbidden[p[0]-'a'] = p[1];
        forbidden[p[1]-'a'] = p[0];
    }

    memset(dp, 127, sizeof(dp));
    dp[0][26] = 0;
    for (int i=0; i<s.length(); i++)
        for (int j=0; j<=26; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if (j == 26 || s[i] != forbidden[j])
                dp[i+1][s[i]-'a'] = min(dp[i+1][s[i]-'a'], dp[i][j]);
        }

    cout << *min_element(dp[s.length()], dp[s.length()] + 27) << "\n";

    return 0;
}