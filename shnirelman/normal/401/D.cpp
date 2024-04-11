#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 19;

map<vector<int>, vector<li>> dp;
li p[N];
int m;

vector<li> get(vector<int> a, bool fir) {
    if(dp.count(a))
        return dp[a];

    int sum = 0;
    for(auto x : a)
        sum += x;

    vector<li> ans(m, 0);

    if(sum == 0) {
        ans[0] = 1;
        return dp[a] = ans;
    }


    for(int i = (fir ? 1 : 0); i < 10; i++) {
        if(a[i] > 0) {
            a[i]--;
            vector<li> res = get(a, false);
            a[i]++;

            for(int j = 0; j < m; j++) {
                ans[(j + p[sum - 1] % m * i) % m] += res[j];
            }

        }
    }

//    cout << "a: ";
//    for(auto x : a)
//        cout << x << ' ';
//    cout<< "ans: ";
//    for(auto x : ans)
//        cout << x << ' ';
//    cout<< endl;

    return dp[a] = ans;
}

int main() {
    p[0] = 1;
    for(int i = 1; i < N; i++)
        p[i] = p[i - 1] * 10;

    string s;
    cin >> s >> m;

    int n = s.length();

    vector<int> a(10, 0);
    for(int i = 0; i < n; i++)
        a[s[i] - '0']++;

    cout << get(a, true)[0] << endl;
}