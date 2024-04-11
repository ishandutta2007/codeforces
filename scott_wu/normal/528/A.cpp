#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int W, H, N;
int wnext[MAXN], wprev[MAXN];
bool wloc[MAXN], hloc[MAXN];
int hnext[MAXN], hprev[MAXN];
int wmax, hmax;

bool cval[MAXN];
int cloc[MAXN];
ll ans[MAXN];

int main()
{
    for (int i = 0; i < MAXN; i++)
        wloc[i] = hloc[i] = false;
    
    cin >> W >> H >> N;
    for (int i = 0; i < N; i++)
    {
        char ch;
        int k;
        cin >> ch >> k;
        
        cval[i] = (ch == 'H');
        cloc[i] = k;
        
        if (cval[i])
            hloc[k] = true;
        else
            wloc[k] = true;
    }
    
    wmax = hmax = 0;
    int pw = 0;
    for (int i = 1; i <= W - 1; i++)
    {
        if (wloc[i])
        {
            wnext[pw] = i;
            wprev[i] = pw;
            wmax = max (wmax, i - pw);
            pw = i;
        }
    }
    wnext[pw] = W;
    wprev[W] = pw;
    wmax = max (wmax, W - pw);
    
    int ph = 0;
    for (int i = 1; i <= H - 1; i++)
    {
        if (hloc[i])
        {
            hnext[ph] = i;
            hprev[i] = ph;
            hmax = max (hmax, i - ph);
            ph = i;
        }
    }
    hnext[ph] = H;
    hprev[H] = ph;
    hmax = max (hmax, H - ph);
    
    for (int i = N - 1; i >= 0; i--)
    {
        ans[i] = hmax * (ll) wmax;
        if (cval[i])
        {
            int n = cloc[i];
            hmax = max (hmax, hnext[n] - hprev[n]);
            hnext[hprev[n]] = hnext[n];
            hprev[hnext[n]] = hprev[n];
        }
        else
        {
            int n = cloc[i];
            wmax = max (wmax, wnext[n] - wprev[n]);
            wnext[wprev[n]] = wnext[n];
            wprev[wnext[n]] = wprev[n];
        }
    }
    
    for (int i = 0; i < N; i++)
        cout << ans[i] << "\n";
    return 0;
}