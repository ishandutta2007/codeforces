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
const int nmax=3456789, mod=1e9+7;
deque < pii > Q;
int n,m,t,f[nmax],d[nmax],rem[nmax];

int main() {
    //ios :: sync_with_stdio(false);
   cin >> n >> m >> t;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        f[i]= ((s[0]-'0')*10+(s[1]-'0'))*3600+((s[3]-'0')*10+(s[4]-'0'))*60+(s[6]-'0')*10+(s[7]-'0');
    }
    int cnt=0,fla=0;
    for(int i=0;i<n;++i){
        if(i>0)
            while(!Q.empty() && Q.front().Y<=f[i])
                Q.pop_front();
        if(Q.size()<m){
            Q.pb(mp(i,f[i]+t));
            rem[i]=++cnt;
        } else {
        pii bc = Q.back();
        Q.pop_back();
        rem[i]=rem[bc.X];
        Q.pb(mp(bc.X, f[i]+t));
        }
        if(Q.size()== m) fla = 1;
    }
    if(fla==0){
        cout << "No solution";
        return 0;
    }
    cout<<cnt<<"\n";
    re(i,0,n){
        cout << rem[i]<<"\n";
    }
    cin.get(); cin.get();
	return 0;
}