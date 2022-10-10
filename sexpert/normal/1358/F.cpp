#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> A, B;
const ll LIM = 200000;

void meme() {
    ll cs = 0;
    string res;
    bool good = true;
    auto sorted = [](vector<ll> &v) -> bool {
        for(int i = 1; i < v.size(); i++) {
            if(v[i] <= v[i - 1])
                return false;
        }
        return true;
    };
    while(true) {
        if(B == A)
            break;
        if(!sorted(B)) {
            reverse(B.begin(), B.end());
            res += 'R';
        }
        if(B == A)
            break;
        if(!sorted(B)) {
            good = false;
            break;
        }
        cs++;
        res += 'P';
        adjacent_difference(B.begin(), B.end(), B.begin());
    }
    if(!good) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if(cs <= LIM) {
        cout << "SMALL\n";
        cout << res.size() << '\n';
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
    else {
        cout << "BIG\n";
        cout << cs << '\n';
    }
}

void non_meme() {
    ll cs = 0;
    string res;
    bool good = true;
    while(true) {
        if(A == B)
            break;
        if(B[0] == B[1]) {
            good = false;
            break;
        }
        if(B[0] > B[1]) {
            swap(B[0], B[1]);
            res += 'R';
        }
        if(A == B)
            break;
        if(A[0] == B[0]) {
            if(B[1] < A[1]) {
                good = false;
                break;
            }
            if((B[1]%B[0]) == (A[1]%B[0])) {
                ll df = (B[1] - A[1]) / B[0];
                cs += df;
                if(cs <= LIM) {
                    while(df--)
                        res += 'P';
                }
                break;
            }
        }
        else if(A[1] == B[0]) {
            if(B[1] < A[0]) {
                good = false;
                break;
            }
            if((B[1]%B[0]) == (A[0]%B[0])) {
                ll df = (B[1] - A[0]) / B[0];
                cs += df;
                if(cs <= LIM) {
                    while(df--)
                        res += 'P';
                }
                if(A[0] != A[1])
                    res += 'R';
                break;
            }
        }
        ll df = ((B[1] - 1) / B[0]);
        B[1] -= df * B[0];
        cs += df;
        if(cs <= LIM) {
            while(df--)
                res += 'P';
        }
    }
    if(!good) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if(cs <= LIM) {
        cout << "SMALL\n";
        cout << res.size() << '\n';
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
    else {
        cout << "BIG\n";
        cout << cs << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    A.resize(n);
    B.resize(n);
    for(auto &x : A)
        cin >> x;
    for(auto &x : B)
        cin >> x;
    if(n >= 3)
        meme();
    else
        non_meme();
}