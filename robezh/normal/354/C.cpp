#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 500, M = (int)2e6 + 500;

int n,k,a;
int num[N];
int ps[M];

bool check(int t){
    if(k + 1 >= t) return ps[t - 1] == 0;
    int sum = 0;
    for(int i = 1; i * t + k < M; i++){
        sum += ps[i * t + k] - ps[i * t - 1];
    }
    return sum == n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i], ps[num[i]] ++;
    for(int i = 2; i < M; i++) ps[i] += ps[i-1];
    for(int i = (int)1e6; i >= 1; i--){
        if(check(i)){
            cout << i << endl;
            return 0;
        }
    }

}