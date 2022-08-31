#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <int> conv (string s)
{
    vector <int> res(26);
    for (int i = 0; i < s.length(); i++)
        res[s[i]-'a']++;
    return res;
}

vector <vector <int> > cget (int l, int r)
{
    cout << "? " << l + 1 << " " << r + 1 << endl << flush;
    int len = (r - l + 1);
    int ctot = (len * (len + 1)) / 2;

    vector <vector <int> > ans;
    for (int i = 0; i < ctot; i++)
    {
        string s; cin >> s;
        ans.push_back (conv (s));
    }
    return ans;
}

void answer (string s)
{
    cout << "! " << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int N; cin >> N;

    if (N == 1)
    {
        vector <vector <int> > f = cget (0, 0);
        int ans = 0;
        while (f[0][ans] == 0) ans++;
        string s = "";
        s += (char) ('a' + ans);
        answer (s);
        return 0;
    }

    vector <vector <int> > ftot = cget (0, N - 1);
    vector <vector <int> > ptot = cget (1, N - 1);
    sort (ftot.begin(), ftot.end());
    sort (ptot.begin(), ptot.end());

    //cout << ftot.size() << " " << ptot.size() << "\n";

    vector <vector <int> > res;
    int cloc = 0;
    for (vector <int> v : ptot)
    {
        while (ftot[cloc] != v)
        {
            res.push_back(ftot[cloc]);
            cloc++;
        }
        cloc++;
    }
    while (cloc < ftot.size())
    {
        res.push_back(ftot[cloc]);
        cloc++;
    }

    //cout << res.size() << "\n";
    //return 0;

    string s = "";
    for (int i = 0; i < N; i++)
    {
        vector <int> rcur = res[i];
        if (i)
            for (int j = 0; j < 26; j++)
                rcur[j] -= res[i-1][j];

        int cans = 0;
        while (!rcur[cans]) cans++;
        s += (char) ('a' + cans);
    }
    answer (s);
}