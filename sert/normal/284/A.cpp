#include <iostream>

using namespace std;

int n, t, ans;
bool fail;

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        t = i;
        fail = false;
        for (int j = 2; j < n && !fail; j++) {
            if (t == 1) fail = true;
            t = (t * i) % n;
        }
        ans += !fail;
        //if (!fail) cout << i << "\n";
    }
    cout << ans;
    return 0;
}