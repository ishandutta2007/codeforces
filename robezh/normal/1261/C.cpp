#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50;

int n, m;
string s[N];
vector<vector<int> > sum;
vector<vector<int> > mp;
vector<vector<int> > mpsum;

int find_rec_sum(vector<vector<int> > &arr, int i1, int j1, int i2, int j2) {
    return arr[i2][j2] - (i1 - 1 >= 0 ? arr[i1-1][j2] : 0) - (j1 - 1 >= 0 ? arr[i2][j1-1] : 0)
        + (i1 - 1 >= 0 && j1 - 1 >= 0 ? arr[i1-1][j1-1] : 0);
}

bool check(int T) {
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mp[i][j] = 0;

    for(int i = T; i + T < n; i++) for(int j = T; j + T < m; j++) {
        if(find_rec_sum(sum, i - T, j - T, i + T, j + T) == 1LL * (2 * T + 1) * (2 * T + 1)) mp[i][j] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mpsum[i][j] = mp[i][j];
            if(i > 0) mpsum[i][j] += mpsum[i-1][j];
            if(j > 0) mpsum[i][j] += mpsum[i][j-1];
            if(i > 0 && j > 0) mpsum[i][j] -= mpsum[i-1][j-1];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'X' && find_rec_sum(mpsum, max(0, i - T), max(0, j - T),
                    min(n - 1, i + T), min(m - 1, j + T)) == 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    sum.resize(n, vector<int>(m, 0));
    mp.resize(n, vector<int>(m, 0));
    mpsum.resize(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum[i][j] = (s[i][j] == 'X');
            if(i > 0) sum[i][j] += sum[i-1][j];
            if(j > 0) sum[i][j] += sum[i][j-1];
            if(i > 0 && j > 0) sum[i][j] -= sum[i-1][j-1];
        }
    }

    int l = 0, r = (int)5e5 + 5, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
//    int l = 1;
    check(l);
    cout << l << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << (mp[i][j] ? 'X' : '.');
        }
        cout << "\n";
    }


}