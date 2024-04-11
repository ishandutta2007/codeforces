#include<bits/stdc++.h>
using namespace std;

int cnt[101010];
int sum = 0, cnt4 = 0;

void change(int i, int delta) {
    sum -= cnt[i] / 2;
    if (cnt[i] >= 4)
        cnt4--;
    cnt[i] += delta;
    sum += cnt[i] / 2;
    if (cnt[i] >= 4)
        cnt4++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        change(a, 1);
    }
    int q;
    cin >> q;
    while (q--) {
        string type;
        int x;
        cin >> type >> x;
        change(x, type == "+" ? 1 : -1);
        cout << (sum >= 4 && cnt4 > 0 ? "YES\n" : "NO\n");
    }
    return 0;
}