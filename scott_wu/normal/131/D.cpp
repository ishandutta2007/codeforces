#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 3100;

int n;
vector <int> ringroad;
vector <int> temp;
bool seen[MAXN];
int parent[MAXN];
vector <int> edge[MAXN];
bool check = false;
int bad, bad2;
int ans[MAXN];

void flood (int cur)
{
    seen[cur] = true;
    for (int i = 0; i < edge[cur].size(); i++)
    {
        if (check) return;
        if (edge[cur][i] == parent[cur]) continue;
        if (seen[edge[cur][i]])
        {
            check = true;
            int c = edge[cur][i];
            while (c != -1)
            {
                temp.push_back (c);
                c = parent[c];
            }
            int sz = temp.size();
            c = cur;
            while (c != -1)
            {
                temp.push_back (c);
                c = parent[c];
            }
            for (int j = 0; j < sz; j++)
            {
                ringroad.push_back (temp[j]);
                if (temp[j] == temp[j + temp.size() - sz])
                    break;
            }
            for (int j = temp.size() - 1; j >= sz; j--)
            {
                if (temp[j] != temp[max (j - (int) temp.size() + sz, 0)])
                    ringroad.push_back (temp[j]);
            }
            /*cout << sz << "\n\n";
            for (int j = 0; j < temp.size(); j++)
                cout << temp[j] << "\n";
            cout << "\n";
            for (int j = 0; j < ringroad.size(); j++)
                cout << ringroad[j] << "\n";*/
        }
        else
        {
            parent[edge[cur][i]] = cur;
            flood (edge[cur][i]);
        }
    }
}

void flood2 (int cur, int last, int dist)
{
    ans[cur] = dist;
    for (int i = 0; i < edge[cur].size(); i++)
        if (edge[cur][i] != bad && edge[cur][i] != bad2 && edge[cur][i] != last)
            flood2 (edge[cur][i], cur, dist + 1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, t2;
        cin >> t >> t2;
        t--; t2--;
        edge[t].push_back (t2);
        edge[t2].push_back (t);
    }
    parent[0] = -1;
    flood (0);
    ringroad.push_back (ringroad[0]);
    ringroad.push_back (ringroad[1]);
    for (int i = 1; i < ringroad.size() - 1; i++)
    {
        bad = ringroad[i-1];
        bad2 = ringroad[i+1];
        flood2 (ringroad[i], -1, 0);
    }
    string sep = "";
    for (int i = 0; i < n; i++)
    {
        cout << sep << ans[i];
        sep = " ";
    }
    cout << "\n";
    //system ("Pause");
    return 0;
}