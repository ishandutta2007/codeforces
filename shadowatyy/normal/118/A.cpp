#include <bits/stdc++.h>
#define ll long long
using namespace std;

string w;

string res;

bitset <207> vowels;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    vowels['A'] = 1;
    vowels['O'] = 1;
    vowels['Y'] = 1;
    vowels['E'] = 1;
    vowels['I'] = 1;
    vowels['U'] = 1;

    vowels['a'] = 1;
    vowels['o'] = 1;
    vowels['y'] = 1;
    vowels['e'] = 1;
    vowels['i'] = 1;
    vowels['u'] = 1;

    cin >> w;

    for(int i = 0; i < w.size(); i++)
    {
        if(w[i]<97)
        {
            w[i] += 32;
        }

        if(vowels[w[i]])
        {
            continue;
        }
        else
        {
            res = res + "." + w[i];
        }
    }

    cout << res;
}