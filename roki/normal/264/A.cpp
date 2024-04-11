#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
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
    forn (i, s.size())
        if(s[i] == 'r')
            cout << i + 1 << endl;
    forn (i, s.size())
        if(s[s.size() - 1 - i] == 'l')
            cout << s.size() - i << endl;
    return 0;
}