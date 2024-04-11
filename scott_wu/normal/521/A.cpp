#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int ans = 1;
    int n;
    int x[4];
    x[0] = x[1] = x[2] = x[3] = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'A') {
            x[0]++;
        } else if (ch == 'C') {
            x[1]++;
        } else if (ch == 'G') {
            x[2]++;
        } else if (ch == 'T') {
            x[3]++;
        }
    }
    
    sort (x, x + 4);
    
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        if (x[i] == x[3])
            cnt++;
    
    for (int i = 0; i < n; i++)
        ans = (ans * (long long) cnt) % 1000000007;
    cout << ans << "\n";
    
    //system ("Pause");
    return 0;
}