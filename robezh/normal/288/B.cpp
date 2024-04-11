#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int ca[8] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};

ll fp(int n, int k){
    if(k == 0) return 1;
    ll t = fp(n, k/2);
    ll ts = (t * t) % mod;
    return k % 2 == 0 ? ts : (ts * n) % mod;
}

bool back(int i, vector<int> v){
    int now = v[i];
    for(int i = 0; i < v.size(); i++){
        now = v[now];
        if(now == 0) return true;
    }
    return false;
}

bool good(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        if(!back(i, v)) return false;
    }
    return true;
}

int get(int n){
    int ttcnt = 0;
    int res = 0;
    vector<int> v;
    int upp = 1;
    for(int i = 0; i < n; i++) upp *= n;
    for(int i = 0; i < upp; i++){
        ttcnt++;
        v.clear();
        int cnt = n;
        int now = i;
        while(cnt > 0){
            v.push_back(now % n);
            now /= n;
            cnt --;
        }
        //if(v.size() != n) cout << v.size() << endl;
        if(good(v)) res++;
    }
    return res;

}

int main(){
    int n,k;
    cin >> n >> k;
    ll res = (fp(n-k, n-k) * ca[k-1]) % mod;
    cout << res;
}