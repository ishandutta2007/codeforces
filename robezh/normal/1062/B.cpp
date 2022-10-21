#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1000050;

bool p[M];
int mu[M], pm[M], pms;

bool pw2(int x){
    while(x > 1){
        if(x % 2 == 1) return false;
        x /= 2;
    }
    return true;
}

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

    int n;
    cin >> n;

    int res = 1;
    int mxp = 0;
    vector<int> ps;
    for(int i = 0; i < pms; i++){
        if(n % pm[i] == 0){
            int p = 0;
            while(n % pm[i] == 0){
                p ++;
                n /= pm[i];
            }
            ps.push_back(p);
            mxp = max(mxp, p);
//            cout << pm[i] << " " << p << endl;
            res *= pm[i];
        }
    }
    int cnt = 0;
    for(int x : ps) cnt += (x != mxp);

    cnt = min(cnt, 1);

    if(!pw2(mxp)) cnt = max(cnt, 1);

//    cout << cnt << endl;
//    cout << mxp << endl;

    mxp --;
    while(mxp > 0){mxp /= 2; cnt++;}

    cout << res << " " << cnt << endl;

}