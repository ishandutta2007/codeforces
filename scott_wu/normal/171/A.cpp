#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int conv (string x)
{
    int res = 0;
    for (int i = 0; i < x.length(); i++)
        res = res * 10 + (x[i] - '0');
    return res;
}

int main()
{
    int a;
    string b;
    cin >> a >> b;
    for (int i = 0; i < b.length() / 2; i++)
        swap (b[i], b[b.length()-1-i]);
    int c = conv (b);
    cout << a + c << "\n";
    //system ("Pause");
    return 0;
}