#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 3e5+5;

int main()
{
    string s;
    cin >> s;
    int x = s.back() - '0';
    cout << (x & 1);
}