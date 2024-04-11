//
//  main.cpp
//  Codeforces
//
//  Created by Scott Wu on 3/16/15.
//  Copyright (c) 2015 Scott Wu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
const int MAXN = 200100;

int N, M;
vector <int> edge[MAXN];
int dep[MAXN];
int croute[MAXN];
int par[MAXN];
pair<int, int> cover[MAXN];
bool seen[MAXN];

void run (int cloc, int last, int cdep)
{
    seen[cloc] = true;
    croute[cdep] = cloc;
    dep[cloc] = cdep;
    par[cloc] = last;
    
    //cout << cloc << " " << last << " " << cdep << endl;
    
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh == last) continue;
        
        if (!seen[neigh])
            run(neigh, cloc, cdep + 1);
        else
        {
            int s = dep[neigh];
            for (int j = s + 1; j <= cdep; j++)
            {
                int k = croute[j];
                if (cover[k].first != -1)
                {
                    int a = cover[k].first, b = cover[k].second;
                    int c = neigh, d = cloc;
                    
                    if (dep[a] > dep[c])
                    {
                        swap (a, c);
                        swap (b, d);
                    }
                    
                    vector<int> x, y, z;
                    
                    int goalx = b, goaly = d;
                    while (dep[goalx] > dep[goaly])
                        goalx = par[goalx];
                    while (dep[goaly] > dep[goalx])
                        goaly = par[goaly];
                    while (goalx != goaly)
                    {
                        goalx = par[goalx];
                        goaly = par[goaly];
                    }
                    int goal = goalx;
                    //cout << c << " " << goal << endl;
                    //if (dep[d] < dep[b]) goal = d;
                    
                    int n = c;
                    x.push_back(n);
                    while (n != a)
                    {
                        n = par[n];
                        x.push_back(n);
                    }
                    x.push_back(b);
                    n = b;
                    while (n != goal)
                    {
                        n = par[n];
                        x.push_back(n);
                        //cout << "x " << n << endl;
                    }
                    
                    y.push_back(c);
                    y.push_back(d);
                    n = d;
                    while (n != goal)
                    {
                        n = par[n];
                        y.push_back(n);
                        //cout << "y " << n << endl;
                    }
                    
                    n = goal;
                    z.push_back(n);
                    while (n != c)
                    {
                        n = par[n];
                        z.push_back(n);
                        //cout << "z " << n << endl;
                    }
                    
                    //cout << a << " " << b << " " << c << " " << d << "\n";
                    cout << "YES\n";
                    /*vector<int> x, y, z;
                    if (b < d)
                    {
                        //c...b
                        for (int m = c; m <= b; m++)
                            x.push_back(croute[m]);
                        for (int m = c; m >= a; m--)
                            y.push_back(croute[m]);
                        y.push_back(croute[b]);
                        z.push_back(croute[c]);
                        for (int m = d; m >= b; m--)
                            z.push_back(croute[m]);
                    }
                    else
                    {
                        //c...d
                        vector<int> x, y, z;
                        for (int m = c; m <= d; m++)
                            x.push_back(croute[m]);
                        for (int m = c; m >= a; m--)
                            y.push_back(croute[m]);
                        z.push_back(croute[b]);
                        z.push_back(croute[c]);
                        for (int m = b; m >= d; m--)
                            y.push_back(croute[m]);
                    }*/
                    
                    cout << x.size();
                    for (int m = 0; m < x.size(); m++)
                        cout << " " << x[m] + 1;
                    cout << "\n";
                    
                    cout << y.size();
                    for (int m = 0; m < y.size(); m++)
                        cout << " " << y[m] + 1;
                    cout << "\n";
                    
                    cout << z.size();
                    for (int m = z.size() - 1; m >= 0; m--)
                        cout << " " << z[m] + 1;
                    cout << "\n";
                    exit(0);
                }
                else
                    cover[k] = make_pair (neigh, cloc);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        cover[i] = make_pair (-1, -1);
        seen[i] = false;
    }
    
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    for (int i = 0; i < N; i++)
    {
        if (!seen[i])
        {
            run(i, -1, 0);
        }
    }
    cout << "NO\n";
    return 0;
}