#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair < int , int > pair;

const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits<double>::infinity();
const double EPS = 1e-8;

const int N = 1179;

int n;
ll w[N], h[N];

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> w[i] >> h[i];
    ll answer = LINF;
    for (int maxH = 1; maxH <= N; ++maxH)
    {
        ll cans = 0;
        for (int j = 0; j < n; ++j)
        {
            ll add = IINF;
            if (w[j] <= maxH)
                add = std::min(add, h[j]);
            if (h[j] <= maxH)
                add = std::min(add, w[j]);
            cans += add;
            if (add == IINF)
                break;
        }
        cans *= maxH;
        answer = std::min(answer, cans);
    }
    std::cout << answer << "\n";
    return 0;
}