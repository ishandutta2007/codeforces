#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll INF = 1e18 + 1;

template<typename T> struct BIT{
    int S;
    vector<T> v;

    BIT<T>(int _S){
        S = _S;
        v.resize(S+1);
    }
    
    void update(int i, T k){
        for(i++; i<=S; i+=i&-i) {
            v[i] = v[i] + k;
            if (v[i] > INF) v[i] = INF;
        }
    }

    T read(int i){
        T sum = 0;
        for(i++; i; i-=i&-i) {
            sum = sum + v[i];
            if (sum > INF) sum = INF;
        }
        return sum;
    }

    T read(int l, int r){
        return read(r) - read(l-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    ll ours, tmp;
    cin >> ours >> tmp;

    vector<ll> events({0});

    N--;
    vector<array<ll, 2>> teams(N);
    for (int i = 0; i < N; i++) {
        cin >> teams[i][0] >> teams[i][1];
        events.push_back(teams[i][0]);
    }

    sort(all(events));
    reverse(all(events));

    sort(all(teams), [&](array<ll, 2> &a, array<ll, 2> &b) {
        return a[0] < b[0]; 
    });

    vector<int> __inx(N);
    for (int i = 0; i < N; i++)
        __inx[i] = i;
    sort(all(__inx), [&](int a, int b) {
        return (teams[a][1] - teams[a][0] + 1)
             < (teams[b][1] - teams[b][0] + 1);
    });

    TRACE( 
            for (auto t : teams)
                cout << t[0] << " " << t[1] << endl;
    );

    vector<int> inx(N);
    for (int i = 0; i < N; i++)
        inx[__inx[i]] = i;

    WATCHC(inx);

    BIT<int> pres(N);
    BIT<ll> cost(N);

    int ans = N;

    int t = teams.size() - 1;
    for (ll pos : events) {
        WATCH(pos);
        while (t >= 0 && teams[t][0] > pos) {
            pres.update(inx[t], 1);
            cost.update(inx[t], teams[t][1] - teams[t][0] + 1);
            t--;
        }

        if (pos > ours) continue;

        int beat = N - t - 1;

        int cov = -1;
        int lo = 0, hi = N - 1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (cost.read(0, mi) <= (ours - pos)) {
                cov = mi;
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }

        if (cov != -1)
            beat -= pres.read(0, cov);
        ans = min(ans, beat);
    }

    cout << ans + 1 << "\n";
    return 0;
}