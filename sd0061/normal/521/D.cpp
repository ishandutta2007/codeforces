#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n , K , m;
LL init[N];
pair<int , int> delta[N];
vector< pair<int , int> > mul;
vector< pair<int , int> > add[N];
int p[N] , f;
struct opt {
    LL a , b;
    int w;
    bool operator < (const opt& R) const {
        return a * R.b < R.a * b;
    }
};

void work() {
    int i , j , x , y;
    scanf("%d%d%d",&K,&n,&m);
    for (i = 1 ; i <= K ; ++ i)
        scanf("%d",&x) , init[i] = x;

    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d%d",&j,&x,&y);
        if (j == 1) {
            delta[x] = max(delta[x] , make_pair(y , i));
        }
        if (j == 2) {
            add[x].push_back(make_pair(y , i));
        }
        if (j == 3) {
            if (y != 1)
                mul.push_back(make_pair(y - 1 , i));
        }
    }
    vector<int> res;
    priority_queue< opt > Q;
    for (i = 1 ; i <= K ; ++ i) {
        if (delta[i].first > init[i])
            add[i].push_back(make_pair(delta[i].first - init[i] , -delta[i].second));
        if (add[i].size()) {
            sort(add[i].begin() , add[i].end() , greater< pair<int , int> >());
            x = add[i][0].first;
            Q.push((opt) {x , init[i] , i});
        }
    }
    sort(mul.begin() , mul.end() , greater< pair<int , int> >());

    while (res.size() < m && !Q.empty()) {
        opt T = Q.top(); Q.pop() , x = T.w;
        if (res.size() + mul.size() >= m) {
            j = m - res.size();
            if (T.a <= mul[j - 1].first * T.b) {
                while (j > 0)
                    res.push_back(mul[-- j].second);
                f = 1; break;
            }
        }
        if (x <= K) {
            init[x] += add[x][p[x]].first;
            res.push_back(add[x][p[x]].second);
            ++ p[x];
            if (p[x] < add[x].size()) {
                y = add[x][p[x]].first;
                Q.push((opt) {y , init[x] , x});
            }
        } else {
            x -= K;
            init[x] += delta[x].first;
            res.push_back(n + delta[x].second);            
        }
    }
    if (!f) {
        j = 0;
        while (res.size() < m && j < mul.size())
            res.push_back(mul[j ++].second);
    }
    printf("%d\n" , (int)res.size());
    for (auto it : res)
        if (it < 0)
            printf("%d " , -it);
    for (auto it : res)
        if (it > 0)
            printf("%d " , it);
    

}


int main() {
    work();
    return 0;
}