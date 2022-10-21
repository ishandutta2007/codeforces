#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, QU = (int)1e9 + (int)1e7;

int n, k;
int num[N];
int res[N];

vector<int> solve(vector<int> &a) {
    int len = a.size();
    vector<int> res;
    int la = -1, cnt = 0;
    for(int i = 0; i <= len; i++) {
        if(i == len || a[i] != QU) {
            int l = la == -1 ? -QU : a[la];
            int r = i == len ? QU : a[i];
            if(cnt > r - l - 1) {
                cout << "Incorrect sequence" << "\n";
                exit(0);
            }
            if(cnt > 0) {
                int cur = max(l + 1, -cnt / 2);
                if(cur + cnt - 1 > r - 1) {
                    int dif = cur + cnt - 1 - (r - 1);
                    cur -= dif;
                }
                for(int j = cur; j < cur + cnt; j++) res.push_back(j);
            }

            if(i == len) break;
            cnt = 0;
            res.push_back(a[i]);
            la = i;
        }
        else {
            cnt++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str[0] == '?') num[i] = QU;
        else num[i] = stoi(str);
    }
    for(int st = 0; st < k; st++) {
        vector<int> cur;
        for(int i = st; i < n; i += k) cur.push_back(num[i]);
        vector<int> cres = solve(cur);
        int pt = 0;
        for(int i = st; i < n; i += k) res[i] = cres[pt++];
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";

}