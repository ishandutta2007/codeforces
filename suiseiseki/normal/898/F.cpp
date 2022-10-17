#include <cstdio>
#define ll long long
#define rep(i,a,b) for(int i=a;i<(b);++i)
const int INF=0x3f3f3f3f;
const int maxn=1e6+5;
const ll MOD=1e9+7;
int len;
ll Hash[maxn],pw[maxn],seed = 10;
char str[maxn];
ll gethash(int l,int r){
    ll ret=(Hash[r]-Hash[l-1]*pw[r-l+1])%MOD;
    if(ret<0) ret+=MOD;
    return ret;
}
void show(int a,int b){
    rep(i,1,a+1) printf("%c",str[i]);
    printf("+");
    rep(i,a+1,a+b+1) printf("%c",str[i]);
    printf("=");
    rep(i,a+b+1,len+1) printf("%c",str[i]);
}
bool check(int lena,int lenb){
    if(lena<=0||lenb<=0) return 0;
    ll c = gethash(lena+lenb+1,len);
    ll a = gethash(1,lena) , b = gethash(lena+1,lena+lenb);
    if(lenb!=1&&str[lena+1]=='0') return 0;
    if((a+b)%MOD==c){
        show(lena,lenb);
        return 1;
    }
    return 0;
}
int main(){
    scanf("%s",str+1);
    len=0;
    while(str[++len]!='\0');
    len--;
    pw[0] = 1;
    rep(i,1,len+1) pw[i] = (pw[i-1]*seed)%MOD;
    Hash[0] = 0;
    rep(i,1,len+1) Hash[i] = (Hash[i-1]*seed+(str[i]-'0'))%MOD;
    rep(i,len/2,len+1){
        if(str[i]=='0'&&i!=len) continue;
        int lenc = len-i+1;
        if(check(lenc,len-2*lenc)) break;
        if(check(lenc-1,len-2*lenc+1)) break;
        if(check(len-2*lenc,lenc)) break;
        if(check(len-2*lenc+1,lenc-1)) break;
    }
    return 0;
}