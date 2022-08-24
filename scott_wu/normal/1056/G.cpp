#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M;
int S;
ll T;
ll nlast[MAXN];

int move (int cloc, int ct)
{
    if (cloc < M) cloc += ct;
    else cloc += (N - ct);
    cloc %= N;
    return cloc;
}

int figure (int cloc)
{
    for (int i = N; i >= 1; i--)
        cloc = move (cloc, i);
    return cloc;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    for (int i = 0; i < MAXN; i++)
        nlast[i] = -1;

    cin >> N >> M >> S >> T;
    S--;
    while (T % N != 0)
    {
        S = move (S, T % N);
        T--;
    }
    nlast[S] = T;
    while (T > 0)
    {
        S = figure (S);
        T -= N;
        if (nlast[S] == -1)
        {
            nlast[S] = T;
        }
        else
        {
            ll ndiff = nlast[S] - T;
            T = T % ndiff;
        }
    }
    cout << S + 1 << "\n";
}