#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x = 0;
    long long a, b, c;
    string s[100];
    int n;
    cin >> n;
    long long buk[100];
    for (int i = 0; i < 100; i++)
        buk[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        buk[s[i][0]-'a']++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        a = buk[i-'a']/2;
        b = buk[i-'a']-a;
        x += a*(a-1)/2;
        x += b*(b-1)/2;
    }
    cout << x << endl;
    return 0;
}