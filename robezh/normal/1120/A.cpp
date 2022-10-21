#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 50;

int m,k,n,s;
int a[N], b[N];
int cnt[N], freq[N];
int cur_cnt = 0;
bool vis[N];
int ql = 0, qr = -1;

void add(int x, int val) {
    cur_cnt -= cnt[x] >= freq[x];
    cnt[x] += val;
    cur_cnt += cnt[x] >= freq[x];
}

void slide(int nl, int nr) {
    while(nr > qr) {
        qr++;
        add(a[qr], 1);
    }
    while(nr < qr) {
        add(a[qr], -1);
        qr--;
    }
    while(nl < ql) {
        ql--;
        add(a[ql], 1);
    }
    while(nl > ql) {
        add(a[ql], -1);
        ql++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> k >> n >> s;
    for(int i = 0; i < m; i++) {
        cin >> a[i]; a[i]--;
    }
    for(int i = 0; i < s; i++) {
        cin >> b[i];
        b[i] --; freq[b[i]] ++;
    }
    for(int i = 0; i < N; i++) if(freq[i] == 0) cur_cnt++;
    for(int i = 0; i < m; i++) {
        slide(i, qr);
        while(qr < m - 1 && cur_cnt < N) slide(i, qr + 1);
        if(cur_cnt == N) {
            if(qr - ql + 1 >= k) {
                int cur_res = ql / k + 1 + (m - 1 - qr) / k;
                if(cur_res >= n) {
                    vector<int> res;
                    int fir = ql % k;
                    for(int j = 0; j < fir; j++) res.push_back(j);
                    memset(cnt, 0, sizeof(cnt));
                    for(int j = ql; j <= qr; j++) {
                        if(cnt[a[j]] < freq[a[j]]) {
                            cnt[a[j]] ++;
                            vis[j] = true;
                        }
                    }
                    int sec = qr - ql + 1 - k;
                    for(int j = ql; j <= qr; j++) {
                        if(!vis[j] && sec > 0) res.push_back(j), sec--;
                    }

                    cout << res.size() << endl;
                    for(int x : res) cout << x + 1 << " ";
                    return 0;
                }
            }
            else {
                int left = ql / k * k;
                int nxt = max(qr, left - 1 + k);
                int cur_res = ql / k + 1 + (m - 1 - nxt) / k;
                if(cur_res >= n) {
                    vector<int> res;
                    if(nxt == qr) {
                        int fir = qr - k - left + 1;
                        for(int j = 0; j < fir; j++) res.push_back(left + j);
                    }
                    cout <<  res.size() << endl;
                    for(int x : res) cout << x + 1 << " ";
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;

}