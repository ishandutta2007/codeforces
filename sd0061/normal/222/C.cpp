#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 10000000;
const int PN = 664579;

int N;
int minp[MAXN + 1], p[PN];

int initPrime(int n = MAXN) {
    int N = 0;
    memset(minp, -1, sizeof(minp));
    for (int i = 2; i <= n; ++i) {
        if (minp[i] == -1) p[N] = i, minp[i] = N++;
        for (int j = 0; j < N && i * p[j] <= n; ++j) {
            minp[i * p[j]] = j;
            if (i % p[j] == 0) break;
        }
    }
    return N;
}

int n, m;
int a[100000], b[100000];
int cUp[PN], cDown[PN];
vector<int> tUp[PN], tDown[PN];

void gao(int* a, const vector<int>& v, int pr, int t) {
    for (vector<int>::const_iterator i = v.begin(); i != v.end() && t > 0; ++i) {
        for (; a[*i] % pr == 0 && t > 0; a[*i] /= pr, --t);
    }
}

int main() {
    N = initPrime();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = a[i]; j != 1; ) {
            int t = minp[j], pr = p[t];
            for (; j % pr == 0; j /= pr, ++cUp[t]);
            tUp[t].push_back(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        for (int j = b[i]; j != 1; ) {
            int t = minp[j], pr = p[t];
            for (; j % pr == 0; j /= pr, ++cDown[t]);
            tDown[t].push_back(i);
        }
    }
    for (int i = 0; i < N; ++i) {
        int t = min(cUp[i], cDown[i]);
        gao(a, tUp[i], p[i], t);
        gao(b, tDown[i], p[i], t);
    }
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
    }
    for (int i = 0; i < m; ++i) {
        printf("%d%c", b[i], i + 1 == m ? '\n' : ' ');
    }
    return 0;
}