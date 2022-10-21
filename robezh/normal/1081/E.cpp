#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 200050, N = M;
const ll INF = (ll)1e18;

vector<int> dvs[M];


pair<ll, ll> get_pair(ll thres, int x){
    ll fir = INF, sec = 0;
    for(int d : dvs[x]){
        if(d % 2 != (x / d) % 2) continue;
        ll b = (d + x / d) / 2, a = (x / d - d) / 2;
        if(a < 0) break;
        if(a * a > thres && a * a < fir){
            fir = a * a;
            sec = b * b;
        }
    }
    return {fir, sec};

};

int n;
int even[N];
ll psum[N];
ll res[N];

int main(){
    for(int i = 1; i < M; i++){
        for(int j = i; j < M; j += i){
            dvs[j].push_back(i);
        }
    }

    scanf("%d", &n);
    for(int i = 1; i <= n/2; i++){
        scanf("%d", &even[i]);
        if(even[i] % 4 == 2) return !printf("No");
        auto p = get_pair(psum[i*2-2], even[i]);
        if(p.first == INF) return !printf("No");
        psum[i*2-1] = p.first;
        psum[i*2] = p.second;
    }

    for(int i = 1; i <= n; i++){
        res[i] = psum[i] - psum[i-1];
    }
    printf("Yes\n");
    for(int i = 1; i <= n; i++) printf("%I64d ", res[i]);


}