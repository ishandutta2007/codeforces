#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int P = (1 << 18);
const int MAXP = 2 * P + 100;

int N;
pair <int, int> pt[MAXN];
int xlist[MAXN];
int nx;
map <int, int> xmap; // xval to ord
int ny;
map <int, int> yord;
map <int, int> ymap; // yval to last x ord
map <int, int> ylast; // yval to last xov count
int np[MAXN];

int seg[MAXP];

void addto (int cloc)
{
    cloc += P;
    while (cloc)
    {
        seg[cloc]++;
        cloc /= 2;
    }
}

int getsum (int cloc)
{
    int res = 0;
    cloc += P;
    while (cloc > 1)
    {
        if (cloc & 1) res += seg[cloc-1];
        cloc /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> pt[i].first >> pt[i].second;
        pt[i].second = -pt[i].second;
        xmap[pt[i].first];
        yord[pt[i].second];
        ymap[pt[i].second] = -1;
    }
    sort (pt, pt + N);

    nx = ny = 0;
    for (map<int,int>::iterator it = xmap.begin(); it != xmap.end(); it++)
    {
        it->second = nx;
        xlist[nx] = it->first;
        nx++;
    }
    for (map<int,int>::iterator it = yord.begin(); it != yord.end(); it++)
    {
        it->second = ny++;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        np[i] = getsum(yord[pt[i].second] + 1) + 1;
        if (i == 0 || pt[i].first != pt[i-1].first)
            addto(yord[pt[i].second]);
        //cout << np[i] << "\n";
    }
    for (int i = 0; i < MAXP; i++)
        seg[i] = 0;

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || pt[i].first != pt[i-1].first)
        {
            addto(yord[pt[i].second]);
        }
        int cval = xmap[pt[i].first];
        int lval = ymap[pt[i].second];
        int hval = ylast[pt[i].second];
        int hnext = getsum(yord[pt[i].second] + 1);
        //ans += ((ll) cval - lval) * ((ll) nx - cval);
        ans += ((ll) (hnext - hval)) * ((ll) np[i]);
        //cout << hnext << " " << hval << " " << np[i] << "\n";
        ymap[pt[i].second] = cval;
        ylast[pt[i].second] = hnext;
    }
    cout << ans << "\n";
}