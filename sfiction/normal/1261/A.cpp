#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ','){cerr << *sdbg++;}cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int N = 2E3 + 10;

vector<pii> ans;
char s[N];

int main(){
    int cas;
    scanf("%d", &cas);
    while (cas--){
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        
        ans.clear();
        int tail = n / 2 - k + 1;
        for (int i = 0; i < n; ++i){
            char target;
            if (k > i / 2 + 1)
                target = "()"[i & 1];
            else
                target = "()"[i + tail >= n];

            int j = find(s + i, s + n, target) - s;

            if (i < j){
                reverse(s + i, s + j + 1);
                ans.emplace_back(i + 1, j + 1);
            }
        }

        printf("%d\n", ans.size());
        for (auto &x: ans)
            printf("%d %d\n", x.st, x.nd);
    }
	return 0;
}