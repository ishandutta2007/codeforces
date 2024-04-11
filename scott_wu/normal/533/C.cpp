#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int x, y, x2, y2;

int main()
{
    ios_base::sync_with_stdio(0);
    string poly = "Polycarp\n", vas = "Vasiliy\n";
    
    cin >> x >> y >> x2 >> y2;
    if (x <= x2 && y <= y2)
    {
        cout << poly;
        return 0;
    }
    
    int a = x + y, b = max (x2, y2);
    if (a <= b)
    {
        cout << poly;
        return 0;
    }
    cout << vas;
    return 0;
}