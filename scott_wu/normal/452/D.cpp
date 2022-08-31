#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int K;
int n1, n2, n3, t1, t2, t3;
int m1[MAXN], m2[MAXN], m3[MAXN];

int main()
{
    cin >> K >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    for (int i = 0; i < MAXN; i++)
        m1[i] = m2[i] = m3[i];
    
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        int lo1 = 1e9, blo1 = -1;
        for (int j = 0; j < n1; j++)
            if (m1[j] < lo1)
            {
                lo1 = m1[j];
                blo1 = j;
            }
        
        int lo2 = 1e9, blo2 = -1;
        for (int j = 0; j < n2; j++)
            if (m2[j] < lo2)
            {
                lo2 = m2[j];
                blo2 = j;
            }
        
        int lo3 = 1e9, blo3 = -1;
        for (int j = 0; j < n3; j++)
            if (m3[j] < lo3)
            {
                lo3 = m3[j];
                blo3 = j;
            }
        
        int start = max (lo1, max (lo2 - t1, lo3 - t1 - t2));
        int end = start + t1 + t2 + t3;
        ans = max (ans, end);
        
        m1[blo1] = start + t1;
        m2[blo2] = start + t1 + t2;
        m3[blo3] = start + t1 + t2 + t3;
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}