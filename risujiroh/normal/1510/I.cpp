#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N, M;
const int T = 200;
ll A[105000];
long double precalc[105000];
ll mywrong = 0;
const int LOCAL = 0;
random_device rd;
mt19937 mt(rd());
uniform_real_distribution<> test(0.0, 1.0);

void solve() {
    mywrong = 0;
    ll N, M;
    if(!LOCAL) cin >> N >> M;
    else N = 1000, M = 10000;
    for(int i = 0; i < N; i++) {
        A[i] = 0;
    }
    for(int m = 0; m < M; m++) {
        string S;
        if(!LOCAL) {
            cin >> S;
        } else {
            for(int i = 0; i < N; i++) {
                if(abs(rand())% 2 == 0) S.push_back('0');
                else S.push_back('1');
            }
        }
        long double penalty[2] = {0, 0};
        ll mini = INF;
        for(int i = 0; i < N; i++) chmin(mini, A[i]);
        for(int i = 0; i < N; i++) {
            penalty[(S[i] == '1')] += precalc[A[i] - mini];
        }
        char myans;
        double p = (penalty[0]) / (penalty[0] + penalty[1]);
        if(test(mt) <= p) {
            myans = '0';
        } else {
            myans = '1';
        }
        if(!LOCAL) cout << myans << endl;
        char c;
        if(!LOCAL) {
            cin >> c;
        } else {
            if(abs(rand())% 2 == 0) c = '0';
            else c = '1';
            //c = S[0];
        }
        if(myans != c) mywrong++;
        for(int i = 0; i < N; i++) {
            if(S[i] != c) A[i]++;
        }
    }
    ll b = INF;
    for(int i = 0; i < N; i++) chmin(b, A[i]);
    if(LOCAL) cerr << b << " " << b * 1.3 + 100 << " " << mywrong << endl;
    if(LOCAL) assert(b * 1.3 + 100 >= mywrong);
}

int main() {
    precalc[0] = 1;
    for(int i = 1; i <= 1e5; i++) {
        precalc[i] = precalc[i-1] * 0.5;
    }
    solve();
    return 0;
}