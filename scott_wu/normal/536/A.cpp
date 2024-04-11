#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXM = 3000100;

int A, B, N;
ll val[MAXM];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> A >> B >> N;
    
    val[0] = A;
    for (int i = 1; i < MAXM; i++)
        val[i] = val[i-1] + B;
    
    for (int i = 0; i < N; i++)
    {
        int l;
        ll t, m;
        cin >> l >> t >> m;
        
        l--;
        
        if (t < val[l])
        {
            cout << "-1\n";
            continue;
        }
        
            int lo = l, hi = MAXM;
            while (lo < hi)
            {
                int mid = (lo + hi + 1) / 2;
                if (val[mid] > t || ((val[mid] + val[l]) * ((ll) mid - l + 1)) > 2 * t* m)
                    hi = mid - 1;
                else
                    lo = mid;
            }
            cout << lo + 1 << "\n";
    }
    
    return 0;
}