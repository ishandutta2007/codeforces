#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 5e5 + 5;
int ct1, ct2, P[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i < MAXN; i++) {
        if(!P[i]) {
            for(int j = 2*i; j < MAXN; j += i)
                P[j] = i;
        }
    }
    P[1] = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1)
            ct1++;
        else
            ct2++;
    }
    int ans = -1, cur, primes;
    vi res;
    for(int n1 = 0; n1 <= min(ct1, 3); n1++) {
        cur = primes = 0;
        for(int i = 0; i < n1; i++) {
            cur++;
            if(!P[cur])
                primes++;
        }
        for(int i = 0; i < ct2; i++) {
            cur += 2;
            if(!P[cur])
                primes++;
        }
        for(int i = 0; i < ct1 - n1; i++) {
            cur++;
            if(!P[cur])
                primes++;
        }
        if(primes > ans) {
            ans = primes;
            res.clear();
            for(int i = 0; i < n1; i++) res.push_back(1);
            for(int i = 0; i < ct2; i++) res.push_back(2);
            for(int i = 0; i < ct1 - n1; i++) res.push_back(1);
        }
    }
    if(ct1 > 0 && ct2 > 0) {
        cur = 3;
        primes = 2;
        for(int i = 0; i < ct2 - 1; i++) {
            cur += 2;
            if(!P[cur])
                primes++;
        }
        for(int i = 0; i < ct1 - 1; i++) {
            cur++;
            if(!P[cur])
                primes++;
        }
        if(primes > ans) {
            res.clear();
            res.push_back(2);
            res.push_back(1);
            for(int i = 0; i < ct2 - 1; i++) res.push_back(2);
            for(int i = 0; i < ct1 - 1; i++) res.push_back(1);
        }
    }
    //cout << ans << '\n';
    for(auto x : res)
        cout << x << " ";
    cout << '\n';
}