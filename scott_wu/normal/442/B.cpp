#include <iostream>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef long double ld;
const int MAXN = 110;

int N;
ld prob[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> prob[i];
    
    sort (prob, prob + N);
    reverse (prob, prob + N);
    
    ld c0 = 1.0, c1 = 0.0;
    ld res = -1.0;
    
    for (int i = 0; i < N; i++)
    {
        ld p = prob[i];
        c1 *= 1 - p;
        c1 += c0 * p;
        c0 *= 1 - p;
        
        if (c1 > res)
            res = c1;
    }
    
    cout << fixed << setprecision (10) << res << "\n";
    //system ("Pause");
    return 0;
}