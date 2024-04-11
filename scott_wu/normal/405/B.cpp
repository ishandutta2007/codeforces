#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string str;
    
    cin >> N >> str;
    int lval = -1;
    char lc = '.';
    
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (str[i] == 'L' || str[i] == 'R')
        {
            if (str[i] == 'L' && lval >= 0 && (i + lval) % 2 == 0)
                ans++;
            if (str[i] == 'R')
                ans += i - lval - 1;
            lval = i;
            lc = str[i];
        }
    }
    if (lc == 'L')
        ans += N - lval - 1;
    if (lc == '.')
        ans = N;
    cout <<ans << "\n";
   }