#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , K , B , C;
int a[N] , b[N] , w[N];

vector<int> V[5];

int main() {
    scanf("%d%d%d%d" , &n , &K, &B , &C);
    B = min(B , C * 5);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        a[i] += 1000000000;
        for (int j = 0 ; j <= 5 ; ++ j) {
            int x = a[i] + j;
            V[x % 5].push_back(x / 5);
        }
    }
    sort(a , a + n);
    LL res = 1LL << 60;
    for (int k = 0 ; k < 5 ; ++ k) {
        sort(V[k].begin() , V[k].end());
        V[k].erase(unique(V[k].begin() , V[k].end()) , V[k].end());
        //printf("--%d\n" , k);
        //for (int i = 0 ; i < V[k].size() ; ++ i)
        //    printf("%d%c" , V[k][i] , " \n"[i + 1 == V[k].size()]);
        for (int i = 0 ; i < n ; ++ i) {
            b[i] = a[i];
            w[i] = 0;
            while (b[i] % 5 != k) {
                ++ b[i];
                w[i] += C;
            }
            b[i] /= 5;
            //printf("%d %d\n" , b[i] , w[i]);
        }
        priority_queue<LL> Q;
        LL sum = 0;
        for (int i = 0 , j = 0 ; i < V[k].size() ; ++ i) {
            while (j < n && b[j] <= V[k][i]) {
                Q.push((LL)B * -b[j] + w[j]);
                sum += (LL)-b[j] * B + w[j];
                ++ j;
                if (Q.size() > K) {
                    sum -= Q.top();
                    Q.pop();
                }
            }
            if (Q.size() == K) {
                res = min(res , (LL)K * B * V[k][i] + sum);
            }
        }
    }
    cout << res << endl;

    return 0;
}