#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
string a, b;
int main()
{
    cin >> a >> b;
    if(a == b) cout << -1;
    else cout << max(a.length(), b.length());
}