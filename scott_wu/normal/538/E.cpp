#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
vector <int> edge[MAXN];
int ssize[MAXN];
int S[MAXN], M[MAXN];

void run (int cloc, int flag)
{
    ssize[cloc] = 0;
    if (edge[cloc].size() == 0)
    {
        ssize[cloc] = 1;
        S[cloc] = M[cloc] = 0;
        return;
    }
    
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        run (edge[cloc][i], 1 - flag);
        ssize[cloc] += ssize[edge[cloc][i]];
    }
    
    if (flag)
    {
        //min
        S[cloc] = 0;
        for (int i = 0; i < edge[cloc].size(); i++)
        {
            int neigh = edge[cloc][i];
            S[cloc] += S[neigh];
        }
        
        M[cloc] = N;
        for (int i = 0; i < edge[cloc].size(); i++)
        {
            int neigh = edge[cloc][i];
            M[cloc] = min (M[cloc], M[neigh]);
        }
    }
    else
    {
        //max
        S[cloc] = 0;
        for (int i = 0; i < edge[cloc].size(); i++)
        {
            int neigh = edge[cloc][i];
            S[cloc] = max (S[cloc], ssize[cloc] - (ssize[neigh] - S[neigh]));
        }
        
        M[cloc] = 0;
        for (int i = 0; i < edge[cloc].size(); i++)
        {
            int neigh = edge[cloc][i];
            M[cloc] += M[neigh] + 1;
        }
        M[cloc]--;
    }
    
    //cout << cloc << " " << S[cloc] << " " << M[cloc] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back (b);
    }
    
    run(0, 0);
    cout << S[0] + 1 << " " << M[0] + 1 << "\n";
    return 0;
}