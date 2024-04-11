#include <iostream>
#include <vector>
using namespace std;
const int N = 1000000+10;
int n, k[N], prime[N], cnt[N], f[N];
bool notp[N]; 
int fac[5050][2502], facopy[5050][2502];
int main() {
    for (int i = 2; i < 5050; i ++) {
        if (notp[i] == false) {
            prime[++ prime[0]] = i;
            for (int j = i + i; j < 5050; j += i) {
                notp[j] = true;
            }
        }
    }
    for (int i = 0; i < 5050; i ++) {
        for (int j = 1; j <= prime[0]; j ++) {
            int now = prime[j];
            int sum = 0;
            while (now <= i) {
                sum += i / now;
                now = now * prime[j];
            }
            fac[i][j] = sum;
        }
    }
    for (int i = 0; i < 5050; i ++) for (int j = 1; j <= prime[0]; j ++) facopy[i][j] = fac[i][j];
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) 
        scanf("%d", &k[i]), cnt[k[i]] ++;
    
    for (int i = 1; i < prime[0]; i ++) {
        for (int j = prime[i]; j < prime[i+1]; j ++) f[i] += cnt[j];
    }
    f[0] = cnt[0] + cnt[1];

    int mx = -1, id = -1;
    for (int i = 1; i <= prime[0]; i ++) {
        if (f[i] > mx) {
            mx = f[i]; id = i;
        }
    }
    //printf("fac[%d][%d] = %d\n", 3,2,fac[3][2]);
    vector<int> bst;

    if (mx * 2 > n) {
        vector<int> vec;
        for (int i = prime[id]; i < prime[id+1]; i ++) vec.push_back(i), fac[i][id] --;
        bst.push_back(id);
        while (1) {
            vector<int> nex1, nex2;
            int tmp1 = 0, tmp2 = 0;
            for (auto x: vec) {
                if (fac[x][id] > 0) tmp1 += cnt[x], nex1.push_back(x); 
                else tmp2 += cnt[x], nex2.push_back(x);
            }
            if (tmp1 * 2 <= n && tmp2 * 2 <= n) {
                break;
            }
            if (tmp1 * 2 > n) {
                bst.push_back(id); 
                for (auto x: nex1) {
                    fac[x][id] --;
                }
                vec=nex1; 
            }
            if (tmp2 * 2 > n) {
                //printf("!\n");
                if (id == 1) break;
                if (id >= 2) bst.push_back(id - 1); 
                -- id;
                for (auto x: nex2) {
                    fac[x][id] --;
                }
                vec=nex2;
            }
        }
    } 

    for (int i = 0; i < 5050; i ++) for (int j = 1; j <= prime[0]; j ++) fac[i][j] = facopy[i][j];
    int res[5002] = {0};
    for (auto x: bst) {
        res[x] ++;
    }
    long long ans = 0;
    for (int i = 0; i <= 5000; i ++) {
        if (cnt[i]) {
            int sum = 0;
            for (int j = 1; j <= prime[0]; j ++) {  
                sum += fac[i][j] + res[j]; 
            }
            int lcp = 0;
            for (int j = prime[0]; j >= 1; j --) {
                if (fac[i][j] == res[j]) {
                    lcp += res[j];
                } else {
                    lcp += min(res[j],fac[i][j]);
                    break;
                }
            }

            //printf("i = %d, sum = %d, lcp = %d\n", i, sum, lcp);
            ans += 1LL * cnt[i] * (sum - 2 * lcp);
        }
    }
    cout << ans << endl;
}