#include <bits/stdc++.h>
using namespace std;

const int N = 5050, M = 32000;

int n,m;
int a[N], b[N], g[N];
bool p[M];
vector<int> pms;

int gcd(int x, int y){
    return x == 0 ? y : gcd(y % x, x);
}

int get_score(int x){
    int res = 0;
    for(int j = 0; j < m; j++){
        while(x % b[j] == 0){
            res--;
            x /= b[j];
        }
    }
    for(int p : pms){
        while(x % p == 0){
            res++;
            x /= p;
        }
    }
    if(x > 1) res++;
    return res;
}

int main(){
    fill(p, p+M, true);
    for(int i = 2; i < M; i++){
        if(!p[i]) continue;
        for(int j = 2 * i; j < M; j += i) p[j] = false;
    }
    for(int i = 2; i < M; i++) if (p[i]) pms.push_back(i);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int res = 0, cmu = 1;
    g[0] = a[0];
    for(int i = 1; i < n; i++) g[i] = gcd(g[i-1], a[i]);

    for(int i = n-1; i >= 0; i--){
        a[i] /= cmu;
        g[i] /= cmu;

        if(get_score(g[i]) < 0){
            cmu *= g[i];
            a[i] /= g[i];
        }
        //cout << "cmu : " << cmu  << "a: " << a[i] << endl;
        res += get_score(a[i]);
    }
    cout << res << endl;


}