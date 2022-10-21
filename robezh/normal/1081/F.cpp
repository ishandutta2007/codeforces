#include <bits/stdc++.h>
using namespace std;

const int N = 305;
typedef pair<int, int> P;

int q_left = 99999;
int T;
int n, t;
int nt;
int res[N];

P ask(int i, int j) {
    int c[2] = {0, 0};
    int len[2] = {j, n - i + 1};
    if(j % 2 == 1) swap(len[0], len[1]);
    assert(len[0] % 2 == 0);
    int x[2] = {-1, -1};
    while(true) {
        if(x[0] != -1 && x[1] != -1 && c[0] % 2 == 0 && c[1] % 2 == 0) break;
        cout << "? " << i << " " << j << "\n";
        fflush(stdout);
        cin >> nt;
        q_left --;
        if(q_left < 0) exit(1);
        int rem = ((nt - t) % 2 + 2) % 2;
        c[rem] ++;
        if(c[1-rem] % 2 == 0){
            if(c[rem] % 2 == 0) x[rem] = (len[rem] + nt - t) / 2;
            else x[rem] = (len[rem] + t - nt) / 2;
//            cout << rem << " is assign to " << x[rem] << endl;
        }
        t = nt;
    }
    assert(T == t);
    if(j % 2 == 1) swap(x[0], x[1]);
    return {x[0], x[1]};
}

void answer(){
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << res[i];
    cout << "\n";
    fflush(stdout);
}

int main() {
    cin >> n >> t;
    T = t;
    if(n == 1) {
        res[1] = t;
        answer();
    }
    else if(n % 2 == 0) {
        for(int i = 1; i <= n; i++){
            auto p = ask(i, i);
            res[i] = p.first + p.second - t;
        }
        answer();
    }
    else {
        auto p = ask(2, n);
        res[1] = t - p.second;
        for(int i = 1; i <= n - 1; i++) {
            auto p1 = ask(i, i+1);
            res[i+1] = p1.first + p1.second - t - res[i];
        }
        answer();
    }
}