#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, K;
int P[MAXN];
int C[MAXN];
pair <int, int> ord[MAXN];
ll ans[MAXN];

int argmax[10];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        ord[i] = make_pair (P[i], i);
    }
    for (int i = 0; i < N; i++) cin >> C[i];
    sort (ord, ord + N);
    
    for (int i = 0; i < N; i++)
    {
        int cloc = ord[i].second;
        ll res = C[cloc];
        for (int j = 0; j < K; j++)
            res += argmax[j];
        ans[cloc] = res;
        
        if (argmax[0] < C[cloc])
        {
            argmax[0] = C[cloc];
            sort (argmax, argmax + K);
        }
    }
    
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}