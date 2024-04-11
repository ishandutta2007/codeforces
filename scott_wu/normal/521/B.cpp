#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
const int MAXM = 100100;

int M;
pair <int, int> coord[MAXM];
bool use[MAXM];

map <pair <int, int>, int> mmap;
set <int> pq;

int count (int n)
{
    int ans = 0;
    for (int i = -1; i <= 1; i++)
    {
        pair <int, int> p = make_pair (coord[n].first + i, coord[n].second - 1);
        if (mmap.find(p) != mmap.end())
        {
            int k = mmap[p];
            if (!use[k])
                ans++;
        }
    }
    return ans;
}

bool good (int n)
{
    for (int i = -1; i <= 1; i++)
    {
        pair <int, int> p = make_pair (coord[n].first + i, coord[n].second + 1);
        if (mmap.find(p) != mmap.end())
        {
            int k = mmap[p];
            if (!use[k] && count(k) == 1)
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> coord[i].first >> coord[i].second;
        mmap[coord[i]] = i;
    }
    
    for (int i = 0; i < M; i++)
    {
        use[i] = false;
        if (good (i))
            pq.insert(i);
    }
    
    long long ans = 0;
    bool par = true;
    while (!pq.empty()) {
        int k;
        if (par)
            k = *pq.rbegin();
        else
            k = *pq.begin();
            
        //cout << k << endl;
        use[k] = true;
        pq.erase(k);
        
        for (int i = -3; i <= 3; i++)
        {
            for (int j = -3; j <= 3; j++)
            {
                int x = coord[k].first + j;
                int y = coord[k].second + i;
                if (mmap.find(make_pair (x, y)) != mmap.end()) {
                    int n = mmap[make_pair (x, y)];
                    if (!use[n]) {
                        if (good(n))
                            pq.insert(n);
                        else
                            pq.erase(n);
                    }
                }
            }
        }
        ans = (M * ans + k) % 1000000009;
        par = !par;
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}