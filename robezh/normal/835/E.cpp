#include <bits/stdc++.h>
using namespace std;

const int N = 1005, B = 10;

int n, x, y;
int sum[2][2];
int dif[B];
int res[2];

int ask(vector<int> v) {
    cout << "? ";
    cout << v.size() << " ";
    for(int x : v) cout << x << " ";
    cout << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res == sum[v.size() % 2][1];
}

int ask_one(int b, int val) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(((i >> b) & 1) == val) v.push_back(i + 1);
    }
    if(v.empty()) return 0;
    else return ask(v);
}

int ask_two(int b1, int val1, int b2, int val2) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(((i >> b1) & 1) == val1 && ((i >> b2) & 1) == val2) v.push_back(i + 1);
    }
    if(v.empty()) return 0;
    else return ask(v);
}


int main() {
     cin >> n >> x >> y;
     for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) {
         sum[(i+j) % 2][j] = (i * x) ^ (j * y);
     }

     int difi = -1;
     for(int i = 0; i < B; i++) {
         dif[i] = ask_one(i, 1);
         if(dif[i]) difi = i;
//         cout << dif[i] << endl;
     }
     res[1] |= (1 << difi);
     for(int i = 0; i < B; i++) {
         if(i == difi) continue;
         int cur = ask_two(difi, 0, i, 0);
         if(dif[i]) {
             if(cur) res[1] |= (1 << i);
             else res[0] |= (1 << i);
         }
         else {
             if(!cur) res[0] |= (1 << i), res[1] |= (1 << i);
         }
     }
     if(res[0] > res[1]) swap(res[0], res[1]);
     cout << "! " << res[0] + 1 << " " << res[1] + 1 << endl;
     fflush(stdout);
}