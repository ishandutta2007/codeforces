#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 500100;
const ll MOD = 1e13 + 7;
const ll POW = 4e5 + 13;

int Q;

int N;
int arr[MAXN];

vector <int> q;
vector <ll> chash;
map <ll, int> mm;

void roll()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    q.clear();
    chash.clear();
    mm.clear();

    mm[0] = 1;
    chash.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int c = arr[i];
        if (q.size() > 0 && q.back() == c)
        {
            q.pop_back();
            chash.pop_back();
        }
        else
        {
            q.push_back(c);
            chash.push_back((chash.back() * POW + c) % MOD);
        }

        mm[chash.back()] += 1;
    }

    ll ans = 0;
    for (auto it = mm.begin(); it != mm.end(); it++)
    {
        ll k = it->second;
        ans += (k * (k - 1)) / 2;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> Q;
    for (int c = 0; c < Q; c++)
        roll();
}