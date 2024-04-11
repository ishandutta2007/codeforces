#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#include <queue>
#include <map>
using namespace std;
const int N = 105;
typedef long long LL;
int n , m;
int a[N] , b[N] , c[N];
map< pair<int , int> , pair<int , int> > Hash;

void dfs(int k , int A , int B , int C , int M) {
    if (k == m) {
        pair<int , int> P(make_pair(B - A , C - A));
        if (!Hash.count(P))
            Hash[P] = make_pair(A , M);
        else
            Hash[P] = max(Hash[P] , make_pair(A , M));            
    } else {
        dfs(k + 1 , A + a[k] , B + b[k] , C , M | 0 << k + k);
        dfs(k + 1 , A + a[k] , B , C + c[k] , M | 1 << k + k);
        dfs(k + 1 , A , B + b[k] , C + c[k] , M | 2 << k + k);        
    }
}
int res = -1 << 30;
int F , S;
char ans[3][4] = {"LM" , "LW" , "MW"};
int DFS(int k , int A , int B , int C , int M) {
    if (k == n) {
        pair<int , int> P(make_pair(A - B , A - C));
        if (Hash.count(P)) {
            pair<int , int> W = Hash[P];
            if (A + W.first > res) {
                res = A + W.first;
                F = W.second , S = M;
            }
        }
    } else {
        DFS(k + 1 , A + a[k] , B + b[k] , C , M | 0 << k + k - m - m);
        DFS(k + 1 , A + a[k] , B , C + c[k] , M | 1 << k + k - m - m);
        DFS(k + 1 , A , B + b[k] , C + c[k] , M | 2 << k + k - m - m);        
    }
}


int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d%d%d" , &a[i] , &b[i] , &c[i]);
    m = n / 2;
    dfs(0 , 0 , 0 , 0 , 0);
    DFS(m , 0 , 0 , 0 , 0);
    if (res == -1 << 30)
        puts("Impossible");
    else {
        for (int i = 0 ; i < m ; ++ i) {
            int y = F >> i + i & 3;
            puts(ans[y]);
        }
        for (int i = 0 ; i < n - m ; ++ i) {
            int y = S >> i + i & 3;
            puts(ans[y]);
        }
    }
    return 0;
}