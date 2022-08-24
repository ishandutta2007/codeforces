#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 2100;
const int MAXD = 31;
const ll MOD = 1000000007;

int N, K;
vector <int> start;
vector <int> pow[MAXD];

vector <int> apply (vector <int> f, vector <int> s)
{
    vector <int> res;
    for (int i = 0; i < f.size(); i++)
        res.push_back (0);
    
    for (int i = 0; i < f.size(); i++)
        for (int j = 0; j < f.size() - i; j++)
            res[i+j] = (res[i+j] + (ll) f[i] * (ll) s[j]) % MOD;
    return res;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        start.push_back (num);
    }
    
    for (int i = 0; i < N; i++)
        pow[0].push_back (1);
    
    for (int i = 1; i < MAXD; i++)
        pow[i] = apply (pow[i-1], pow[i-1]);
    
    vector <int> res;
    for (int i = 0; i < N; i++)
        res.push_back (0);
    res[0] = 1;
    
    for (int i = 0; i < MAXD; i++)
        if (K & (1 << i))
            res = apply (res, pow[i]);
    res = apply (res, start);
    
    for (int i = 0; i < N; i++)
    {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    
    //system ("Pause");
    return 0;
}