#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXT = 62;

int R, C, T;
char c[MAXT];
ll r1score[MAXT];
ll rscore[MAXT];
ll lscore[MAXT];
ll mval;

map <pair <ll, int>, ll> mmap; // [tot sum, # A's] -> ncount
map <pair <ll, int>, ll> nmap;

ll choose (int x, int y)
{
    if (y > x || y < 0) return 0;
    ll res = 1;
    for (int i = 0; i < y; i++)
    {
        res = res * (x - i);
        res = res / (i + 1);
    }
    //cout << x << " " << y << " " << res << "\n";
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> R >> C;
    T = (2 * R + 2 * C);
    for (int i = 0; i < T; i++)
        cin >> c[i];

    for (int i = 0; i < MAXT; i++)
        lscore[i] = 0;
    lscore[2*R-1] = 1;
    for (int i = 2 * R; i < T; i++)
    {
        lscore[i] = lscore[i-1] * i / ((ll) i - 2 * R + 1);
        //cout << i << " " << lscore[i] << "\n";
    }
    for (int i = 0; i <= T; i++)
    {
        r1score[i] = choose (i, R - 1);
        rscore[i] = choose (i, R);
    }

    mval = 0;
    int acnt = 0, bcnt = 0;
    for (int i = T - 1; i >= 0; i--)
    {
        bool u = mval > 0;
        if (bcnt == T / 2)
            u = true;
        if (acnt == T / 2)
            u = false;

        if (u)
        {
            acnt++;
            mval -= r1score[T / 2 - acnt] * rscore[T / 2 - bcnt];
        }
        else
        {
            bcnt++;
            mval += r1score[T / 2 - bcnt] * rscore[T / 2 - acnt];
        }
    }
    mval = max(mval, -mval);

    //cout << "mval " << mval << "\n";

    ll tsum = 0;
    for (int i = 0; i < T; i++)
    {
        tsum += lscore[i];
    }

    tsum = rscore[T/2] * rscore[T/2];

    mmap[make_pair(0, 0)] = 1;
    for (int i = T - 1; i >= 2 * R - 1; i--)
    {
        nmap.clear();
        for (map<pair<ll, int>, ll>::iterator it = mmap.begin(); it != mmap.end(); it++)
        {
            ll sum = it->first.first;
            ll acnt = it->first.second;
            ll ncount = it->second;

            int aleft = T / 2 - acnt;
            int bleft = i + 1- aleft;

            ll asum = sum + r1score[aleft - 1] * rscore[bleft];
            ll bsum = sum - r1score[bleft - 1] * rscore[aleft];

            if (c[i] == 'A')
            {
                nmap[make_pair(asum, acnt + 1)] += ncount;
                nmap[make_pair(bsum, acnt)] += 0;
            }
            else if (c[i] == 'B')
            {
                nmap[make_pair(asum, acnt + 1)] += 0;
                nmap[make_pair(bsum, acnt)] += ncount;
            }
            else
            {
                nmap[make_pair(asum, acnt + 1)] += ncount;
                nmap[make_pair(bsum, acnt)] += ncount;
            }
        }
        tsum -= lscore[i];

        mmap.clear();
        for (map<pair<ll, int>, ll>::iterator it = nmap.begin(); it != nmap.end(); it++)
        {
            ll sum = it->first.first;
            int acnt = it->first.second;
            ll ncount = it->second;

            //cout << i << " " << sum << " " << tsum << " " << ncount << "\n";

            int aleft = T / 2 - acnt;
            int bleft = i - aleft;
            if (acnt > (T / 2) || (T - i - acnt) > (T / 2))
                continue;   
            ll lsum = rscore[aleft] * rscore[bleft];
            if (sum < (-mval - lsum) || sum > (mval + lsum))
                continue;
            mmap[make_pair(sum, acnt)] += ncount;
        }
    }

    ll bscore = (ll) 1e18;
    for (map<pair<ll, int>, ll>::iterator it = mmap.begin(); it != mmap.end(); it++)
    {
        ll sum = it->first.first;
        bscore = min (bscore, max (sum, -sum));
    }

    //cout << "bscore " << bscore << "\n";

    ll ans = 0;
    for (map<pair<ll, int>, ll>::iterator it = mmap.begin(); it != mmap.end(); it++)
    {
        ll sum = it->first.first;
        int acnt = it->first.second;
        ll ncount = it->second;

        if (sum == bscore || sum == -bscore)
        {
            //cout << sum << " " << acnt << " " << ncount << "\n";
            int nleft = 0;
            for (int i = 0; i < 2 * R - 1; i++)
            {
                if (c[i] == 'A')
                    acnt++;
                if (c[i] == '?')
                    nleft++;
            }

            ncount *= choose (nleft, T / 2 - acnt);
            ans += ncount;
        }
    }

    cout << ans << "\n";
    return 0;
}