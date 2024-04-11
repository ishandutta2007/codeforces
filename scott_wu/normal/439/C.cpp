#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110000;

int N, K, P;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);


    cin >> N >> K >> P;
    int no = 0;
    vector <int> v;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
        {
            no++;
            v.push_back(i);
        }
    }

    if (no < K - P)
    {
        cout << "NO\n";
        return 0;
    }
    if (no % 2 != (K - P) % 2)
    {
        cout << "NO\n";
        return 0;
    }

    if ((no - (K - P)) / 2 + (N - no) < P)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < (K - P); i++)
    {
        if (P == 0 && i == 0)
        {
            vector <int> cv;
            for (int j = K - P; j < no; j++)
                cv.push_back(v[j]);
            for (int j = 0; j < N; j++)
                if (arr[j] % 2 == 0)
                    cv.push_back(j);
            cv.push_back(v[0]);
            cout << cv.size();
            for (int x : cv)
                cout << " " << arr[x];
            cout << "\n";
        }
        else
            cout << "1 " << arr[v[i]] << "\n";
    }
    if (!P)
        return 0;

    vector <vector <int> > pv;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0)
        {
            vector <int> cv;
            cv.push_back(i);
            pv.push_back(cv);
        }
    }
    for (int i = K - P; i < no; i += 2)
    {
        vector <int> cv;
        cv.push_back(v[i]);
        cv.push_back(v[i+1]);
        pv.push_back(cv);
    }
    if ( pv.size() < P)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < P - 1; i++)
    {
        cout << pv[i].size();
        for (int x : pv[i])
            cout << " " << arr[x];
        cout << "\n";
    }

    vector <int> mm;
    for (int i = P - 1; i < pv.size(); i++)
        for (int x : pv[i])
            mm.push_back(x);
    cout << mm.size();
    for (int x : mm)
        cout << " " << arr[x];
    cout << "\n";
}