#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

#define clr(a) memset(a, 0, sizeof(a))
#define fori(a) for(int i = 0; i < a; i++)
#define ll long long

using namespace std;

set <string> S;


int main()
{
    int n;
    cin >> n;
    int ans = 0;
    fori(n)
    {
        string s1, s2;
        cin >> s1 >> s2;
        string s3 = s1 + '#' + s2;
        if (S.find(s3) == S.end())
        {
            S.insert(s3);
            ans++;
        }

    }
    cout << ans;

    return 0;
}