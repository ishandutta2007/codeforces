#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

vector <int> conv (string s)
{
    vector <int> res(26);
    for (int i = 0; i < s.length(); i++)
        res[s[i]-'a']++;
    return res;
}

//string g = "abbabbababaababababaab";
int cx;

vector <vector <int> > cget (int l, int r)
{
    cout << "? " << l + 1 << " " << r + 1 << endl << flush;
    int len = (r - l + 1);
    int ctot = (len * (len + 1)) / 2;
    cx += ctot;

    vector <vector <int> > ans;
    /*for (int i = l; i <= r; i++)
        for (int j = i; j <= r; j++)
            ans.push_back (conv (g.substr (i, j - i + 1)));*/
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

void small_ball()
{
    if (N == 1)
    {
        vector <vector <int> > f = cget (0, 0);
        int ans = 0;
        while (f[0][ans] == 0) ans++;
        string s = "";
        s += (char) ('a' + ans);
        answer (s);
        return;
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

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;

    if (N <= 7)
    {
        small_ball();
        return 0;
    }

    int CUT = (3 * N - 1) / 4;
    vector <vector <int> > ftot = cget (0, CUT);
    vector <vector <int> > ptot = cget (1, CUT);
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
    string s = "";
    for (int i = 0; i < CUT + 1; i++)
    {
        vector <int> rcur = res[i];
        if (i)
            for (int j = 0; j < 26; j++)
                rcur[j] -= res[i-1][j];

        int cans = 0;
        while (!rcur[cans]) cans++;
        s += (char) ('a' + cans);
    }

    int NKEEP = (N / 2) + 1;
    vector <vector <int> > blast = cget (N - NKEEP, N - 1);
    sort(blast.begin(), blast.end());

    res.clear();
    for (int i = N - 1; i >= CUT; i--)
    {
        int stot = (i - (N - NKEEP)) + 1;
        vector <int> big;
        for (int j = 0; j < blast.size(); j++)
        {
            int ct = 0;
            for (int k = 0; k < 26; k++)
                ct += blast[j][k];
            if (ct == stot)
            {
                big = blast[j];
                break;
            }
        }
       /* for (int j = 0; j < 26; j++)
            for (int k = 0; k < big[j]; k++)
                cout << (char) ('a' + j);
        cout << "\n";*/

        res.push_back(big);
        vector <vector <int> > sig;
        for (int j = N - NKEEP; j <= CUT; j++)
        {
            sig.push_back(big);
            big[s[j]-'a']--;
            /*for (int j = 0; j < 26; j++)
                for (int k = 0; k < big[j]; k++)
                    cout << (char) ('a' + j);
            cout << "\n";*/
        }
        reverse (sig.begin(), sig.end());
        vector <vector <int> > nblast;
        int crloc = 0;
        for (vector <int> vv : sig)
        {
            while (crloc < blast.size() && blast[crloc] != vv)
            {
                nblast.push_back(blast[crloc]);
                crloc++;
            }
            crloc++;
        }
        while (crloc < blast.size())
        {
            nblast.push_back(blast[crloc]);
            crloc++;
        }
        blast = nblast;
    }
    reverse (res.begin(), res.end());
    for (int i = 0; i + 1 < res.size(); i++)
    {
        int cj = 0;
        while (res[i][cj] == res[i+1][cj]) cj++;
        s += (char) ('a' + cj);
    }
    answer (s);

    //cout << cx << " " << (int) (0.777 * (N + 1) * (N+1)) << "\n";
}