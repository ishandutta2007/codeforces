#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#define ll long long

using namespace std;

map <pair<int, int>, bool> p;
int n;

bool count(pair <int, int> a)
{
    ll w = 1;
    for (int i = 0; i < a.second; i++)
    {
        w *= a.first;
        if (w >= n) return false;
    }
    return true;
}
bool dfs(pair <int, int> a)
{
    if (p.find(a) != p.end())
    {
        return p[a];
    }
    if (a.second == 1)
    {
        pair <int, int> w;
        w = a;
        w.second = 2;
        if (! count(w))
        {
            p[a] = ((n - a.first) % 2 == 0);
            return p[a];
        }
    }

    if (!count(a)) {p[a] = true; return true;}
    pair <int, int> w1, w2;
    w1 = a;
    w2 = a;
    w1.first++;
    w2.second++;
    p[a] = !(dfs(w1) && dfs(w2));
    return p[a];
}


int main()
{
    int a, b;
    scanf("%d%d%d", &a, &b, &n);
    pair <int, int> A;
    A.first = a;
    A.second = b;
    if (a == 1)
    {
        pair <int, int> w;
        w.first = 1;
        w.second = b;
        pair <int, int> w1 = w;
        w1.first = 2;
        for (; count(w1); w.second++, w1.second++)
        {
            if (! dfs(w1))
            {
                if ((w.second - b) % 2 == 0)
                    cout << "Masha";
                else cout << "Stas";
                return 0;
            }
        }
        cout << "Missing";
        return 0;
    }
    if (dfs(A)) cout << "Masha";
    else cout << "Stas";



    return 0;
}