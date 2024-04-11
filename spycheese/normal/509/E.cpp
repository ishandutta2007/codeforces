#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long long ull;
typedef long double ld;
typedef std::pair < int , int > ipair;

const int INF = 0x3f3f3f3f;
const int N = 500179;

int n;
double sum[N];
double curr, ans;

int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    std::string s;
    std::cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
            sum[i + 1] = sum[i] + 1;
        else
            sum[i + 1] = sum[i];
    }

    curr = sum[n];
    for (int i = 1; i <= n; ++i)
    {
        ans += curr / i;
        curr += sum[n - i] - sum[i];
    }
    printf("%.7lf\n", ans);

    return 0;
}