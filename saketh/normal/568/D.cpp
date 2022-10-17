#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
typedef long long ll;

int N;
int A[MAXN], B[MAXN], C[MAXN];

int suc[MAXN], bef[MAXN];

void rem(int idx) {
    suc[bef[idx]] = suc[idx];
    bef[suc[idx]] = bef[idx];
}

void put(int idx) {
    suc[bef[idx]] = idx;
    bef[suc[idx]] = idx;
}

vector<pair<int, int>> soln;

double start;

bool go(int R, int K) {
    if (K == 0) return R == 0;

    if( R <= K ) {
        for (int idx = suc[0]; idx <= N; idx = suc[idx]) {
            soln.emplace_back(idx, -1);
        }
        return true;
    }

    if (R > 30 * K * K) {
        vector<int> lines;
        for (int idx = suc[0]; idx <= N; idx = suc[idx])
            lines.push_back(idx); 
        assert(lines.size() == R);

        for (int TRY = 0; TRY < 100; TRY++) {
            if ((clock() - start) / CLOCKS_PER_SEC > 1.93) {
                cout << "NO\n";
                exit(0);
            }

            int i1 = rand() % R, i2 = rand() % R;
            if(i1 == i2) continue;

            int par = lines[i1], idx = lines[i2];

            ll det = A[par] * B[idx] - B[par] * A[idx];
            if (det == 0) continue;

            ll x = -C[par] * B[idx] + B[par] * C[idx];
            ll y = -A[par] * C[idx] + C[par] * A[idx];

            vector<int> on;

            for (int road = suc[0]; road <= N; road = suc[road]) {
                ll ev = A[road] * x + B[road] * y;
                if (ev == -C[road] * det) {
                    on.push_back(road);
                    rem(road);
                }
            }

            if (on.size() > K && go(R - on.size(), K - 1)) {
                soln.emplace_back(par, idx);
                return true;
            }

            for (int i = on.size() - 1; i >= 0; i--) 
                put(on[i]);
        }

        return false;
    }

    for (int idx = suc[0], i = 0; i < K + 1; idx = suc[idx], i++) {
        for (int par = suc[0]; par != idx; par = suc[par]) {
            ll det = A[par] * B[idx] - B[par] * A[idx];
            if (det == 0) continue;

            ll x = -C[par] * B[idx] + B[par] * C[idx];
            ll y = -A[par] * C[idx] + C[par] * A[idx];

            vector<int> on;

            for (int road = suc[0]; road <= N; road = suc[road]) {
                ll ev = A[road] * x + B[road] * y;
                if (ev == -C[road] * det) {
                    on.push_back(road);
                    rem(road);
                }
            }

            if (go(R - on.size(), K - 1)) {
                soln.emplace_back(par, idx);
                return true;
            }

            for (int i = on.size() - 1; i >= 0; i--) 
                put(on[i]);
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    start = clock();
    srand(time(NULL));

    int K;
    cin >> N >> K;

    suc[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i];
        suc[i] = i + 1;
        bef[i] = i - 1;
    }
    bef[N+1] = N;

    if (go(N, K)) {
        cout << "YES\n";
        cout << soln.size() << "\n";

        for (pair<int, int> p: soln)
            cout << p.first << " " << p.second << "\n";
    }
    else cout << "NO\n";
}