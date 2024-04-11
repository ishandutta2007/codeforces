#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 1e5 + 10, M = 1e5, I = M * M;
long long n, A[N], F[N], Pw[120][120];
string Mn;
map < int , string > MP;
vector< int > B;
void Min(string tt)
{
    if (tt.size() < Mn.size())
        Mn = tt;
}
string gett(int ii)
{
    string ret = "";
    if (ii <= 0) return ("What Da .... :|?");
    while (ii)
        ret += (char)(ii % 10 + '0'), ii /= 10;
    reverse(ret.begin(), ret.end());
    return (ret);
}
bool Check(int a, int b)
{
    return (a < I && b < I && a <= (I + b - 1) / b && a * b < I);
}
void Solve(int aa, int bb, int cc, int dd)
{
    for (int a = 2; a < aa; a++)
        for (int b = 2; b < bb; b++)
            for (int c = 2; c < cc; c++)
                for (int d = 2; d < dd; d++)
                    {
                        if (Check(Pw[a][b], Pw[c][d]))
                        {
                            Min(gett(a) + '^' + gett(b) + '*' + gett(c) + '^' + gett(d) + '+' + gett(n - Pw[a][b] * Pw[c][d]));
                            if (n % (Pw[a][b] * Pw[c][d]) == 0)
                                Min(gett(a) + '^' + gett(b) + '*' + gett(c) + '^' + gett(d) + '*' + gett(n / (Pw[a][b] * Pw[c][d])));
                        }
                        Min(gett(a) + '^' + gett(b) + '+' + gett(c) + '^' + gett(d) + '+' + gett(n - Pw[a][b] - Pw[c][d]));
                        if (n >= Pw[c][d] && (n - Pw[c][d]) % Pw[a][b] == 0)
                            Min(gett(a) + '^' + gett(b) + '*' + gett((n - Pw[c][d]) / Pw[a][b]) + '+' + gett(c) + '^' + gett(d));
                    }
}
int Power(int a, int b)
{
    int ret = 1;
    for (; b && Check(a, 1); b >>= 1, a = (Check(a, a) ? a * a : I))
        if (b & 1)
            ret = ret * ((Check(a, ret) ? ret * a : I));
    return (ret);
}
void Solve2(int aa, int bb, int cc)
{
    for (int a = 2; a < aa; a++)
        for (int b = 2; b < bb; b++)
            for (int c = 1; c < cc; c++)
            {
                if (a < 120 && Pw[a][b] != I && (n - c) % Pw[a][b] == 0)
                    Min(gett(a) + '^' + gett(b) + '*' + gett((n - c) / Pw[a][b]) + '+' + gett(c));
                if (a >= 120 && Power(a, b) != I && (n - c) % Power(a, b) == 0)
                    Min(gett(a) + '^' + gett(b) + '*' + gett((n - c) / Power(a, b)) + '+' + gett(c));
            }
}
int32_t main()
{
    scanf("%lld", &n);
    Mn = gett(n);
    if (n == 1ll * M * M) return puts("10^10");
    for (int i = 2; i <= M; i++)
    {
        int cnt = 2, len = (int)floor(log10(i)) + 1;
        long long r = i * 1ll * i;
        while ((int)floor(log10(r)) + 1 <= len + 1 + ((cnt < 10) ? 1 : 2))
            cnt ++, r *= i;
        F[i] = cnt; A[i] = r;
    }
    for (int i = 0; i < 120; i++)
        Pw[i][0] = 1;
    for (int j = 1; j < 120; j++)
        for (int i = 2; i < 120; i++)
            Pw[i][j] = Check(Pw[i][j - 1], i) ? (Pw[i][j -1] * i) : I;
    for (int i = 2; i <= M; i++)
    {
        int r = A[i], cnt = F[i];
        while (r < I)
        {
            B.pb(r);
            string tt = gett(i) + '^' + gett(cnt);
            if (MP.count(r) == 0)
                MP[r] = tt;
            if (MP[r].size() > tt.size())
                MP[r] = tt;
            r *= i; cnt ++;
        }
    }
    sort(B.begin(), B.end());
    for (auto X : B)
        if (X == n && Mn.size() > MP[X].size())
            Mn = MP[X];
    for (auto X : B)
    {
        if (n % X == 0)
        {
            Min((string)(MP[X] + '*' + gett(n / X)));
            int t = n / X;
            if (MP.count(t))
                Min((string)(MP[X] + '*' + MP[t]));
        }
        Min((string)(MP[X] + '+' + gett(n - X)));
        if (MP.count(n - X))
            Min((string)(MP[X] + '+' + MP[n - X]));
    }
    Solve(100, 10, 10, 10);
    Solve(10, 100, 10, 10);
    Solve(10, 10, 100, 10);
    Solve(10, 10, 10, 100);
    Solve2(10, 10, 10000);
    Solve2(10000, 10, 10);
    Solve2(1000, 10, 100);
    Solve2(100, 10, 1000);
    Solve2(10, 50, 10000);
    cout << Mn;
    return (0);
}