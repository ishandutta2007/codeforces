#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef double ld;
const ll N = 103;

string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    fr(i, s.length())
        if (s[i] != '1' && s[i] != '4') {
            cout << "NO";
            return 0;
        }
    fr(i, s.length() - 2) {
        if (s[i] == '4' && s[i + 1] == '4' && s[i + 2] == '4') {
            cout << "NO";
            return 0;
        }
    }
    if (s[0] == '4') cout << "NO";
    else cout << "YES";

    return 0;
}