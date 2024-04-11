#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
const int MAXN = 5100;

int N;
vector <int> edge[MAXN];
bool ans[MAXN];
bool poss[MAXN];
int size[MAXN];

void flood(int cur, int last)
{
    if (last != -1 && edge[cur].size() == 1)
    {
        size[cur] = 1;
        return;
    }
    
    for (int i = 0; i < edge[cur].size(); i++)
        if (edge[cur][i] != last)
            flood (edge[cur][i], cur);
    
    for (int i = 0; i < MAXN; i++)
        poss[i] = false;
    poss[0] = true;
    
    size[cur] = 1;
    for (int i = 0; i < edge[cur].size(); i++)
    {
        int sz = size[edge[cur][i]];
        size[cur] += sz;
        for (int j = N - 1; j >= 0; j--)
            if (poss[j])
                poss[j+sz] = true;
    }
    int sz = N - size[cur];
    for (int j = N - 1; j >= 0; j--)
        if (poss[j])
            poss[j+sz] = true;
    
    for (int i = 0; i < MAXN; i++)
        if (poss[i])
            ans[i] = true;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int t, t2;
        cin >> t >> t2;
        t--, t2--;
        edge[t].push_back (t2);
        edge[t2].push_back (t);
    }
    
    flood (0, -1);
    
    int count = 0;
    for (int i = 1; i < N - 1; i++)
        if (ans[i])
            count++;
    cout << count << "\n";
    for (int i = 1; i < N - 1; i++)
        if (ans[i])
            cout << i << " " << N-1-i << "\n";
    //system ("Pause");
    return 0;
}