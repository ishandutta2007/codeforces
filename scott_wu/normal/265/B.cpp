#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N; cin >> N;
    
    int last = 0;
    int cur = 0;
    
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> cur;
        
        ans += abs (cur - last);
        last = cur;
    }
    
    ans += 2 * N - 1;
    cout << ans << "\n";
    return 0;
}