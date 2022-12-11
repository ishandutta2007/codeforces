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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), c = {0};
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(i&&a[i]==a[i-1])
            c.push_back(i);
    }
    c.push_back(n);
    int ans = 0;
    for(int i = 1; i<c.size(); i++)
        ans = max(ans, c[i]-c[i-1]);
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