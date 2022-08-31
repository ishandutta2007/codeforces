#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int a[MAXN];
int aloc[MAXN];
int b[MAXN];
int hval[MAXN];
int htype[MAXN];
int ans[MAXN];

priority_queue <pair <int, int> > h, h2; //val, ind, h = -1, h2 = +1
vector <int> htime[MAXN];

int main()
{
    while (!h.empty())
        h.pop();
    while (!h2.empty())
        h2.pop();
    for (int i = 0; i < MAXN; i++)
        hval[i] = htype[i] = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        aloc[a[i]] = i;
    }
    for (int i = 0; i < N; i++)
        cin >> b[i];
    
    for (int i = 0; i < N; i++)
        htime[(aloc[b[i]] - i + N) % N].push_back (i);
    
    for (int i = 0; i < N; i++)
    {
        int cmp = aloc[b[i]];
        if (i < cmp)
        {
            htype[i] = 1;
            hval[i] = -(cmp - i);
            h.push (make_pair (hval[i], i));
        }
        else
        {
            htype[i] = 2;
            hval[i] = -(i - cmp);
            h2.push (make_pair (hval[i], i));
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        int nmove = (N - i) % N;
        htype[nmove] = 1;
        hval[nmove] = -(aloc[b[nmove]] + i);
        h.push (make_pair (hval[nmove], nmove));
        
        while (!h.empty() && 
            (hval[h.top().second] != h.top().first || htype[h.top().second] != 1))
            h.pop();
        
        while (!h2.empty() && 
            (hval[h2.top().second] != h2.top().first || htype[h2.top().second] != 2))
            h2.pop();
        
        int best = N;
        if (!h.empty())
            best = min (best, -h.top().first - i);
        if (!h2.empty())
            best = min (best, -h2.top().first + i);
        
        //cout << h.top().second << " " << h2.top().second << "\n";
        
        /*for (int j = 0; j < N; j++)
            cout << hval[j] << " " << htype[j] << "\n";
        
        if (h2.empty())
            cout << "blah\n";
        cout << h.top().first << " " << h.top().second << " " << h2.top().first << " " << h2.top().second << "\n";*/
        ans[(N - i) % N] = best;
        
        for (int j = 0; j < htime[i].size(); j++)
        {
            nmove = htime[i][j];
            htype[nmove] = 2;
            hval[nmove] = -(-i);
            h2.push (make_pair (hval[nmove], nmove));
        }
    }
    
    for (int i = 0; i < N; i++)
        cout << ans[i] << "\n";
    
    //system ("Pause");
    return 0;
}