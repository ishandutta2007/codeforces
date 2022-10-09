#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fs first
#define sc second
#define mp make_pair

int main() {
    ios::sync_with_stdio(0);
    long long ans = 1;
    int n;
    vector<int> a = {4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985, 1086, 1111, 1165};
    cin >> n;
    cout << a[n - 1] << endl;
    return 0;
}