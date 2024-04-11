#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 0; x <= 10000; ++x) {
        if (a * x <= c && (c - a * x) % b == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No";
    return 0;
}