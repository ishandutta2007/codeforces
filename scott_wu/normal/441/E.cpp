#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 210;
 
int X, N, P;

vector <short> trainer (int x)
{
    vector <short> res;
    for (int i = 0; i <= N; i++)
        res.push_back(__builtin_ctz(x+i));
    return res;
}
 
vector <short> plessy (vector <short> &v)
{
    vector <short> res(v.size() - 1);
    for (int i = 1; i < v.size(); i++)
        res[i-1] = v[i];
    return res;
}
 
vector <short> timey (vector <short> &v)
{
    vector <short> res(v.size() - 1);
    for (int i = 0; i + 1 < v.size(); i++)
    {
        if (i % 2 == 1)
            res[i] = 0;
        else
            res[i] = v[i/2] + 1;
    }
    return res;
}

map <vector <short>, double> dp[MAXN];
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    cin >> X >> N >> P;
    dp[0][trainer(X)] = 1.0;
 
    for (int i = 0; i < N; i++)
    {
        for (auto it : dp[i])
        {
            vector <short> v = it.first;
            dp[i+1][timey (v)] += it.second * (P / 100.0);
            dp[i+1][plessy (v)] += it.second * ((100. - P) / 100.0);
        }
        dp[i].clear();
    }
 
    double res = 0.0;
    for (auto it : dp[N])
    {
        res += it.second * it.first[0];
    }
    cout << fixed << setprecision(9);
    cout << res << "\n";
}