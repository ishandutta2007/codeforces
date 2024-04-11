#include <bits/stdc++.h>
using namespace std;

const int LOG = 35;
typedef long long ll;

multiset<int> S[LOG];
bool fat[LOG];
ll psum[LOG];
int cur = 0, tot = 0;
int q;

void add(int x, int type) {
    int sign = 1;
    int cat = 33 - __builtin_clz(x);
    if(fat[cat]) cur--, fat[cat] = false;

    if(type == 1) S[cat].insert(x);
    else S[cat].erase(S[cat].find(x)), sign = -1;

    tot += sign;

    if(2 * psum[cat-1] < *S[cat].begin()) cur++, fat[cat] = true;
    for(int i = cat; i < LOG - 1; i++){
        psum[i] += sign * x;
        if(fat[i+1]) cur--, fat[i+1] = false;
        if(2 * psum[i] < *S[i+1].begin()) cur++, fat[i+1] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> q;
    while(q--) {
        char c; int x;
        cin >> c >> x;
        add(x, c == '+' ? 1 : -1);
        cout << tot - cur << "\n";
    }

}