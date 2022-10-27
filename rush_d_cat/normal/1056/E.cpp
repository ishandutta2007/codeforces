#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
const int B = 131;
const int N = 1000000 + 10;

LL p[N],inv[N];int n;
char s[N],t[N];
LL sum[N];

int gethash(int l,int r) {
    return (sum[r]-sum[l-1]+MOD) * inv[l-1] % MOD;
}

bool check(int x,int y){
    int h1=-1,h2=-1;
    int now=1;
    for(int i=1;s[i];i++){
        if(s[i]=='0'){
            int tmp = gethash(now,now+x-1);
            if(h1==-1) h1=tmp; else if(tmp!=h1) return 0;
            now += x;
        } else {
            int tmp = gethash(now,now+y-1);
            if(h2==-1) h2=tmp; else if(tmp!=h2) return 0;
            now += y;
        }
    }
    if(h1==h2)return 0;
    return 1;
}
int main() {
    scanf("%s%s",s+1,t+1);  n=strlen(t+1);
    inv[1]=1;inv[0]=1;
    for(int i=2;i<N;i++)inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    LL k=inv[B];
    p[0]=1;for(int i=1;i<N;i++)p[i]=p[i-1]*B%MOD,inv[i]=inv[i-1]*k%MOD;
    for(int i=1;i<=n;i++){
        sum[i]=(sum[i-1] + (t[i])*p[i]) % MOD;
    }        

    int a=0,b=0;
    for(int i=1;s[i];i++)if(s[i]=='0')a++;else b++;

    int ans=0;
    for(int x=1;x*a<n;x++){
        if((n-x*a)%b) continue; 
        int y=(n-x*a)/b;
        //printf("# %d %d\n",x,y);
        if(check(x,y)) ans++;
    }
    cout<<ans<<endl;
}