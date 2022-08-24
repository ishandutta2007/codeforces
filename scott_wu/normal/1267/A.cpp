#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll A[MAXN], B[MAXN], T[MAXN];
multiset <ll> cv;
vector <pair <ll, int> > event;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i] >> T[i];
        event.push_back(make_pair (A[i] + T[i], i));
        event.push_back(make_pair (B[i], i + N));
    }

    ll res = 0;
    sort (event.begin(), event.end());
    cv.insert(2e18);
    ll nlast = -1; // actionable

    for (int i = 0; i + 1 < event.size(); i++)
    {
        int e = event[i].second;
        if (e < N)
        {
            cv.insert(T[e]);
            if (nlast <= A[e])
            {
                res++;
                nlast = A[e] + T[e];
            }
        }
        else
        {
            cv.erase(cv.find(T[e-N]));
        }

        ll nv = *cv.begin();
        ll nadd = (event[i+1].first - nlast) / nv;
        res += nadd;
        nlast += nadd * nv;
    }
    cout << res << "\n";
}