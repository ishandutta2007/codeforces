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
const int MAXN = 210;

ll K;
int N, M;

pair <ll, pair <string, string> > fib[MAXN];

bool query (string S)
{
    // count strings <= S
    fib[0] = make_pair (0, make_pair ("0", "0"));
    fib[1] = make_pair (0, make_pair ("1", "1"));
    if ("0" <= S)
        fib[0].first++;
    if ("1" <= S)
        fib[1].first++;

    for (int i = 2; i <= N; i++)
    {
        ll ntot = fib[i-2].first + fib[i-1].first;
        string send = fib[i-2].second.second, sbegin = fib[i-1].second.first;
        string stot = send + sbegin;
        for (int j = 0; j < send.length(); j++)
        {
            for (int len = 0; len + j < send.length(); len++)
            {
                if (send[len+j] < S[len]) break;
                else if (send[len+j] > S[len])
                {
                    ntot++;
                    break;
                }
            }
            for (int len = 0; len < M && len + j < stot.length(); len++)
            {
                if (stot[len+j] < S[len]) break;
                else if (stot[len+j] > S[len])
                {
                    ntot--;
                    break;
                }
            }
        }

        fib[i].first = ntot;
        fib[i].second.first = fib[i-2].second.first + fib[i-1].second.first;
        fib[i].second.second = fib[i-2].second.second + fib[i-1].second.second;
        if (fib[i].second.first.length() > M)
            fib[i].second.first = fib[i].second.first.substr(0, M);
        if (fib[i].second.second.length() > M)
            fib[i].second.second = fib[i].second.second.substr(fib[i].second.second.length() - M);
        if (fib[i].first > 2e18) fib[i].first = 2e18;
    }

    return fib[N].first >= K;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K >> M;

    string ans = "";
    string ones = "";
    for (int i = 0; i < M; i++)
        ones += '1';

    while (ans.length() < M)
    {
        if (query (ans)) break;
        else if (query (ans + '0' + ones)) ans += '0';
        else ans += '1';
    }
    //cout << fib[4].second.first << " " << fib[4].second.second << "\n";
    cout << ans << "\n";
}