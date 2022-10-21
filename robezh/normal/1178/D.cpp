#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 100050, N = 1005;

bool p[M];
int mu[M], pm[M], pms;

int n;

void get_mobius_and_sieve(){
    mu[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

int main(){
    get_mobius_and_sieve();
    cin >> n;
    int sum = n;
    int add = 0;
    while(!p[n + add]) add++;
    cout << n + add << endl;
    for(int i = 0; i < n; i++) {
        cout << i + 1 << " " << ((i + 1) % n + 1) << "\n";
    }
    for(int i = 0; i < add; i++) {
        cout << i + 1 << " " << i + n / 2 + 1 << endl;
    }


}