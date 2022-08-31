#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;
typedef long long ll;
const int MAXN = 50100;
const int MAXD = 600000;

int N, Q;
string str;
map <pair <int, int>, int> mmap;
vector <int> loc[MAXD];

int conv (string s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        res = 27 * res + (s[i] - 'a' + 1);
    for (int i = s.length(); i < 4; i++)
        res *= 27;
    return res;
}

void init()
{
    int x;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= 4 && i + j <= N; j++)
        {
            x = conv (str.substr (i, j));
            loc[x].push_back (i);
        }
    }
}
            

int solve (string a, string b)
{
    int x = conv (a), y = conv (b);
    if (mmap.find (make_pair (x, y)) != mmap.end())
        return mmap[make_pair (x, y)];
    if (mmap.find (make_pair (y, x)) != mmap.end())
        return mmap[make_pair (y, x)];
    
    if (loc[x].size() > loc[y].size())
    {
        swap (a, b);
        swap (x, y);
    }
    if (loc[x].size() == 0)
        return -1;
    
    int res = 1e9;
    for (int i = 0; i < loc[x].size(); i++)
    {
        int lo = 0, hi = loc[y].size() - 1;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (loc[y][mid] < loc[x][i])
                lo = mid;
            else
                hi = mid - 1;
        }
        
        int start = min (loc[y][lo], loc[x][i]);
        int end = max (loc[y][lo] + b.size(), loc[x][i] + a.size());
        res = min (res, end - start);
        
        if (lo == loc[y].size() - 1) continue;
        ++lo;
        start = min (loc[y][lo], loc[x][i]);
        end = max (loc[y][lo] + b.size(), loc[x][i] + a.size());
        res = min (res, end - start);
    }
    mmap[make_pair (x, y)] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> str;
    N = str.length();
    
    init();
    
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        string a, b;
        cin >> a >> b;
        cout << solve (a, b) << "\n";
    }
    //system ("Pause");
    return 0;
}