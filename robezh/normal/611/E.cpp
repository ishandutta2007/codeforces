#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n;
int a, b, c;
vector<int> num;
multiset<int> S;
int cnt[8];

void del(int a) {
    auto it = S.upper_bound(a);
    if(it != S.begin()) S.erase(--it);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);

    num = {a, b, c, a + b, a + c, b + c, a + b + c};
    sort(num.begin(), num.end());
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x > a + b + c) return cout << "-1" << endl, 0;
        for(int j = 0; j < num.size(); j++) {
            if(x <= num[j]) {
                cnt[j] ++;
                break;
            }
        }
    }
    int res = 0;
    res += cnt[6];
    res += cnt[5] + cnt[4];
    cnt[0] -= min(cnt[5], cnt[0]);
    int take = min(cnt[4], cnt[1]);
    cnt[4] -= take, cnt[1] -= take;
    cnt[0] -= min(cnt[4], cnt[0]);


    if(num[3] == a + b) {
        res += cnt[3];
        int rem = cnt[3];
        cnt[3] = 0;
        for(int i = 2; i >= 0; i--) {
            take = min(cnt[i], rem);
            rem -= take; cnt[i] -= take;
        }
    }
    for(int i = 0; i < 4; i++) for(int j = 0; j < cnt[i]; j++) S.insert(num[i]);
    while(!S.empty()) {
        res++; del(c);
        if(S.empty()) break;
        if(*S.begin() <= b) {
            del(b); del(a);
        }
        else {
            del(a + b);
        }
    }
    cout << res << endl;
}