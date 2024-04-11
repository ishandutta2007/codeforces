#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char a, b;
    int res = 8;
    cin >> a >> b;
    if(a == 'a' || a == 'h') res -= 3;
    if(b == '1' || b == '8') res -= 3;
    if(res == 2) res ++;
    cout << res << endl;
}