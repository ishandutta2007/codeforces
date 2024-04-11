#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1000005;
int a1 , a2 , b1 , b2;
map<int , int> hash;
void dfs(int x , int d , vector< pair<int , int> >& A) {
    if (hash.count(x) && d >= hash[x])
        return;
    hash[x] = d;
    A.push_back(make_pair(x , d));
    if (x % 2 == 0)
        dfs(x / 2 , d + 1 , A);
    if (x % 3 == 0)
        dfs(x / 3 * 2 , d + 1 , A);
}

void work() {
    cin >> a1 >> b1 >> a2 >> b2;
    vector< pair<int , int> > A , B , C , D;

    hash.clear();
    dfs(a1 , 0 ,  A);
    hash.clear();
    dfs(b1 , 0 ,  B);
    hash.clear();
    dfs(a2 , 0 ,  C);
    hash.clear();
    dfs(b2 , 0 ,  D);
    sort(D.begin() , D.end());
    int res = 1 << 30;
    int a , b , c , d , i , j , k , l , x;
    for (i = 0 ; i < A.size() ; ++ i)
        for (j = 0 ; j < B.size() ; ++ j)
            for (k = 0 ; k < C.size() ; ++ k) {
                if ((LL)A[i].first * B[j].first % C[k].first) continue;
                if ((LL)A[i].first * B[j].first / C[k].first > 1e9) continue;
                l = lower_bound(D.begin() , D.end() , make_pair((int)((LL)A[i].first * B[j].first / C[k].first) , -1)) - D.begin();
                if (l == D.size()) continue;
                    if ((LL)A[i].first * B[j].first == (LL)C[k].first * D[l].first) {
                        x = A[i].second + B[j].second + C[k].second + D[l].second;
                        if (x < res)
                            res = x , a = i , b = j , c = k , d = l;
                    }
            }
    if (res == 1 << 30)
        puts("-1");
    else {
        printf("%d\n" , res);
        printf("%d %d\n" , A[a].first , B[b].first);
        printf("%d %d\n" , C[c].first , D[d].first);
    }


}

int main() {
    work();
    return 0;
}