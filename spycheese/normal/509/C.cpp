#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long long ull;
typedef long double ld;
typedef std::pair < int , int > ipair;

const int INF = 0x3f3f3f3f;
const int N = 179;

int n;
std::string ca = "0";

std::string getNext(const std::string & a, int b)
{
    int dc = a.length();

    if (dc * 9 < b)
    {
        dc = (b + 8) / 9;
        std::string ans = "1";
        for (int i = 1; i < dc; ++i)
            ans += '0';
        --b;
        int i = dc - 1;
        while (b > 0)
        {
            int x = std::min(b, 9 - (ans[i] - '0'));
            b -= x;
            ans[i] += x;
            --i;
        }
        return ans;
    }
    
    std::string mmx = "a";
    for (int i = 0; i < dc; ++i)
    {
        if (a[i] == '9')
            continue;
        std::string ans = a.substr(0, i);
        ans += a[i] + 1;
        for (int j = i + 1; j < dc; ++j)
            ans += '0';
        int cb = b;
        for (int j = 0; j < dc; ++j)
            cb -= ans[j] - '0';
        if (cb < 0)
            continue;
        int j = dc - 1;
        while (cb > 0)
        {
            int x = std::min(cb, 9 - (ans[j] - '0'));
            cb -= x;
            ans[j] += x;
            --j;
        }
        mmx = std::min(mmx, ans);
    }

    if (mmx != "a")
        return mmx;
    ++dc;
    std::string ans = "1";
    for (int i = 1; i < dc; ++i)
        ans += '0';
    --b;
    int i = dc - 1;
    while (b > 0)
    {
        int x = std::min(b, 9 - (ans[i] - '0'));
        b -= x;
        ans[i] += x;
        --i;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int b;
        std::cin >> b;
        ca = getNext(ca, b);
        std::cout << ca << "\n";
    }

    return 0;
}