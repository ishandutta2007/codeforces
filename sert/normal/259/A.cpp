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
const ll N = 1e6+5;

string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    fr(i, 8) {
        cin >> s;
        if (s != "WBWBWBWB" && s != "BWBWBWBW") {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";



    return 0;
}