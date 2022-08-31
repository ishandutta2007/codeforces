#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

ll v4 = 204761410474LL;
ll v3 = 2046;
ll v34 = 20468426;

ll lo, hi, nq;

void query (vector <ll> x)
{
    cout << x.size();
    for (int i = 0; i < x.size(); i++)
        cout << " " << x[i];
    cout << endl;
    nq--;

    int r;
    cin >> r;
    if (r < 0)
        exit(0);

    if (r < x.size())
        hi = min (hi, x[r] - 1);
    if (r > 0)
        lo = max (lo, x[r-1] + 1);
}

void run_round()
{
    if (lo >= 10000)
    {
        ll clen = hi - lo + 1;

        ll rlen = clen / (10001);
        vector <ll> p;
        ll cc = lo;
        for (int k = 0; k < 10000; k++)
        {
            cc += rlen;
            p.push_back(cc);
            cc++;
        }        
        query(p);
        return;
    }

    if (nq == 1)
    {
        vector <ll> p;
        for (ll i = lo; i <= hi; i++)
            p.push_back(i);
        query(p);
        return;
    }
    if (nq == 2)
    {
        vector <ll> p;

        ll llo = lo;
        for (int i = 0; i < lo; i++)
        {
            llo = llo + min (llo, 10000LL);
            p.push_back(llo);
            llo++;
        }
        query(p);  
        return;      
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    lo = 1; hi = 10004205361450474LL; nq = 5;

    vector <ll> v, p;
    v.push_back(v4);
    query(v);

    if (lo == 1)
    {
        v.clear();
        v.push_back(v3);
        query(v);
        v.clear();
        if (lo == 1)
        {
            v.push_back(6);
            query(v);
            v.clear();
            for (int i = 0; i < 2; i++)
                run_round();
        }
        else
        {
            ll cc = 100020000LL;
            ll cur = hi;
            for (int i = 0; i < 2047; i++)
            {
                cur -= cc;
                p.push_back(cur);
                cur--;
            }
            reverse(p.begin(), p.end());
            query(p);
            for (int i = 0; i < 2; i++)
                run_round();
        }
    }
    else
    {
        for (int c = 0; c < 4; c++)
        {
            run_round();
        }
    }
}