#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)4e5 + 500;

int n, res[N];
P sea[N];
string str;
stack<P> S;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &sea[i].first);
        sea[i].second = i+1;
    }
    getchar();
    getline(cin, str);
    sort(sea, sea+n);
    int cur = 0;
    for(int i = 0; i < 2 * n; i++){
        if(str[i] == '0'){
            res[i] = sea[cur].second;
            S.push(sea[cur++]);
        }
        else{
            res[i] = S.top().second;
            S.pop();
        }
    }
    for(int i = 0; i < 2 * n; i++){
        printf("%d ", res[i]);
    }
}