#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int INF = (int)1e9;
int n, r;

P get(int a, int b) {
    int change = n, steps = 0;
    while(a > 1 || b > 1) {
        if(a < b) {
            swap(a, b);
            change--;
        }
        steps += (a - 1) / b;
        a -= (a - 1) / b * b;
    }
    return {change, steps};
}

string get_str(int a, int b) {
    int change = n-1;
    string res = "";
    char cur_c = 'B';
    while(a > 1 || b > 1) {
        if(a < b) {
            swap(a, b);
            cur_c = (cur_c == 'T' ? 'B' : 'T');
        }
        int cnt = (a - 1) / b;
        for(int i = 0; i < cnt; i++) res.push_back(cur_c);
        a -= cnt * b;
    }
    cur_c = (cur_c == 'T' ? 'B' : 'T');
    res.push_back(cur_c);
    reverse(res.begin(), res.end());
    if(res[0] == 'B') for(char &c : res) c = (c == 'T' ? 'B' : 'T');
    return res;
}

int main() {
    cin >> n >> r;
    n--;
    int min_step = INF, k;
    for(int i = 1; i <= r; i++) {
        if(__gcd(i, r) != 1) continue;
        P p = get(i, r);
        if(p.second == n && p.first < min_step) {
            min_step = p.first;
            k = i;
        }
    }
    if(min_step == INF) return cout << "IMPOSSIBLE" << endl, 0;
    cout << min_step << endl;
    cout << get_str(k, r);
}