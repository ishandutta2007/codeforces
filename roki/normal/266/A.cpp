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
    int n;
    cin >> n;
    vector<char> a(n);
    forn (i, n)
        cin >> a[i];
    forn (i, a.size() - 1)
    {
        if(a[i] == a[i + 1])
        {
            a.erase(a.begin() + i + 1);
            i--;
        }
    }
    cout << n - a.size() << endl;
    return 0;
}