#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;

int K;
int n;
vector< pair<int , int> > E;
void add(int x , int y) {
    E.push_back(make_pair(x , y));
}
void work() {
    cin >> K;
    if (K == 1) {
        puts("YES\n2 1\n1 2");
        return;
    }
    if (K % 2 == 0) {
        puts("NO");
        return;
    }
    int sum = K + K - 3;
    int i , j , x , y;
    x = ++ n;
    for (i = 1 ; i < K ; ++ i)
        add(x , ++ n);
    for (i = 1 ; i < K ; ++ i)
        add(x + 1 , ++ n);
   
    for (i = 0 ; i < sum ; ++ i)
        for (j = -K / 2 ; j <= K / 2 ; ++ j) {
            if (j != 0)
                add(x + 2 + i , x + 2 + (i + j + sum) % sum);
        }
    y = ++ n;
    for (i = 1 ; i < K ; ++ i)
        add(y , ++ n);
    for (i = 1 ; i < K ; ++ i)
        add(y + 1 , ++ n);
   
    for (i = 0 ; i < sum ; ++ i)
        for (j = -K / 2 ; j <= K / 2 ; ++ j) {
            if (j != 0)
                add(y + 2 + i , y + 2 + (i + j + sum) % sum);
        }
    add(x , y);
    for (i = 0 ; i < (int)E.size() ; ++ i)
        if (E[i].first > E[i].second)
            swap(E[i].first , E[i].second);
    sort(E.begin() , E.end());
    E.resize(unique(E.begin() , E.end()) - E.begin());
    printf("YES\n%d %d\n" , n , (int)E.size());
    for (i = 0 ; i < (int)E.size() ; ++ i)
        printf("%d %d\n" , E[i].first , E[i].second);
    
}

int main() {
    work();
    return 0;
}