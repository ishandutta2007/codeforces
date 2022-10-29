#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int main()
{
    forn (i, 8)
    {
        string s = "1";
        forn (j, 8)
        {
            char c;
            cin >> c;
            s += c;
            if(s[j] == s[j + 1])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}