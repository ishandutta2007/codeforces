#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
#define pb push_back
#define mp make_pair
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 300005;
const ll inf = 1e17;

int N, K;
ll a[MaxN], delta[MaxN], sum[MaxN];
std::unordered_map<ll, ll> m[MaxN];

ll dp(int i, int j) {
    if (m[i].find(j) == m[i].end()) return inf;
    else return m[i][j];
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);

    std::sort(a+1, a+N+1);
    for (int i = 1; i+1 <= N; i++) delta[i] = a[i+1] - a[i];
    for (int i = 1; i+1 <= N; i++) sum[i] = sum[i-1] + delta[i]; 
    int extra = N%K, normal = K - extra, size = N/K;
    m[0][0] = 0;
    for (int i = size; i <= N; i++) {
        if (i <= N-size || i == N) {
            for (int j = std::max(1, i/(size+1)); j <= i/size; j++) {
                if (j >= extra && i > extra*(size+1) + (j-extra)*size) continue;
                if (j >= normal && i < normal*size + (j-normal)*(size+1)) continue;
                m[i][j] = dp(i-size, j-1) + sum[i-1] - sum[i-size];
                if (i >= size+1) m[i][j] = std::min(m[i][j], dp(i-(size+1), j-1) + sum[i-1] - sum[i-(size+1)]);
                //printf("m[%d][%d] = %lld\n", i, j, m[i][j]);
            }
        }
        if (i >= size+1) m[i-(size+1)].clear();
    }
    printf("%lld\n", m[N][K]);
}