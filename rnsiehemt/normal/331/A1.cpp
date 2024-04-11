// Change I64d to lld to compile
#include <cstdio>
#include <algorithm>

typedef long long ll;

const ll inf = 999999999999999999ll;

int N;
ll a[300005];
ll s[300005];
int k[300005];
int anss, anse;
ll ans = -inf;
int d[300005];
int D;

bool cmp(const int &i, const int &j) {
    if (a[i] == a[j]) return i < j;
    else return a[i] < a[j];
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%I64d", &a[i]);
    
    s[0] = std::max(0ll, a[0]);
    for (int i = 1; i < N; i++) s[i] = s[i-1] + std::max(0ll, a[i]);

    for (int i = 0; i < N; i++) k[i] = i;
    std::sort(k, k+N, cmp);
    
    int curs = k[0]; ll sum = a[k[0]];
    for (int i = 1; i < N; i++) {
        if (a[k[i]] == a[k[i-1]]) {
            sum += s[k[i]-1] - s[k[i-1]];
            if (sum + a[k[i]] > ans) {
                ans = sum + a[k[i]];
                anss = curs;
                anse = k[i];
            }
            if (a[k[i]] > 0ll) sum += a[k[i]];
        }
        else {
            curs = k[i];
            sum = a[k[i]];
        }
    }

    printf("%I64d ", ans);
    for (int i = 0; i < anss; i++) d[D++] = i+1;
    for (int i = anss+1; i < anse; i++) if (a[i] < 0ll) d[D++] = i+1;
    for (int i = anse+1; i < N; i++) d[D++] = i+1;
    printf("%d\n", D);
    for (int i = 0; i < D; i++) printf("%d ", d[i]);
    printf("\n");
}