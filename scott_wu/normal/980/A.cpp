#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M;
string s;

int main()
{
    cin >> s;
    N = M = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
            N++;
        else
            M++;
    }

    if (M == 0 || N % M == 0)
    {
        cout << "YeS";
    }
    else
        cout << "no\n";
}