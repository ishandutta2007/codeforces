#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
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

template<typename T> struct BIT{
    int S;
    vector<T> v;

    BIT<T>(int _S){
        S = _S;
        v.resize(S+1);
    }
    
    void update(int i, T k){
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i){
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
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
    string steps;
    cin >> N >> steps;

    vi ul(N), dr(N);

    for (int i = 1; i < N; i++) {
        ul[i] = ul[i-1] + (steps[i-1] == 'U');
    }

    for (int i = N - 2; i >= 0; i--) {
        dr[i] = dr[i+1] + (steps[i+1] == 'D');
    }

    vll ans(N);
    vi pl(N), pr(N);

    for (int i = 0; i < N; i++) {
        if (ul[i] > dr[i]) {
            ans[i] = N - i;
            pr[i] = dr[i];
            if (steps[i] == 'D') pl[i] = pr[i] + 1;
            else pl[i] = pr[i];
        }
        else if (ul[i] < dr[i]) {
            ans[i] = i + 1;
            pl[i] = ul[i];
            if (steps[i] == 'U') pr[i] = pl[i] + 1;
            else pr[i] = pl[i];
        } else {
            if (steps[i] == 'U') ans[i] = N - i;
            else ans[i] = i + 1;
            pl[i] = pr[i] = ul[i];
        }
    }

    BIT<ll> ups(N);
    vector<int> uploc;
    for (int i = 0; i < N; i++) {
        if (pl[i]) {
            ans[i] += 2ll * pl[i] * i
                    - 2ll * ups.read(uploc[uploc.size() - pl[i]], i);
        }

        if (steps[i] == 'U') {
            uploc.push_back(i);
            ups.update(i, i);
        }
    }

    BIT<ll> downs(N);
    vector<int> downloc;
    for (int i = N - 1; i >= 0; i--) {
        if (pr[i]) {
            ans[i] += 2ll * downs.read(i, downloc[downloc.size() - pr[i]])
                    - 2ll * pr[i] * i;
        } 

        if (steps[i] == 'D') {
            downloc.push_back(i);
            downs.update(i, i);
        }
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}