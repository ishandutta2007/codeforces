#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int MAXN = 5100;

int n;
bool edge[MAXN][MAXN];
int num[MAXN];
//bool seen2[MAXN];
bool seen[MAXN];
int last[MAXN];
bool done;
int start;
vector <int> cyc, lcyc;
bool bad[MAXN];
char ch[MAXN];

/*void flood (int cur)
{
    seen2[cur] = true;
    for (int i = 0; i < beat[cur].size(); i++)
    {
        if (done) return;
        if (seen[beat[cur][i]])
        {
            last[beat[cur][i]] = cur;
            done = true;
            lres = beat[cur][i];
        }
        else if (!seen2[beat[cur][i]])
        {
            last[beat[cur][i]] = cur;
            seen[beat[cur][i]] = true;
            flood (beat[cur][i]);
            seen[beat[cur][i]] = false;
        }
    }
}*/

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf ("%s",ch);
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = (ch[j] == '1');
            if (edge[i][j])
                num[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        seen[i] = false;
        bad[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        bool found = true;
        for (int j = 0; j < n; j++)
        {
            if (num[j] == 0 && !bad[j])
            {
                found = false;
                bad[j] = true;
                for (int k = 0; k < n; k++)
                    if (edge[k][j])
                        num[k]--;
            }
        }
        if (found) break;
    }
    int start = -1;
    for (int i = 0; i < n; i++)
        if (num[i] > 0)
            start = i;
    /*for (int i = 0; i < n; i++)
        seen[i] = seen2[i] = false;
    done = false;*/
    //cout << start << "\n";
    int cloc = start;
    if (start == -1)
    {
        cout << "-1\n";
        //system ("Pause");
        return 0;
    }
    else
    {
        while (true)
        {
            if (seen[cloc]) break;
            seen[cloc] = true;
            for (int i = 0; i < n; i++)
                if (edge[cloc][i] && !bad[i])
                {
                    last[i] = cloc;
                    cloc = i;
                    break;
                }
        }
    }
    int cur = cloc;
    do
    {
        cyc.push_back (cur);
        cur = last[cur];
    } while (cur != cloc);
    while (cyc.size() > 3)
    {
        if (edge[cyc[0]][cyc[2]])
        {
            cout << cyc[0]+1 << " " << cyc[2]+1 << " " << cyc[1]+1 << "\n";
            //system ("Pause");
            return 0;
        }
        lcyc.clear();
        for (int i = 0; i < cyc.size(); i++)
            lcyc.push_back (cyc[i]);
        cyc.clear();
        for (int i = 0; i < lcyc.size(); i++)
            if (i != 1)
                cyc.push_back (lcyc[i]);
    }
    cout << cyc[0]+1 << " " << cyc[2]+1 << " " << cyc[1]+1 << "\n";
    //system ("Pause");
    return 0;
}