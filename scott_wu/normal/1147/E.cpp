#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int nedge[MAXN];
vector <pair <int, int> > qs;
vector <int> ans;
vector <int> cs;
int res[MAXN], outc[MAXN];
vector <int> gg[3];

void ask()
{
    ans.clear();
    if (!qs.size())
        return;
    cout << "Q " << qs.size();
    for (pair <int, int> p : qs)
    {
        cout << " " << p.first + 1 << " " << p.second + 1;
    }
    cout << endl << flush;
    string t; cin >> t;
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] == '0')
            ans.push_back(0);
        else
            ans.push_back(1);
    }
}

void win()
{
    cout << "A " << gg[0].size() << " " << gg[1].size() << " " << gg[2].size() << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < gg[i].size(); j++)
        {
            if (j) cout << " ";
            cout << gg[i][j] + 1;
        }
        cout << endl;
    }
}

void gogo()
{
    for (int i = 0; i < 3; i++)
        gg[i].clear();
    cin >> N;

    qs.clear();
    for (int i = 0; i + 1 < N; i += 2)
        qs.push_back(make_pair (i, i+1));
    ask();
    for (int i = 0; i < ans.size(); i++)
        nedge[2*i] = ans[i];

    qs.clear();
    for (int i = 1; i + 1 < N; i += 2)
        qs.push_back(make_pair (i, i+1));
    ask();
    for (int i = 0; i < ans.size(); i++)
        nedge[2*i+1] = ans[i];
    
    cs.clear();
    cs.push_back(0);
    for (int i = 0; i < N - 1; i++)
    {
        if (!nedge[i])
        {
            cs.push_back(i + 1);
        }
    }

    qs.clear();
    for (int i = 2; i < cs.size(); i++)
    {
        if (i % 4 >= 2)
        {
            qs.push_back(make_pair (cs[i], cs[i-2]));
        }
    }
    ask();
    int nx = 0;
    for (int i = 2; i < cs.size(); i++)
    {
        if (i % 4 >= 2)
        {
            outc[i] = ans[nx];
            nx++;
        }
    }

    qs.clear();
    for (int i = 2; i < cs.size(); i++)
    {
        if (i % 4 < 2)
        {
            qs.push_back(make_pair (cs[i], cs[i-2]));
        }
    }
    ask();
    nx = 0;
    for (int i = 2; i < cs.size(); i++)
    {
        if (i % 4 < 2)
        {
            outc[i] = ans[nx];
            nx++;
        }
    }

    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i < cs.size(); i++)
    {
        if (outc[i])
            res[i] = res[i-2];
        else
            res[i] = 3 - res[i-1] - res[i-2];
    }

    int nc = 0;
    for (int i = 0; i < N; i++)
    {
        if (nc + 1 < cs.size() && cs[nc+1] <= i)
            nc++;
        gg[res[nc]].push_back(i);
    }

    win();
}

int main()
{
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        gogo();
    }
}