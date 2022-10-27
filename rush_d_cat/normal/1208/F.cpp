#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,n,a) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define RD(x) scanf("%d",&x)
#define PT(x) printf("%d\n", x)
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int N=5000000+10;
int n,m,a[N];
int f1[N],f2[N];
void add(int val,int pos){
    if(pos>f1[val])f2[val]=f1[val],f1[val]=pos;
    else if(pos>f2[val]) f2[val]=pos;
}
int main() {
    RD(n); rep(i,1,n+1) RD(a[i]), add(a[i],i);
    // rep(i,0,10) printf("%d, %d, %d\n", i,f1[i],f2[i]); printf("----\n");
    rep(i,0,22) rep(j,1,1<<22) if(!(j>>i&1)) add(j,f1[j^(1<<i)]), add(j,f2[j^(1<<i)]);
    // rep(i,0,10) printf("%d, %d, %d\n", i,f1[i],f2[i]);
    int ans=0;
    for(int i=1;i<=n-2;i++) {
        int mask=0,tmp=a[i];
        for(int j=21;j>=0;j--) if(!((a[i]>>j)&1)) {
            mask|=1<<j; 
           // printf("i=%d,j=%d, mask=%d, f2=%d\n", i,j,mask,f2[mask]);
            if(f2[mask]>i) tmp|=1<<j; else mask^=1<<j;
        }
        ans=max(ans,tmp);
    }
    printf("%d\n", ans);
}