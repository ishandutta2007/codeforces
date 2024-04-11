                            
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char s[100];
int main()
{
    int n;cin >> n;cin >> s;
    int tmp = 10 * (s[0] - '0') + s[1] - '0';
    if(n == 12)
    {
        if(tmp > 12)
        {
            if(s[1] == '0')
            {
                s[0] = '1';
            } else {
                s[0] = '0';
            }
        }
        if(tmp == 0)
        {
            s[1] = '1';
        }
    }
    
    if(n == 24)
    {
        if(tmp >= 24)
        {
            s[0] = '0';
        }
    }
    
    if(10 * (s[3] - '0') + s[4] - '0' >= 60)
    {
        s[3] = '0';
    }
    cout << s << endl;
}