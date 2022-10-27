#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int NICO = 1000 + 10;
string a, b, x, y;
int main()
{
    cin >> a >> b;
    cout << a << " " << b << endl;
    int n; cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x >> y;
        if(x==a) a = y;
        else b = y;
        cout << a << " " << b << endl;
    }
}