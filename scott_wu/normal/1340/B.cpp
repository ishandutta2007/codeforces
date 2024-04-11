#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

string d[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int N, K;
int dp[MAXN][MAXN];
int nlast[MAXN][MAXN];
int nfrom[MAXN][MAXN];
pair <int, int> ndp[MAXN];
vector <int> res;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    dp[0][0] = 1;
    for (int i = 1; i < MAXN; i++)
        dp[0][i] = -100;

    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;

        for (int j = 0; j < MAXN; j++)
        {
            ndp[j] = make_pair (-1, -1);
            nlast[i+1][j] = nfrom[i+1][j] = -1;
        }

        for (int j = 0; j < 10; j++)
        {
            int ndiff = 0;
            for (int k = 0; k < 7; k++)
            {
                if (s[k] == '0' && d[j][k] == '1')
                    ndiff++;
                else if (s[k] == '1' && d[j][k] == '0')
                {
                    ndiff = -100;
                    break;
                }
            }
            if (ndiff < 0) continue;

            for (int k = 0; k <= K; k++)
            {
                if (ndp[k+ndiff] < make_pair (dp[i][k], j))
                {
                    ndp[k+ndiff] = make_pair (dp[i][k], j);
                    nfrom[i+1][k+ndiff] = k;
                    nlast[i+1][k+ndiff] = j;
                }
            }
        }

        vector <pair <pair <int, int>, int> > vv;
        for (int j = 0; j <= K; j++)
            vv.push_back (make_pair (ndp[j], j));
        sort (vv.begin(), vv.end());

        int nt = 0;
        for (int j = 0; j <= K; j++)
        {
            if (j > 0 && vv[j].first != vv[j-1].first)
                nt++;
            dp[i+1][vv[j].second] = nt;
        }
    }

    int cn = N, ck = K;
    bool bad = false;
    while (cn)
    {
        if (nlast[cn][ck] < 0)
        {
            bad = true;
            break;
        }
        res.push_back(nlast[cn][ck]);
        ck = nfrom[cn][ck];
        cn--;
    }

    if (ck != 0) bad = true;

    if (bad) cout << "-1\n";
    else
    {
        reverse (res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            cout << res[i];
        cout << "\n";
    }
}