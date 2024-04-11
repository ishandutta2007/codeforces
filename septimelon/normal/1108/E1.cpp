#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int a[100000];
    int l[300], r[300];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    int ami = 1000000, ama = -1000000, d;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < ami)
            ami = a[i];
        if (a[i] > ama)
            ama = a[i];
    }
    d = ama - ami;

    int am[100000]/*, amz[100000]*/, km = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - ami < m)
        {
            am[km] = i;
            //amz[km] = a[i];
            km++;
        }
    }

    int ab[100000]/*, abz[100000]*/, kb = 0;
    for (int i = 0; i < n; i++)
    {
        if (ama - a[i] < m)
        {
            ab[kb] = i;
            kb++;
        }
    }

    /*cout << "am[]: ";
    for (int i = 0; i < km; i++)
        cout << a[am[i]] << " ";
    cout << endl;
    cout << "ab[]: ";
    for (int i = 0; i < kb; i++)
        cout << a[ab[i]] << " ";
    cout << endl;*/

    int dmi = d, imi = -1;
    int db, dm, mindm;
    for (int i = 0; i < km; i++)
    {
        //cout << endl << "i = " << i << ": ";
        dm = 0;
        for (int qqq = 0; qqq < m; qqq++)
            if (l[qqq] <= am[i] && am[i] <= r[qqq])
                dm++;
        //cout << "dm = " << dm << "; ";
        for (int j = 0; j < kb; j++)
        {
            db = 0;
            for (int qqq = 0; qqq < m; qqq++)
                if (l[qqq] <= ab[j] && ab[j] <= r[qqq] && l[qqq] <= am[i] && am[i] <= r[qqq])
                    db++;
            //cout << "d[" << j << "] = " << a[ab[j]] - db - a[am[i]] + dm << "; ";
            if (a[ab[j]] - db - a[am[i]] + dm > dmi)
                dmi = a[ab[j]] - db - a[am[i]] + dm;
        }
        if (dmi > d)
        {
            d = dmi;
            imi = i;
            mindm = dm;
        }
    }

    if (imi == -1)
    {
        cout << d << endl << 0;
        return 0;
    }

    cout << d << endl << mindm << endl;
    dm = 0;
    for (int qqq = 0; qqq < m; qqq++)
        if (l[qqq] <= am[imi] && am[imi] <= r[qqq])
            cout << qqq+1 << " ";


    return 0;
}