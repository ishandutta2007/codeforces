#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500, A = (int)5e5 + 500;

int n,q,a;
int num[N], cur_count = 0;
int fac[A];
bool vis[N];
vector<int> primes;

bool is_prime(int x){
    for(int i = 2; i < x; i++) if(x % i == 0) return false;
    return true;
}

//void add(int x, int val){
//    int f[10], cnt[10], now[10], fn = 0;
//    for(int i = 0; i < 10; i++) f[i] = cnt[i] = now[i] = 0;
//    for(int p : primes){
//        if(x % p == 0){
//            f[fn] = p;
//            while(x % p == 0){
//                cnt[fn] ++;
//                x /= p;
//            }
//            fn++;
//        }
//    }
//    if(x > 1) f[fn] = x, cnt[fn++] = 1;
//    int pro = 1;
//    for(int i = 0; i < fn; i++) pro *= (cnt[i] + 1);
//    for(int i = 0; i < pro; i++){
//        for(int j = 0; j < fn; j++) if(now[j] > cnt[j]){
//                now[j] = 0;
//                now[j+1] ++;
//            }
//        int cur = 1;
//        for(int j = 0; j < fn; j++){cur *= pow(f[j], now[j]);}
//        fac[cur] += val;
//        now[0] ++;
//    }
//}

ll get(int x, int val){
    ll res = 0;
    int f[10], fn = 0;
    for(int i = 0; i < 10; i++) f[i] = 0;
    for(int p : primes){
        if(x % p == 0){
            f[fn++] = p;
            while(x % p == 0){x /= p;}
        }

    }
    if(x > 1) f[fn++] = x;
    for(int i = 1; i < (1 << fn); i++){
        int s = -1;

        int cur = 1;
        for(int j = 0; j < fn; j++){
            if(i & (1 << j)) cur *= f[j], s = -s;
        }
        res += s * fac[cur];
        fac[cur] += val;
    }
    return res;
}

int main(){
    for(int i = 2; i < 710; i++) if(is_prime(i)) primes.push_back(i);
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    ll cur_res = 0;
    while(q--){
        scanf("%d", &a); a--;
        if(!vis[a]){
            cur_res += cur_count - get(num[a], 0);
            get(num[a], 1);
            vis[a] = true;
            cur_count++;
            printf("%I64d\n", cur_res);
        }
        else{
            get(num[a], -1);
            cur_count--;
            cur_res -= cur_count - get(num[a], 0);
            vis[a] = false;
            printf("%I64d\n", cur_res);
        }
    }
}