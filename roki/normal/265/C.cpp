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
      char s[1000010];
    gets(s);
    int n = strlen(s);
    forn (i, n)
        if(s[i] == 'r')
            cout << i + 1 << endl;
    forn (i, n)
        if(s[n - 1 - i] == 'l')
            cout << n - i << endl;
    return 0;
}