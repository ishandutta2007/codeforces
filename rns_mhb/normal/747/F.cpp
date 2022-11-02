#include<bits/stdc++.h>
using namespace std;

long long p[22];
void init(){
    p[0] = 1;
    for(int i = 1; i <= 20; i ++) p[i] = p[i-1] * i;
  // cout << p[20] << endl;
}

long long tot[20][20];
int arr[20];
long long calc(int len){
    if(len == 0) return 1;
    memset(tot, 0, sizeof tot);
    tot[0][0] = 1;
    for(int i = 1; i <= 16; i ++){
        for(int j = 0; j <= len; j ++){
            tot[i][j] = 0;
            for(int t = 0; t <= j && t <= arr[i]; t ++){
                tot[i][j] += (p[j] / p[j-t] / p[t]) * tot[i-1][j - t];
            }
        }
    }
    return tot[16][len];
}

long long k;
int m;
int length;

void print(int x){
    if(x <= 10) printf("%d", x - 1);
    else printf("%c", 'a' + x - 11);
}

void run(int dep){
  //  cout << dep << endl;
    if(dep == length) return;
    for(int i = 1; i <= 16; i ++) if(arr[i] > 0){
        arr[i] --;
        long long tmp = calc(length - dep - 1);
        if(tmp < k) k -= tmp;
        else if(tmp >= k){
            print(i);
            run(dep + 1); return;
        }
        arr[i] ++;
    }
}

int main(){
   // freopen("f.in", "r", stdin);
    init();
    cin >> k >> m;
  ///  cout << k << m << endl;
    for(int i = 0; i <= 16; i ++) arr[i] = m;
    for(int gas = 1;; gas ++){
        for(int i = 2; i <= 16; i ++){
            arr[i] --;
            long long tmp = calc(gas - 1);
            if(tmp < k) k -= tmp;
            else if(tmp >= k){
                length = gas;
                print(i);
                run(1); return 0;
            }
            arr[i] ++;
        }
    }
}