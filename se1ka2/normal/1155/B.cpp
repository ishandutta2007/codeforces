#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int k = 0;
    for(int i = 10; i < n; i++) if(s[i] == '8') k++;
    if(k * 2 - 1 >= n - 10) cout << "YES" << endl;
    else cout << "NO" << endl;
}