#include <bits/stdc++.h>
using namespace std;

int main()
{
    map <long long, long long> roots;
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        long long eq = 0;
        for(char c : s)
        {
            eq |= (1 << (c - 'a'));
        }
        roots[eq]++;
    }
    cout << roots.size();
}