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
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    forn (i, t)
    {
        string next = s;
        forn (j, n)
        {
            if(j + 1 < n && s[j] == 'B' && s[j + 1] == 'G')
                swap(next[j], next[j + 1]);
        }
        s = next;
    }
    cout << s << endl;
    return 0;
}