#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
    int N, K;
    int best = -1e9;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        int F, T;
        cin >> F >> T;
        if (T <= K)
            best = max (best, F);
        else
            best = max (best, F - T + K);
    }
    
    cout << best << "\n";
    return 0;
}