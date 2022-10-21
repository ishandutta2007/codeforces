#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e3 + 50;

struct Pt {
    int x, y;
} p[N];

int trans(int x, int d) {
    return (x - (x % d + d) % d) / d;
}

void answer(vector<int> res) {
    cout << res.size() << '\n';
    for(int x : res) cout << x + 1 << " ";
    cout << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> res;
    int g = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        if(i != 0) {
            g = __gcd(p[i].x - p[0].x, g);
            g = __gcd(p[i].y - p[0].y, g);
        }
    }
    g = abs(g);
    int pw = 1;
    while(g % (pw * 2) == 0) {
        pw *= 2;
    }
    for(int i = 0; i < n; i++) {
        p[i].x = trans(p[i].x, pw);
        p[i].y = trans(p[i].y, pw);
    }
    for(int i = 0; i < n; i++) {
        if((p[i].x + p[i].y) % 2 == 0) res.push_back(i);
    }
    if(!res.empty() && res.size() < n) {
        answer(res);
    }
    res.clear();
    for(int i = 0; i < n; i++) {
        if((p[i].x - p[0].x) % 2 == 0) res.push_back(i);
    }
    answer(res);

}