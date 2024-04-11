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

int f(string s)
{
    vector<int> v(500, 0);
    forn (i, s.size())
        v[s[i]]++;
    int k = 0;
    forn (i, 500)
        if(v[i] % 2 == 1)
            k++;
    return k;
}

int main()
{
    string s;
    cin >> s;
    if(f(s) % 2 == 1 || f(s) == 0)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}