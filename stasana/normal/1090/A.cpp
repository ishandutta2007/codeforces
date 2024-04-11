#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //ifstream cin("digits.in");
    //ofstream cout("digits.out");
    int n;
    cin >> n;
    vector<pair<long long, long long> > a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i].second;
        for(int j = 0; j<a[i].second; j++){
            long long b;
            cin >> b;
            a[i].first = max(a[i].first, b);
        }
        a[i].first = -a[i].first;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for(int i = 1; i<n; i++)
        ans += (a[i].first-a[0].first)*a[i].second;
    cout << ans;

    return 0;
}
///aaaaa.aaaab..ab
/*
3 3
1 2 0
2 3 1
1 2
1 3
2 3
*/