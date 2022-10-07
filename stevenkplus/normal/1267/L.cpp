#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, K, L;
string S;
int nc[26];
vector <char> res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 26; i++)
        nc[i] = 0;

    cin >> N >> L >> K >> S;
    for (int i = 0; i < S.length(); i++)
        nc[S[i]-'a']++;

    int nlo = 0, tlen = 0;
    for (int i = 0; i < 26; i++)
    {
        if (tlen == L) break;
        int ncnt = (K - nlo);
        int nb = nc[i] / ncnt;
        nb = min (nb, L - tlen);

        for (int j = nlo; j < K; j++)
        {
            for (int k = 0; k < nb; k++)
            {
                res[j].push_back((char) 'a' + i);
                nc[i]--;
            }
        }

        tlen += nb;
        if (tlen == L) break;

        int nleft = nc[i] % ncnt;
        for (int j = 0; j < nleft; j++)
        {
            res[nlo++].push_back((char) 'a' + i);
            nc[i]--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            while (nc[j] > 0 && res[i].size() < L)
            {
                res[i].push_back((char) 'a' + j);
                nc[j]--;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (char c : res[i])
            cout << c;
        cout << "\n";
    }
}