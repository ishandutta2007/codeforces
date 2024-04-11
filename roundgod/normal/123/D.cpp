#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
 
using namespace std;
 
const int MAX_N = 100100;
 
struct SuffixArray
{
    int sa[MAX_N], height[MAX_N];
 
    void build(const string &s)
    { build(s.c_str(), s.size()); }
 
    void build(const char *t, int n)
    {
        static int g[MAX_N], b[MAX_N];
        for (int i = 0; i < n + 1; ++i)
        {
            sa[i] = i, g[i] = t[i];
        }
        b[0] = b[n] = 0;
        sort(sa, sa + n + 1, SAComp(0, g));
        for (int h = 1; b[n] != n; h *= 2)
        {
            SAComp comp(h, g);
            sort(sa, sa + n + 1, comp);
            for (int i = 0; i < n; ++i)
            {
                b[i + 1] = b[i] + comp(sa[i], sa[i + 1]);
            }
            for (int i = 0; i < n + 1; ++i)
            {
                g[sa[i]] = b[i];
            }
        }
        for (int i = 0; i < n + 1; ++i)
        {
            b[sa[i]] = i;
        }
        int h = 0;
        for (int i = 0; i < n; ++i)
        {
            const int j = sa[b[i] - 1];
            while (j + h < n && i + h < n && t[j + h] == t[i + h])
                h++;
            height[b[i]] = h;
            if (h)
                h--;
        }
        height[0] = -1;
    }
 
    struct SAComp
    {
        const int h, *g;
 
        SAComp(int h, int *g) : h(h), g(g)
        {}
 
        bool operator()(int l, int r)
        {
            return g[l] != g[r] ? g[l] < g[r] : g[l + h] < g[r + h];
        }
    };
} sa;
 
char buf[MAX_N];
 
long long cnt(long long n)
{
    return n * (n + 1) / 2;
}
 
int main()
{
#ifndef  ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("err.txt", "w", stderr);
#endif
    int n;
    long long ans;
    vector<pair<pair<int, int>, int>> v;
 
    scanf("%s", buf);
    n = (int) strlen(buf);
    sa.build(buf, n);
    sa.height[n + 1] = 0;
    sa.sa[n + 1] = n;
    ans = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        while (!v.empty() && v.back().first.second > sa.height[i])
        {
            auto &end = v.back();
            if (end.first.first < sa.height[i])
            {
                ans += (end.first.second - sa.height[i]) * cnt(i - end.second);
                end.first.second = sa.height[i];
            }
            else
            {
                ans += (end.first.second - end.first.first) * cnt(i - end.second);
                v.pop_back();
            }
        }
        v.push_back({{sa.height[i], n - sa.sa[i]}, i});
    }
    printf("%I64d\n", ans);
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stderr);
#endif
    return 0;
}