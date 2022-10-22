#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 2005;

int n;
vector< pair<int , int> > L , R;

void work() {
    scanf("%d" , &n);
    while (n --) {
        int x , y;
        scanf("%d%d" , &x , &y);
        if (x > 0) {
            R.push_back(make_pair(x , y));
        } else {
            L.push_back(make_pair(-x , y));
        }
    }
    sort(L.begin() , L.end());
    sort(R.begin() , R.end());
    if (L.size() < R.size())
        swap(L , R);
    int m = R.size() , res = 0;
    for (int i = 0 ; i < m ; ++ i)
        res += R[i].second;
    for (int i = 0 ; i < L.size() && i <= m ; ++ i)
        res += L[i].second;
    cout << res << endl;    
}

int main() {
    work();
    return 0;
}