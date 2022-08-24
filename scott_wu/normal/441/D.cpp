#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 3100;

int N;
int nv[MAXN];
int pt[MAXN];
int M;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> nv[i];
        nv[i]--;
        pt[i] = -1;
    }
    cin >> M;

    int nn = 0;
    for (int i = 0; i < N; i++)
    {
        if (pt[i] == -1)
        {
            int cloc = i;
            while (pt[cloc] == -1)
            {
                pt[cloc] = nn;
                cloc = nv[cloc];
            }
            nn++;
        }
    }

    nn = N - nn;
    vector <int> ans;
    if (nn > M)
    {
        for (int i = 0; i < nn - M; i++)
        {
            for (int j = 0; j < N; j++)
                if (nv[j] != j)
                {
                    int cv = nv[j];
                    int mv = nv[j];
                    while (cv != j)
                    {
                        mv = min (mv, cv);
                        cv = nv[cv];
                    }
                    ans.push_back(j);
                    ans.push_back(mv);
                    swap (nv[j], nv[mv]);
                    break;
                }
        }
    }
    else
    {
        set <int> s;
        for (int i = 0; i < M - nn; i++)
        {
            int ct = pt[0];
            for (int j = 0; j < N; j++)
            {
                if (pt[j] != ct && s.find(pt[j]) == s.end())
                {
                    s.insert(pt[j]);
                    ans.push_back(0);
                    ans.push_back(j);
                    break;
                }
            }
        }
    }

    cout << ans.size() / 2 << "\n";
    for (int x : ans)
        cout << x + 1 << " ";
}