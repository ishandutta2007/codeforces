#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define re(i,a,b) for (int i=a;i<b;++i)
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int nmax=123456, mod=1e9+7;
int n, k, q, x, a[nmax];
int main() {
    //ios :: sync_with_stdio(false);
    read(n, k);
    rep(i,1,n) read(a[i]);
    read(q);
    while(q--) {
        read(x);
        map <int, int >f;
        f[0] = 0;
        int ans = 1e9;
        rep(i,1,n){
            rep(j,1,k){
                if(1LL * j * a[i] > x) {
                    break;
                }
                if(f.count(x - j * a[i])){
                    ans = min(ans, f[x - j * a[i]] + j);
                }
            }
            rep(j,1,k){
                if(1LL * j * a[i] > x) {
                    break;
                }
                if(!f.count(j * a[i]))
                    f[j * a[i]] = 1e9;
                f[j * a[i]] = min(f[j * a[i]], j);
            }
        }
        if(ans > k) ans = -1;
        cout << ans << "\n";
    }
    cin.get(); cin.get();
	return 0;
}