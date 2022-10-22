#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 50005;
int n , m , B , Q;
string S , X , Y;
map<string , int> hash;
vector<int> C[N << 2];
vector<int>::iterator it;
int id[N << 2] , res[300][N << 2] , len[N << 2];
void work() {
    int i , j , k;
    cin >> S;
    for (i = 0 ; i < S.size() ; ++ i) {
        string tmp = "";
        for (j = 1 ; j <= 4 && i + j - 1 < S.size() ; ++ j) {
            tmp += S[i + j - 1];
            if (!hash[tmp])
                hash[tmp] = ++ n , len[n] = j;
        }
    }
    for (i = 0 ; i < S.size() ; ++ i) {
        string tmp = "";
        for (j = 1 ; j <= 4 && i + j - 1 < S.size() ; ++ j) {
            tmp += S[i + j - 1];
            C[hash[tmp]].push_back(i);
        }
    }
    B = 299;
    //cout << hash["ab"] << endl;
    //cout << hash["d"] << endl;

    for (i = 1 ; i <= n ; ++ i) {
        if (C[i].size() > B) {
            id[i] = ++ Q;
            for (j = 1 ; j <= n ; ++ j) {
                res[Q][j] = 1 << 30; int& ans = res[Q][j];
                for (k = 0 ; k < C[j].size() ; ++ k) {
                    it = lower_bound(C[i].begin() , C[i].end() , C[j][k]);
                    if (it != C[i].end())
                        ans = min(ans , max(len[j] , *it - C[j][k] + len[i]));
                    if (it != C[i].begin()) {
                        -- it;
                        ans = min(ans , max(len[i] , C[j][k] - *it + len[j]));
                    }
                }
            }
        }
    }
    scanf("%d",&m);
    while (m --) {
        cin >> X >> Y;
        if (!hash.count(X) || !hash.count(Y)) {
            puts("-1");
            continue;
        }
        int x = hash[X] , y = hash[Y];
        if (C[x].size() < C[y].size())
            swap(X , Y) , swap(x , y);
        int ans = 1 << 30;
        if (C[x].size() <= B) {
            for (i = 0 ; i < C[x].size() ; ++ i) {
                it = lower_bound(C[y].begin() , C[y].end() , C[x][i]);
                if (it != C[y].end())
                    ans = min(ans , max((int)X.size() , *it - C[x][i] + (int)Y.size()));
            }
            for (i = 0 ; i < C[y].size() ; ++ i) {
                it = lower_bound(C[x].begin() , C[x].end() , C[y][i]);
                if (it != C[x].end())
                    ans = min(ans , max((int)Y.size() , *it - C[y][i] + (int)X.size()));
            }
            printf("%d\n" , ans);
        } else {
            printf("%d\n" , res[id[x]][y]);
        }
    }
}

int main()
{
    work();
    return 0;
}