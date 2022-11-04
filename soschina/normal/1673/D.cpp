#include <cstdio>
#include <vector>
using namespace std;
const int p = 1e9 + 7;

int t, b, q, y, c, r, z;
vector<int> fac, cnt;

bool in_b(long long x){
    if(x < b)
        return false;
    if((x - b) % q)
        return false;
    if((x - b) / q >= y)
        return false;
    return true;
}

int ans;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

void dfs(int i, int num){
    if(i == fac.size()){
        if(1ll * num * q / gcd(num, q) >= r)
            ans = (ans + 1ll * r / num * r / num) % p;
        return;
    }
    for (int j = 0; j <= cnt[i]; j++){
        dfs(i + 1, num);
        num *= fac[i];
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        fac.clear(), cnt.clear();
        scanf("%d%d%d%d%d%d", &b, &q, &y, &c, &r, &z);
        if(r % q || !in_b(c) || !in_b(c + 1ll * (z - 1) * r)){
            puts("0");
            continue;
        }
        if(!in_b(c - r) || !in_b(c + 1ll * z * r)){
            puts("-1");
            continue;
        }
        int tmp = r;
        for (int i = 2; 1ll * i * i <= tmp; i++){
            if(tmp % i == 0){
                fac.push_back(i);
                cnt.push_back(0);
                do{
                    cnt.back()++;
                    tmp /= i;
                } while (tmp % i == 0);
            }
        }
        if(tmp > 1){
            fac.push_back(tmp);
            cnt.push_back(1);
        }
        ans = 0;
        dfs(0, 1);
        printf("%d\n", ans);
    }
    return 0;
}