#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
//    cout << "Hello, World!" << endl;
    int n, d; cin >> n >> d;
    int c = 0;
    int mx = 0;
    for (int i = 0; i < d; ++i)
    {
        string s; cin >> s;
        if (count(s.begin(), s.end(), '0'))
            mx = max(mx, ++c);
        else
            c = 0;
    }
    cout << mx << endl;
    return 0;
}