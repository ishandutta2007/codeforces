#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n, k;
int num[N];
int f[12] = {0, 1, 0, 1, 2, 0, 2, 0, 1, 0, 1, 0};
int g[5] = {0, 1, 2, 0, 1};

int get_sg(int x) {
    if(x < 12) return f[x];
    if(x % 2 == 1) return 0;
    int nxt = get_sg(x / 2);
    if(nxt == 1) return 2;
    return 1;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i];

    if(k % 2 == 0) {
        int sg = 0;
        for(int i = 0; i < n; i++) {
            int cur_sg = (num[i] < 5 ? g[num[i]] : 1 - num[i] % 2);
            sg ^= cur_sg;
        }
        cout << (sg == 0 ? "Nicky" : "Kevin") << endl;
    }
    else {
        int sg = 0;
        for(int i = 0; i < n; i++) sg ^= get_sg(num[i]);
        cout << (sg == 0 ? "Nicky" : "Kevin") << endl;
    }

}