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
    int l = 0;
    while(l < s.size() && s[l] == '1')
        l++;
    if(l == s.size())
        s.erase(0, 1);
    else
        s.erase(l, 1);
    cout << s << endl;
    return 0;
}