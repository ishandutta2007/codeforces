#include <bits/stdc++.h>
using namespace std;

const int N = 5, INF = (int)1e9;

int n, a;
int cnt[N];
int res = 0;

int get1(int x) {
    if(x == 1 || x == 2 || x == 5) return -1;
    return x - x / 3;
}

int get2(int x) {
    if(x == 1) return -1;
    return (x + 2) / 3 * 2;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a; cnt[a] ++;
    }
    int tog = min(cnt[1], cnt[2]);
    cnt[1] -= tog, cnt[2] -= tog;
    cnt[3] += tog;
    res += tog;

    if(cnt[1] == 0 && cnt[2] == 0) cout << res << endl;
    else if(cnt[2] > 0){
        int cur = INF;
        for(int i = 0; i <= min(cnt[2], cnt[4]); i++) {
            int add = get2(cnt[2] - i);
            if(add != -1) cur = min(cur, add + i);
        }
        for(int i = 0; i <= min(cnt[3]/2, cnt[2]); i++) {
            int add = get2(cnt[2] - i);
            if(add != -1) cur = min(cur, add + 2 * i);
        }
        for(int i = 0; i <= min(1, cnt[4]); i++) {
            int add = get2(cnt[2] + i * 2);
            if(add != -1) cur = min(cur, add + 2 * i);
        }
        if(cur == INF) return !printf("-1");
        cout << res + cur << endl;
    }
    else {
        int cur = INF;
        for(int i = 0; i <= min(cnt[3], cnt[1]); i++) {
            int add = get1(cnt[1] - i);
            if(add != -1) cur = min(cur, add + i);
        }
        for(int i = 0; i <= cnt[4]; i++) {
            int add = get1(cnt[1] + i);
//            cout << add + i << endl;
            if(add != -1) cur = min(cur, add);
        }
        if(cur == INF) return !printf("-1");
        cout << res + cur << endl;
    }


}