#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, Q;
int par[MAXN];

int cfind (int x)
{
    if (x == par[x])
        return x;
    return par[x] = cfind (par[x]);
}

void uni (int x, int y)
{
    x = cfind (x);
    y = cfind (y);
    par[x] = y;
}

set <int> mset;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        par[i] = i;
    for (int i = 0; i < N - 1; i++)
        mset.insert(i);
    
    for (int i = 0; i < Q; i++)
    {
        int x, a, b;
        cin >> x >> a >> b;
        a--, b--;
        
        if (x == 1)
        {
            uni (a, b);
        }
        else if (x == 2)
        {
            if (b > a)
            {
                // [a, b)
                set<int>::iterator it = mset.lower_bound(a);
                
                for(; it != mset.end() && *it < b; mset.erase(it++)) {
                    uni (*it, (*it) + 1);
                }
            }
        }
        else
        {
            if (cfind (a) == cfind (b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
    return 0;
}