#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
typedef long long LL;
const int N = 1000000 + 10;
const LL MOD = 1e9 + 7;
const int B = 1000007;
LL mpow(LL a, LL x) {
    if(x==0) return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}
 
char s[N];
LL pw[N],ip[N];
 
vector<char> res;
LL pre[N],preans[N];
 
void add() {
    pre[0]=s[0];
    int n=strlen(s);
 
    int len=(int)res.size()-1;
    int pos = -1;
    for(int i=0;i<n;i++){
        if(i>0) pre[i]=(pre[i-1] + pw[i] * s[i]) % MOD;
        if(len-i-1>=-1) {
            LL tmp = preans[len] - (len-i-1>=0 ? preans[len - i - 1] : 0);
            tmp = (tmp % MOD + MOD) % MOD;
            tmp = tmp * ip[len-i] % MOD;
            if (tmp == pre[i]) {
                pos = i;
            }
        }
    }
 
    for(int i=pos+1;i<n;i++) {
        res.push_back(s[i]);
        int len = (int)res.size()-1;
        preans[len] = ((len>=1 ? preans[len-1] : 0) + s[i] * pw[len]) % MOD;
    }
}
 
int main() {
    pw[0]=1, pw[1]=B;
    ip[0]=1, ip[1]=mpow(B,MOD-2);
    for(int i=2;i<N;i++){
        pw[i]=pw[i-1]*B%MOD;
        ip[i]=ip[i-1]*ip[1]%MOD;
    }
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        add();
    }
    for(auto c: res) {
        printf("%c", c);
    }
    printf("\n");
}