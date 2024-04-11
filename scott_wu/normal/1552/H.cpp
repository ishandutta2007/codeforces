#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 200;
const int MAXB = 40100;

vector <int> v[MAXB];

void gogo()
{
    
}

int test (int A, int m)
{
    map <int, int> mm;
    for (int x : v[A])
    {
        int y = A / x;
        int a1 = (x / m) * y, a2 = ((x - 1) / m + 1) * y;
        int b1 = (y / m) * x, b2 = ((y - 1) / m + 1) * x;
        //int c1 = (x / n) * y, c2 = ((x - 1) / n + 1) * y;
        //int d1 = (y / n) * x, d2 = ((y - 1) / n + 1) * x;

        mm[a1*N+b1]++;
        if (b1 != b2) mm[a1*N+b2]++;
        if (a1 != a2)
        {
            mm[a2*N+b1]++;
            if (b1 != b2) mm[a2*N+b2]++;
        }
    }

    int res = 0;
    for (auto it : mm)
        res = max (res, it.second);
    return res;
}

int test2 (int A, int m, int n, bool say = false)
{
    map <int, int> mm;
    for (int x : v[A])
    {
        int y = A / x;
        int a1 = (x / m) * y, a2 = ((x - 1) / m + 1) * y;
        int b1 = (y / m) * x, b2 = ((y - 1) / m + 1) * x;
        int c1 = (x / n) * y, c2 = ((x - 1) / n + 1) * y;
        //int d1 = (y / n) * x, d2 = ((y - 1) / n + 1) * x;

        for (int p = 0; p < 2; p++)
        {
            int nall = c1 * N * N;
            if (p == 1) nall = c2 * N * N;
            if (p == 1 && c1 == c2) continue;

            mm[nall+a1*N+b1]++;
            if (b1 != b2) mm[nall+a1*N+b2]++;
            if (a1 != a2)
            {
                mm[nall+a2*N+b1]++;
                if (b1 != b2) mm[nall+a2*N+b2]++;
            }
        }
    }

    int res = 0;
    for (auto it : mm)
        res = max (res, it.second);
    for (auto it : mm)
        if (say && it.second >= 3)
        {
            vector <pair <int, int> > c;
            //cout << A << " " << m << " " << res << " " << it.first % N << " " << (it.first / N) % N << "\n";
            for (int x : v[A])
            {
                int y = A / x;
                int a1 = (x / m) * y, a2 = ((x - 1) / m + 1) * y;
                int b1 = (y / m) * x, b2 = ((y - 1) / m + 1) * x;
                if (a1 == (it.first / N) % N || a2 == (it.first / N) % N)
                    if (b1 == it.first % N || b2 == it.first % N)
                    {
                        //cout << x << " " << y << "\n";
                        c.push_back (make_pair (x, y));
                    }
            }
            int nfound = -1;
            for (int j = 1; j <= N; j++)
            {
                for (int k = 1; k <= N; k++)
                {
                    map <int, int> cmm;
                    for (auto pp : c)
                    {
                        int x = pp.first, y = pp.second;
                        int a1 = (x / j) * y, a2 = ((x - 1) / j + 1) * y;
                        int b1 = (y / k) * x, b2 = ((y - 1) / k + 1) * x;
                        cmm[a1*MAXB+b1]++;
                        if (a1 != a2) cmm[a2*MAXB+b1]++;
                        if (b1 != b2)
                        {
                            cmm[a1*MAXB+b2]++;
                            if (a1 != a2) cmm[a2*MAXB+b2]++;
                        }
                    }

                    int mmax = 0;
                    for (auto pp : cmm)
                        mmax = max (mmax, pp.second);
                    if (mmax == 1)
                    {
                        nfound = j * MAXB + k;
                        break;
                    }
                }
            }
            if (nfound == -1)
            {
                cout << A << " " << m << " " << res << " " << it.first % N << " " << (it.first / N) % N << "\n";
                for (auto pp : c)
                    cout << pp.first << " " << pp.second << "\n";
            }
        }
    return res;
}

int ask (int x, int y)
{
    vector <pair <int, int> > res;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i % x == 0 && j % y == 0)
                res.push_back (make_pair (i, j));
        }

    cout << "? " << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        if (i) cout << " ";
        cout << res[i].first + 1 << " " << res[i].second + 1;
    }
    cout << "\n" << flush;

    int r; cin >> r;
    return r;
}

int answer (int x)
{
    cout << "! " << x << "\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);

    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
        {
            v[i*j].push_back(i);
        }

    int area = ask (1, 1);
    int A = area;
    for (int i = 1; i < MAXB; i++)
    {
        if (i != area) continue;
        if (v[i].size() > 1)
        {
            int np = MAXB, nloc = -1;
            for (int j = 1; j <= N; j++)
            {
                int nv = test (i, j);
                if (nv == np)
                {
                    nloc = j;
                }
                else if (nv < np)
                {
                    np = nv;
                    nloc = j;
                }
            }

            int horiz = ask (nloc, 1);
            int vert = ask (1, nloc);
            vector <pair <int, int> > c;
            int m = nloc;
            for (int x : v[i])
            {
                int y = A / x;
                int a1 = (x / m) * y, a2 = ((x - 1) / m + 1) * y;
                int b1 = (y / m) * x, b2 = ((y - 1) / m + 1) * x;
                if (a1 == horiz || a2 == horiz)
                    if (b1 == vert || b2 == vert)
                    {
                        c.push_back (make_pair (x, y));
                    }
            }

            if (c.size() > 1)
            {
                int nfound = -1;
                for (int j = 1; j <= N; j++)
                {
                    if (nfound != -1) break;
                    for (int k = 1; k <= N; k++)
                    {
                        map <int, int> cmm;
                        for (auto pp : c)
                        {
                            int x = pp.first, y = pp.second;
                            int a1 = (x / j) * y, a2 = ((x - 1) / j + 1) * y;
                            int b1 = (y / k) * x, b2 = ((y - 1) / k + 1) * x;
                            cmm[a1*b1]++;
                            if (a1 != a2) cmm[a2*b1]++;
                            if (b1 != b2)
                            {
                                cmm[a1*b2]++;
                                if (a1 != a2) cmm[a2*b2]++;
                            }
                        }

                        int mmax = 0;
                        for (auto pp : cmm)
                            mmax = max (mmax, pp.second);
                        if (mmax == 1)
                        {
                            nfound = j * MAXB + k;
                            break;
                        }
                    }
                }

                int ares = nfound / MAXB, bres = nfound % MAXB;
                int fin = ask (ares, bres);

                for (auto pp : c)
                {
                    int x = pp.first, y = pp.second;
                    int a1 = (x / ares), a2 = ((x - 1) / ares + 1);
                    int b1 = (y / bres), b2 = ((y - 1) / bres + 1);
                    //cout << x << " " << y << " " << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";
                    if (a1 * b1 == fin || a1 * b2 == fin || a2 * b1 == fin || a2 * b2 == fin)
                        answer (2 * x + 2 * y - 4);
                }
            }
            else
            {
                int res = c[0].first + c[0].second;
                answer (res * 2 - 4);
            }
            /*if (np > 2)
            {
                bool found = false;
                test2 (i, nloc, 1);
                for (int j = 1; j <= N; j++)
                {
                    if (test2 (i, nloc, j) < 2)
                        found = true;
                }
                if (!found)
                {
                    test2 (i, nloc, 1, 1);
                    cout << "YO " << i << " " << nloc << " " << np << "\n";
                    cout << "\n\n";
                }
            }*/
        }
        else
        {
            int x = v[i][0];
            int y = i / x;
            answer (x + x + y + y - 4);
        }
    }
}