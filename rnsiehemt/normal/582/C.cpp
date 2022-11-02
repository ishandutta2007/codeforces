#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
#define pb push_back
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); } 
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); } 
typedef long long ll;

const int MaxN = 200005;

int N, a[MaxN];
bool ismax[MaxN];
std::vector<int> lens[MaxN], cum[MaxN];
ll ans;

int gcd(int a, int b) {
    return (b ? gcd(b, a%b) : a);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    for (int k = 1; k <= N; k++) if ((N % k) == 0) {
        for (int s = 0; s < k; s++) {
            int max = -1e9;
            for (int i = s; i < s+N; i += k) domax(max, a[i]);
            for (int i = s; i < s+N; i += k) {
                ismax[i] = (a[i] == max);
            }
        }

        int start = 0;
        for (int i = 0; i < N; i++) if (!ismax[i]) start = i;
        int len = 0;
        for (int i = start; i < start+N; i++) {
            if (!ismax[i%N]) {
                if (len) {
                    lens[k].pb(len);
                    len = 0;
                }
            } else {
                len++;
            }
        }
        if (len) lens[k].pb(len);

        std::sort(lens[k].begin(), lens[k].end());
        std::reverse(lens[k].begin(), lens[k].end());
        cum[k].resize(sz(lens[k]));
        for (int i = 0; i < sz(lens[k]); i++) {
            if (i) cum[k][i] = cum[k][i-1];
            cum[k][i] += lens[k][i];
        }

        //printf("k = %d: ", k);
        //for (int i = 0; i < sz(lens[k]); i++) printf("%d%c", lens[k][i], " \n"[i == sz(lens[k]) - 1]);
        //if (sz(lens[k]) == 0) printf("\n");
    }

    for (int s = 1; s < N; s++) {
        int k = gcd(s, N);
        
        int lo = 0, hi = sz(lens[k]);
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (lens[k][mid] >= s) lo = mid;
            else hi = mid;
        }

        if (sz(lens[k]) == 0 || lens[k][lo] < s) {
            assert(lo == 0);
        } else if (lo == 0 && lens[k][lo] == N) {
            ans += N;
        } else {
            lo++;
            ans += cum[k][lo - 1] - (s-1) * lo;
        }
    }

    printf("%lld\n", ans);
}