#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

string s1, s2, s3, s4;
int n1, n2, n3, n4, kol;
char ch;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    n1 = s1.length() - 2;
    n2 = s2.length() - 2;
    n3 = s3.length() - 2;
    n4 = s4.length() - 2;

    if (n1 * 2 <= n2 && n1 * 2 <= n3 && n1 * 2 <= n4) {ch = 'A'; kol++;}
    if (n1 >= n2 * 2 && n1 >= n3 * 2 && n1 >= n4 * 2) {ch = 'A'; kol++;}

    if (n2 * 2 <= n1 && n2 * 2 <= n3 && n2 * 2 <= n4) {ch = 'B'; kol++;}
    if (n2 >= n1 * 2 && n2 >= n3 * 2 && n2 >= n4 * 2) {ch = 'B'; kol++;}

    if (n3 * 2 <= n2 && n3 * 2 <= n1 && n3 * 2 <= n4) {ch = 'C'; kol++;}
    if (n3 >= n2 * 2 && n3 >= n1 * 2 && n3 >= n4 * 2) {ch = 'C'; kol++;}

    if (n4 * 2 <= n2 && n4 * 2 <= n3 && n4 * 2 <= n1) {ch = 'D'; kol++;}
    if (n4 >= n2 * 2 && n4 >= n3 * 2 && n4 >= n1 * 2) {ch = 'D'; kol++;}

    if (kol != 1) cout << "C\n"; else cout << ch;


    return 0;
}