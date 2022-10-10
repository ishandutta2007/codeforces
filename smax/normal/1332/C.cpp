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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int ret = 0;
        for (int i=0; i<(k+1)/2; i++) {
            int tot = 0;
            vector<int> freq(26);
            for (int j=i; j<n; j+=k)
                freq[s[j]-'a']++, tot++;
            if (i != k - i - 1)
                for (int j=k-i-1; j<n; j+=k)
                    freq[s[j]-'a']++, tot++;

            ret += tot - *max_element(freq.begin(), freq.end());
        }

        cout << ret << "\n";
    }

    return 0;
}