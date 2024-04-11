#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll A[MAXN];
ll B[MAXN];
ll C[MAXN];

ll ob[MAXN];

vector <int> v;

bool op()
{
    C[0] = B[0];
    for (int i = 1; i < N; i++)
        C[i] = B[i] - B[i-1];

    for (int i = 0; i < N; i++)
        if (C[i] <= 0) return false;
    for (int i = 0; i < N; i++)
        B[i] = C[i];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
        ob[i] = B[i];
    }

    if (N == 1)
    {
        if (A[0] == B[0])
        {
            cout << "SMALL\n";
            cout << "0\n";
            cout << "\n";
            return 0;
        }
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    bool bad = false;
    int vc = 0;
    while (v.size() < 2e6)
    {
        bool cf = true;
        for (int i = 0; i < N; i++)
            if (A[i] != B[i]) cf = false;
        if (cf)
        {
            break;
        }
        cf = true;
        for (int i = 0; i < N; i++)
            if (A[i] != B[N-1-i]) cf = false;
        if (cf)
        {
            v.push_back(1);
            break;
        }

        if (B[0] > B[N-1])
        {
            for (int i = 0; i < N / 2; i++)
                swap (B[i], B[N-1-i]);
            v.push_back(1);
            continue;
        }
        if (!op())
        {
            bad = true;
            break;
        }
        v.push_back(0);
        vc++;
    }

    if (v.size() < 1.9e6 && !bad)
    {
        if (vc > 200000)
        {
            cout << "BIG\n";
            cout << vc << "\n";
        }
        else
        {
            cout << "SMALL\n";
            cout << v.size() << "\n";
            reverse (v.begin(), v.end());
            for (int i : v)
            {
                if (i == 0)
                    cout << "P";
                else
                    cout << "R";
            }
            cout << "\n";
        }
        return 0;
    }

    ll vb = -1;
    if (N == 2)
    {
        for (int i = 0; i < N; i++)
            B[i] = ob[i];
        
        sort (A, A + 2);
        sort (B, B + 2);
        ll tt = 0;
        while (B[0])
        {
            if (A[0] == B[0])
            {
                if (A[1] <= B[1] && (A[1] % A[0] == B[1] % A[0]))
                {
                    tt += (B[1] - A[1]) / A[0];
                    vb = tt;
                }
                break;
            }

            ll nv = B[1] % B[0];
            tt += B[1] / B[0];
            B[1] = B[0];
            B[0] = nv;
        }
    }

    if (vb == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << "BIG\n";
        cout << vb << "\n";
    }
}