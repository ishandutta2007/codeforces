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
const int nmax=1234, mod=1e9+7;
int n, a[nmax], b[nmax];
int main() {
    //ios :: sync_with_stdio(false);
    read(n);
    rep(i,1,n){
        read(a[i],b[i]);
    }
    ll ans = (ll)1e18;
    rep(h,1,1000){
        ll cur = 0;
        int cnt = 0;
        rep(i,1,n){
            if(min(a[i],b[i])>h){
                cur = (ll)1e15;
                break;
            }
            if(b[i]<=h){
               cur += a[i];
               continue;
               }
            cur += b[i];
            ++cnt;
        }
        if(cur < (ll)1e15 && cnt <= n / 2) {
            int can = n / 2 - cnt;
            multiset < int > s;
            rep(i,1,n){
                if(max(a[i],b[i])<=h){
                    s.insert(b[i]-a[i]);
                }
            }
            for(multiset < int > :: iterator it = s.begin(); it != s.end(); ++it){
                if(can > 0){
                    if(*it<0){
                        cur+=*it;
                        --can;
                    }
                }
            }
            ans = min(ans, cur * h);
        }
    }
    cout << ans << endl;
    cin.get(); cin.get();
	return 0;
}