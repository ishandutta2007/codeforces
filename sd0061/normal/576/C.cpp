#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n;
vector< pair<int , int> > X[N];
vector<int> res;
int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        X[x / 1000].push_back(make_pair(y , i));
    }
    for (int i = 0 ; i <= 1000 ; ++ i) {
        sort(X[i].begin() , X[i].end());
        if (i & 1)
            reverse(X[i].begin() , X[i].end());
        for (auto &it : X[i])
            printf("%d " , 1 + it.second);
    }   
    return 0;
}