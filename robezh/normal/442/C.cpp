#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 500;
typedef pair<int, int> P;

ll res = 0;
int cur = 0;
int n, num[N];
priority_queue<P, vector<P>, greater<P> > pque;
set<int> S;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        pque.push({num[i], i});
        S.insert(i);
    }
    while(S.size() >= 3){
        P p = pque.top(); pque.pop();
        res += 1LL * (p.first - cur) * ((int)S.size() - 2);
        cur = p.first;
        auto it = S.erase(S.find(p.second));
        if(it == S.begin() || it == S.end()) continue;
        int cur_num = num[*it];
        --it;
        res += (min(cur_num, num[*it]) - cur);

    }
    cout << res << endl;
}