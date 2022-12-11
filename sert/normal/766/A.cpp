#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "dynasties"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;



int main() {
    //init();

    string s1, s2;
    cin >> s1 >> s2;
    cout << (s1 == s2 ? (int)-1 : (int)max(s1.length(), s2.length()));

    return 0;
}