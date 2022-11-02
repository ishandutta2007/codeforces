#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

string s;
vector < string > S;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i ++)
        for (int j = i; j < s.size(); j ++)
        {
            string buf = "";
            for (int k = i; k <= j; k ++)
                buf += s[k];
            S.push_back(buf);
        }
    sort(S.begin(), S.end());
    int res = 0;
    for (int i = 1; i < S.size(); i ++)
        if (S[i] == S[i - 1])
            res = max(res, (int)S[i].size());
    cout << res << endl;
    return 0;
}