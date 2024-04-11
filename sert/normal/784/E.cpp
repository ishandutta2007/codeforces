#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e7 + 34;
const ll M = (ll)1e9 + 34;

string R = "0101000?_10?_01_";
string q = "0100000011001010";
string t = "0101000011011011";

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a * 8 + b * 4 + c * 2 + d;
    cout << t[x];

    return 0;
}