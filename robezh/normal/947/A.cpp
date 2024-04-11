#include <bits/stdc++.h>
using namespace std;

int lar[1000500];
int x2;
vector<int> x1;
set<int> S;

int main() {
    fill(lar, lar+1000500, 1);
    for(int i = 2; i < 1000500; i++){
        if(lar[i] == 1){
            lar[i] = 1;
            for(int j = 2*i; j < 1000500; j+=i){
                lar[j] = i;
            }
        }
    }
    int res = 1000500;
    cin >> x2;
    for(int i = x2; i > x2-lar[x2]; i--) x1.push_back(i);
    for(int x : x1){
        res = min(res, x-lar[x]+1);
    }
    cout << res;

}