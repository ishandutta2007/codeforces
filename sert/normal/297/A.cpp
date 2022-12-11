#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

typedef long long ll;

#define fr(i, n) for(int i = 0; i < n; i++)
const int N = 1e6 + 7;
const ll p = 503;
const ll md = 1e9 + 9;

string s1, s2;
int a1, a2;

int main(){

    cin >> s1 >> s2;
    fr(i, s1.length())
        a1 += s1[i] - '0';
    fr(i, s2.length())
        a2 += s2[i] - '0';
    a1 += a1 % 2;
    a2 += a2 % 2;
    if (a1 < a2) cout << "NO";
    else cout << "YES";

    return 0;
}