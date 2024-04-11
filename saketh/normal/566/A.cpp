#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
pair <string, int> val[MAXN];
bool use[MAXN];
int hnext[MAXN], hprev[MAXN];

priority_queue <pair <int, pair <int, int> > > pq; // dist, left, right
vector <pair <int, int> > ans;
int tot;

inline bool cmp (pair <string, int> left, pair <string, int> right)
{
    for (int i = 0; i < min (left.first.length(), right.first.length()); i++)
        if (left.first[i] != right.first[i])
            return left.first[i] < right.first[i];
    return left.first.length() < right.first.length();
}

int match (int x, int y)
{
    int res = 0;
    while (res < val[x].first.length() && res < val[y].first.length() && val[x].first[res] == val[y].first[res])
        res++;
    return res;
}

inline bool f (int loc)
{
    return val[loc].second < N;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> val[i].first;
        val[i].second = i;
        use[i] = true;
    }
    
    sort (val, val + 2 * N, cmp);
    for (int i = 0; i < 2 * N; i++)
    {
        hnext[i] = i + 1;
        hprev[i] = i - 1;
    }
    
    for (int i = 0; i < 2 * N - 1; i++)
        if (f (i) ^ f (i + 1))
            pq.push (make_pair (match (i, i + 1), make_pair (i, i + 1)));
    
    tot = 0;
    ans.clear();
    
    while (!pq.empty())
    {
        int d = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        
        if (!use[x] || hnext[x] != y)
            continue;
        
        tot += d;
        int left, right;
        if (f (x))
        {
            left = val[x].second;
            right = val[y].second - N;
        }
        else
        {
            left = val[y].second;
            right = val[x].second - N;
        }
        ans.push_back (make_pair (left, right));
        
        use[x] = use[y] = false;
        int hp = hprev[x], hn = hnext[y];
        if (hp != -1)
            hnext[hp] = hn;
        if (hn != 2 * N)
            hprev[hn] = hp;
        
        if (hp >= 0 && hn < 2 * N)
        {
            if (f (hp) ^ f (hn))
                pq.push (make_pair (match (hp, hn), make_pair (hp, hn)));
        }
    }
    
    cout << tot << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    
    return 0;
}