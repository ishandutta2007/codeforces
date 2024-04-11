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
const int P = (1 << 19);
const int MAXP = (1 << 20) + 100;

int N, M;
map <pair <int, int>, int> xmap;
map <pair <pair <int, int>, ll>, int> ymap;
pair <int, int> vid[MAXN];
pair <pair <int, int>, ll> chan[MAXN];
pair <int, int> crange[MAXN];
ll cscore[MAXN];

ll res;
pair <int, int> xres;
pair <pair <int, int>, ll> yres;

int ncoord;
map <int, int> coord;

pair <int, int> arr[MAXP];

void upd (int cloc, pair <int, int> cval)
{
    //cout << cloc << " " << cval.first << " " << cval.second << "\n";
    cloc += P;
    while (cloc)
    {
        arr[cloc] = max (arr[cloc], cval);
        cloc /= 2;
    }
}

pair <int, int> find (int x) // 0..x
{
    x++;
    x += P;
    pair <int, int> res = make_pair (-1e9, 0);
    
    while (x > 1)
    {
        if (x % 2 == 1)
            res = max (res, arr[x-1]);
        x /= 2;
    }
    
    return res;
}

void run()
{
    sort (vid, vid + N);
    sort (chan, chan + M);
    
    for (int i = 0; i < M; i++)
    {
        crange[i] = chan[i].first;
        cscore[i] = chan[i].second;
    }
    
    int cloc = 0, bmax = -1e9, bloc = 0;
    for (int i = 0; i < M; i++)
    {
        while (cloc < N && vid[cloc].first <= crange[i].first)
        {
            if (vid[cloc].second > bmax)
            {
                bmax = vid[cloc].second;
                bloc = cloc;
            }
            cloc++;
        }
        
        if (bmax >= crange[i].first)
        {
            ll nval = (min (crange[i].second, bmax) - crange[i].first) * cscore[i];
            if (nval > res)
            {
                //cout << bmax << " " << crange[i].second << " " << crange[i].first << " " << cscore[i] << " " << nval << "\n";
                res = nval;
                xres = vid[bloc];
                yres = chan[i];
            }
        }
    }
    
    coord.clear();
    for (int i = 0; i < N; i++)
        coord[vid[i].second];
    for (int i = 0; i < M; i++)
        coord[chan[i].first.second];
    
    ncoord = 0;
    for (map <int, int>::iterator it = coord.begin(); it != coord.end(); it++)
    {
        it->second = ncoord++;
    }
    
    for (int i = 0; i < MAXP; i++)
        arr[i] = make_pair (-1e9, 0);
    
    cloc = N - 1;
    for (int i = M - 1; i >= 0; i--)
    {
        while (cloc >= 0 && vid[cloc].first >= crange[i].first)
        {
            upd (coord[vid[cloc].second], make_pair (vid[cloc].second - vid[cloc].first, cloc));
            cloc--;
        }
        
        pair <int, int> rval = find (coord[crange[i].second]);
        if (rval.first * cscore[i] > res)
        {
            res = rval.first * cscore[i];
            xres = vid[rval.second];
            yres = chan[i];
            
            //cout << res << " " << crange[i].first << " " << crange[i].second << " " << cscore[i] << " " << vid[rval.second].first << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> vid[i].first >> vid[i].second;
        xmap[vid[i]] = i + 1;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> chan[i].first.first >> chan[i].first.second >> chan[i].second;
        ymap[chan[i]] = i + 1;
    }
    
    res = 0;
    run();
    
    for (int i = 0; i < N; i++)
        vid[i] = make_pair (-vid[i].second, -vid[i].first);
    for (int i = 0; i < M; i++)
        chan[i].first = make_pair (-chan[i].first.second, -chan[i].first.first);
    
    run();
    
    if (res == 0)
    {
        cout << res << "\n";
        return 0;
    }
    
    if (xres.first < 0)
        xres = make_pair (-xres.second, -xres.first);
    if (yres.first.first < 0)
        yres.first = make_pair (-yres.first.second, -yres.first.first);
    
    cout << res << "\n";
    cout << xmap[xres] << " " << ymap[yres] << "\n";
    
    return 0;
}