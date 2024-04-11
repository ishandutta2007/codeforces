#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

map<int, int> M;

ll n,k;
int cnt = 0;
int psize = 0;
int lar, sma = -1;

void bd(int k){
    M[k] --;
    M[k-1] += 2;
    if(sma == k) sma = k-1;
    if(lar == k && M[k] == 0) lar = k-1;
}

int main() {
    cin >> n >> k;
    int base = 0;
    while(n > 0){
        if(n%2 == 1){
            M[base] = 1, lar = base;
            if(sma == -1) sma = base;
        }
        base ++, n /= 2;
    }
    if(M.size() > k) return !printf("No");
    int upp = k - M.size();
    for(int i = 0; i < upp; i++){
        if(M[lar] > upp-i) bd(sma);
        else bd(lar);
    }
    printf("Yes\n");
    vector<int> res;
    for(auto p : M){
        for(int i = 0; i < p.second; i++) res.push_back(p.first);
    }
    for(int i = res.size()-1; i >= 0; i--){printf("%d ", res[i]);}
}