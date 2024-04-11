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
const ll N = 1e7+5;

string s[44];
bool check(int a, int b) {
    int k1 = 0;
    fr(q, 2) fr(w, 2)
    if (s[a + q][b + w] == '.') k1++;
    if (k1 != 2) {
        cout << "YES";
        exit(0);
    }
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    fr(i, 4)
        cin >> s[i];
    fr(i, 3)
        fr(j, 3)
            check(i, j);
    cout << "NO";


    return 0;
}