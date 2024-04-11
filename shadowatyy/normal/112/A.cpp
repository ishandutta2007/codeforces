#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s1, s2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i]<97)
        {
            s1[i] += 32;
        }

        if(s2[i]<97)
        {
            s2[i] += 32;
        }
    }

    cout << s1.compare(s2);
}