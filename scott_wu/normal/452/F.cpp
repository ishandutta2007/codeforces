#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int arr[MAXN];

bool w2 (vector <int> v)
{
    vector <int> olo, ohi;
    int lo = 1e9, hi = -1e9;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] % 2 == 1)
        {
            lo = min (lo, v[i]);
            hi = max (hi, v[i]);
        }
        olo.push_back (lo);
        ohi.push_back (hi);
    }
    
    lo = 1e9, hi = -1e9;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 1)
        {
            lo = min (lo, v[i]);
            hi = max (hi, v[i]);
        }
        else
        {
            if (lo < 1e8 && olo[v.size()-1-i] < 1e8)
            {
                int c = lo + olo[v.size()-1-i];
                int d = hi + ohi[v.size()-1-i];
                
                if (c <= 2 * v[i] && 2 * v[i] <= d)
                    return false;
            }
        }
    }
    return true;
}

bool works (vector <int> v)
{
    if (v.size() <= 1)
        return true;
    
    if (!w2(v))
        return false;
    int M = v.size();
    for (int i = 0; i < M; i++)
        v[i]--;
    if (!w2(v))
        return false;
    for (int i = 0; i < M; i++)
        v[i]++;
    
    vector <int> l, r;
    for (int i = 0; i < M; i++)
    {
        if (v[i] % 2 == 1)
            l.push_back ((v[i] + 1) / 2);
        else
            r.push_back (v[i] / 2);
    }
    return works (l) && works (r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    vector <int> v;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        v.push_back (arr[i]);
    }
    
    if (!works (v))
        cout << "YES\n";
    else
        cout << "NO\n";
    //system ("Pause");
    return 0;
}