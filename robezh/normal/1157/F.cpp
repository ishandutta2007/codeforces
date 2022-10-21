#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n;
int cnt[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; cnt[a] ++;
    }
    int res = 0, lb, rb;
    int r;
    for(int i = 1; i <= (int)2e5; ) {
        if(cnt[i] < 2) {
            i++;
            continue;
        }
        int cur_res = 0;
        r = i;
        while(cnt[r] >= 2) {
            cur_res += cnt[r];
            r++;
        }
        cur_res += cnt[i-1] + cnt[r];
        if(cur_res > res) {
            res = cur_res;
            lb = i, rb = r;
        }
        i = r + 1;
    }
    if(res == 0) {
        for(int i = 1; i <= (int)2e5; i++) {
            if(cnt[i] == 1 && cnt[i+1] == 1) {
                cout << 2 << endl;
                cout << i << " " << i + 1 << endl;
                return 0;
            }
        }
        for(int i = 1; i <= (int)2e5; i++) {
            if(cnt[i] == 1) {
                cout << 1 << endl;
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << res << endl;
    if(cnt[lb-1] > 0) cout << lb - 1 << " ";
    for(int i = lb; i < rb; i++) cout << i << " ", cnt[i]--;
    if(cnt[rb] > 0) cout << rb << " ";
    for(int i = rb - 1; i >= lb; i--) {
        while(cnt[i] > 0) cout << i << " ", cnt[i]--;
    }
    cout << endl;

}