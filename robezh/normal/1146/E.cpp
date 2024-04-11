#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, OFF = (int)1e5 + 25, E5 = (int)1e5;
int n, q;
int num[N];
int pos[N];

struct P {
    int r, neg;
};

struct BIT {
    int n = N;
    int bit[N];
    void add(int x, int val) {
        x += OFF;
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        x += OFF;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res % 2;
    }

    int add(int l, int r, int val) {
        add(l, 1);
        add(r + 1, 1);
    }

} bit;

map<int, P> mp;
//
//void print_out() {
//    cout << "map :" << endl;
//    for(const auto &p : mp) printf("{l: %d, r: %d, neg: %d}\n", p.first, p.second.r, p.second.neg);
//    cout << endl;
//}

void split(int x) {

    if(x <= -E5 || x > E5) return ;
    auto it = --mp.upper_bound(x);
    if(it->first != x) {
        mp[x] = it->second;
        mp[it->first] = {x - 1, it->second.neg};
    }

}

void change(int l, int r, int sign) {
    if(l > r) return ;
    for(auto it = mp.lower_bound(l); it != mp.end() && it->first <= r; it = mp.erase(it)) {
        if(bit.get(it->first) % 2) bit.add(it->first, it->second.r, 1);
    }
    mp[l] = {r, sign};
}

void flip(int l, int r) {
    bit.add(l, r, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> num[i];

    mp[-(int)1e5] = {(int)(1e5), 0};
    while(q--) {
        char c; int x; cin >> c >> x;
        if(c == '>' && x >= 0) {
            split(x+1);
            split(-x);
            change(x+1, E5, 1);
            change(-E5, -x-1, 0);
        }
        else if(c == '<' && x <= 0) {
            split(x);
            split(-x+1);
            change(-E5, x-1, 1);
            change(-x+1, E5, 0);
        }
        else if(c == '>' && x < 0) {
            flip(x+1, -x-1);
            split(x+1);
            split(-x);
            change(-E5, x, 0);
            change(-x, E5, 1);
        }
        else {
            flip(-x+1, x-1);
            split(-x+1);
            split(x);
            change(x, E5, 0);
            change(-E5, -x, 1);
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        for(int i = it->first; i <= it->second.r; i++) {
            int sign = (bit.get(i) % 2) ^ !it->second.neg;
            pos[i+OFF] = sign;
        }
    }
    for(int i = 0; i < n; i++) {
        if(pos[num[i] + OFF]) cout << num[i] << " ";
        else cout << -num[i] << " ";
    }


}