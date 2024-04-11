#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;

int n, k, ans = 0;
ll num[N];
int nxt[N];

bool noover(ll a, ll b){
    return (ll)(9e18) / b > a;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){scanf("%I64d", &num[i]);}
    int las = n;
    for(int i = n-1; i >= 0; i--){
        if(num[i] == 1){nxt[i] = las;}
        else las = i;
    }
    for(int i = 0; i < n; i++){
        ll prod = 1, sum = 0;
        int j = i;
        while(j < n){
            if(num[j] == 1){
                int nx = nxt[j];
                ll csum = sum + (nx - j);
                if(k * csum >= prod && k * (sum+1) <= prod && prod % k == 0) ans++;
                j = nx;
                sum = csum;
            }
            else{
                if(noover(prod, num[j])){
                    prod *= num[j];
                    sum += num[j];
                    if(k * sum == prod) ans++;
                    j ++;
                }
                else break;
            }
        }
    }
    cout << ans << endl;

}