#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int on[1005], score, n;

void play(vector<int> &v) {
    for(auto x : v) {
        if(!on[x])
            score++;
        on[x] = 1;
    }
    cout << v.size() << ' ';
    for(auto x : v)
        cout << x << ' ';
    cout << '\n' << flush;
    int res;
    cin >> res;
    if(res == -1)
        exit(0);
    for(int i = 0; i < v.size(); i++) {
        if(on[res])
            score--;
        on[res] = 0;
        res++;
        if(res > n)
            res -= n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    if(n <= 3) {
        cout << "0\n" << flush;
        return 0;
    }

    int bestk = 1, mx = 0;
    for(int k = 2; k <= n; k++) {
        int fullgp = n / k;
        int rem = n - k * fullgp;
        int res = (k - 1) * (fullgp - 1);
        if(rem > 0)
            res += rem - 1;
        if(res > mx) {
            mx = res;
            bestk = k;
        }
    }

    vector<int> targets;

    for(int i = 1; i <= n; i += bestk) {
        for(int j = i; j < min(i + bestk - 1, n + 1); j++) {
            targets.push_back(j);
        }
    }

    /*for(auto x : targets)
        cout << x << " ";
    cout << endl;*/

    while(score < mx) {
        vector<int> move;
        for(auto t : targets) {
            if(move.size() == bestk)
                break;
            if(on[t])
                continue;
            move.push_back(t);
        }
        play(move);
    }

    cout << "0\n" << flush;
}