#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    int lv = 0, ctot = 0, cbest = 0;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        if (x > 2 * lv)
        {
            ctot = 1;
        }
        else
            ctot++;
        lv = x;
        cbest = max (cbest, ctot);
    }
    cout << cbest << "\n";
}