#include <bits/stdc++.h>
using namespace std;

const int N = (int)370000, INF = (int)1e9, mod = (int)1e9 + 7;
typedef long long ll;

int n;
int tp[N], num[N];
set<int> S;

int getmode(){
    string res;
    char c;
    while(scanf("%c", &c) && c != ' ') {
        res.push_back(c);
    }
    if(res[1] == 'D') return 0;
    else return 1;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        getchar();
        tp[i] = getmode();
        scanf("%d", &num[i]);
    }
    ll res = 1;
    int l = 0, r = INF;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(tp[i] == 0){
            S.insert(num[i]);
            if(num[i] > l && num[i] < r) cnt ++;
        }
        else{
            cnt = 0;
            if(num[i] > r || num[i] < l) return !printf("0");
            if(num[i] > l && num[i] < r) res = (res * 2) % mod;
            auto it = S.find(num[i]);
            auto nit = it, pit = it;
            l = (pit == S.begin() ? 0 : *(--pit));
            nit++;
            r = (nit == S.end() ? INF : *nit);
            S.erase(it);

        }
    }
    res = (res * (cnt+1)) % mod;
    cout << res << endl;
}