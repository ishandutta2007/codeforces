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
    string s;
    cin >> s;
    int x = 0, y = 0; 
    forn (i, s.size())
    {
        if(s[i] == 'x')
            x++;
        else
            y++;
    }
    if(y > x)
    {
        forn (i, y - x)
            cout << 'y';
    }
    else
    {
        forn (i, x - y)
            cout << 'x';
    }
    return 0;
}