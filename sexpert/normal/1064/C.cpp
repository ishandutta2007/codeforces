#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> ct;
    int n;
    cin >> n;
    string s, t = "";
    cin >> s;
    for(char c : s)
        ct[c]++;
    for(auto p : ct)
    {
        char c = p.first;
        int numApp = p.second;
        for(int i = 0; i < numApp; i++)
            t += c;
    }
    cout << t << endl;
}