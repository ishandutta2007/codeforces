#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int ans[3];
    string res[3] = {"chest", "biceps", "back"};
    ans[0] = ans[1] = ans[2] = 0;
    
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int k; cin >> k;
        ans[i%3] += k;
    }
    if (ans[0] > max (ans[1], ans[2]))
        cout << res[0] << "\n";
    else if (ans[1] > ans[2]) cout <<res[1] << "\n";
    else cout << res[2] << "\n";
    return 0;
}