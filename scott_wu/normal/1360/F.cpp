#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
string s[10];

bool test (string t)
{
    for (int i = 0; i < N; i++)
    {
        int nc = 0;
        for (int j = 0; j < M; j++)
            if (s[i][j] != t[j])
                nc++;
        if (nc > 1) return false;
    }
    return true;
}

void gogo()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> s[i];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            string g = s[0];
            g[i] = (char) ('a' + j);
            if (test (g))
            {
                cout << g << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--)
    {
        gogo();
    }
}