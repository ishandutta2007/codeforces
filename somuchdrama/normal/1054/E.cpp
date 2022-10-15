#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
#define fon(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
const int N=333;
string a[N][N];
string b[N][N];
struct query{
    int x1,y1,x2,y2;
    query(int _x1,int _y1,int _x2, int _y2):x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
};
int32_t main() {

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>b[i][j];

    vector<query> ans;
    reverse(a[1][m].begin(),a[1][m].end());
    reverse(a[n][1].begin(),a[n][1].end());
    for(int k=(int)a[1][1].size()-1;k>=0;--k){
        if(a[1][1][k]=='0'){
            ans.pb(1,1,n,1);
            dbg(1,1,n,1);
            a[n][1]+='0';
        }else{
            ans.pb(1,1,1,m);
            dbg(1,1,1,m);
            a[1][m]+='1';
        }
    }
    dbg("1 1 moved");
    for(int k=(int)a[n][m].size()-1;k>=0;--k){
        if(a[n][m][k]=='0'){
            ans.pb(n,m,n,1);
            dbg(n,m,n,1);
            a[n][1]+='0';
        }else{
            ans.pb(n,m,1,m);
            dbg(n,m,1,m);
            a[1][m]+='1';
        }
    }
    dbg("n m moved");
    a[1][1].clear();
    a[n][m].clear();
    reverse(a[1][m].begin(),a[1][m].end());
    reverse(a[n][1].begin(),a[n][1].end());
    
    
    for(int i=1;i<=n;++i){
        reverse(a[i][1].begin(),a[i][1].end());
        reverse(a[i][m].begin(),a[i][m].end());
        for(int j=2;j<m;++j){
            for(int k=(int)a[i][j].size()-1;k>=0;--k){
                if(a[i][j][k]=='0'){
                    ans.pb(i,j,i,1);
                    dbg(i,j,i,1);
                    a[i][1]+='0';
                }else{
                    ans.pb(i,j,i,m);
                    dbg(i,j,i,m);
                    a[i][m]+='1';
                }
            }
            a[i][j].clear();  
        }
        dbg("row",i,"to 1 m");
        reverse(a[i][1].begin(),a[i][1].end());
        if(i>1){
            for(int k=(int)a[i][1].size()-1;k>=0;--k){
                if(a[i][1][k]=='0'){
                    ans.pb(i,1,1,1);
                    dbg(i,1,1,1);
                    a[1][1]+='0';
                }else{
                    ans.pb(i,1,i,m);
                    dbg(i,1,i,m);
                    a[i][m]+='1';
                }
            }
            a[i][1].clear();
        }
        reverse(a[i][m].begin(),a[i][m].end());
        dbg("1 col ok");
        if(i<n){
            dbg(a[i][m]);
            for(int k=(int)a[i][m].size()-1;k>=0;--k){
                if(a[i][m][k]=='0'){
                    ans.pb(i,m,i,1);
                    dbg(i,m,i,1);
                    a[i][1]+='0';
                }else{
                    ans.pb(i,m,n,m);
                    dbg(i,m,n,m);
                    a[n][m]+='1';
                }
            }
            a[i][m].clear();            
        }
        if(i>1){
            for(int k=(int)a[i][1].size()-1;k>=0;--k){
                if(a[i][1][k]=='0'){
                    ans.pb(i,1,1,1);
                    dbg(i,1,1,1);
                    a[1][1]+='0';
                }else{
                    assert(0);
                    ans.pb(i,1,i,m);
                    dbg(i,1,i,m);
                    a[i][m]+='1';
                }
            }
            a[i][1].clear();
        }
        dbg("ok row",i);
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)dbg(i,j,a[i][j]);
    
    int c0,c1;
    c0=count(b[1][1].begin(), b[1][1].end(),'0');
    c1=count(b[1][1].begin(), b[1][1].end(),'1');
    while(c0--){
        ans.pb(1,1,1,m);
        dbg(1,1,1,m);
    }
    while(c1--){
        ans.pb(n,m,n,1);
        dbg(n,m,n,1);
    }
    for(int k=(int)b[1][1].size()-1;k>=0;--k){
        if(b[1][1][k]=='0'){ans.pb(1,m,1,1);
            dbg(1,m,1,1);
        }
        else {ans.pb(n,1,1,1);dbg(n,1,1,1);}
    }
    dbg("ok b 1 1");
    c0=count(b[n][m].begin(), b[n][m].end(),'0');
    c1=count(b[n][m].begin(), b[n][m].end(),'1');
    while(c0--){
        ans.pb(1,1,1,m);
        dbg(1,1,1,m);
    }
    while(c1--){
        ans.pb(n,m,n,1);
        dbg(n,m,n,1);
    }
    for(int k=(int)b[n][m].size()-1;k>=0;--k){
        if(b[n][m][k]=='0'){ans.pb(1,m,n,m);dbg(1,m,n,m);}
        else {ans.pb(n,1,n,m);dbg(n,1,n,m);}
    }
    dbg("ok b n m");
    for(int i=1;i<=n;++i){
        for(int j=2;j<m;++j){
            for(int k=(int)b[i][j].size()-1;k>=0;--k){
                if(b[i][j][k]=='0'){
                    if(i>1)ans.pb(1,1,i,1);
                    if(i>1)dbg(1,1,i,1);
                    ans.pb(i,1,i,j);
                    dbg(i,1,i,j);
                }else{
                    if(i<n)ans.pb(n,m,i,m);
                    if(i<n)dbg(n,m,i,m);
                    ans.pb(i,m,i,j);
                    dbg(i,m,i,j);
                }
            }
        }
        int need=i<n?count(b[i][m].begin(), b[i][m].end(),'0'):0;
        if(i>1){
            while(need--){ans.pb(1,1,i,1);dbg(1,1,i,1);}
            for(int k=(int)b[i][1].size()-1;k>=0;--k){
                if(b[i][1][k]=='0'){
                    ans.pb(1,1,i,1);
                    dbg(1,1,i,1);
                }else{
                    if(i<n)ans.pb(n,m,i,m);
                    if(i<n)dbg(n,m,i,m);
                    ans.pb(i,m,i,1);
                    dbg(i,m,i,1);
                }
            }
        }
        if(i<n){
            for(int k=(int)b[i][m].size()-1;k>=0;--k){
                if(b[i][m][k]=='0'){
                    ans.pb(i,1,i,m);
                    dbg(i,1,i,m);
                }else{
                    ans.pb(n,m,i,m);
                    dbg(n,m,i,m);
                }
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto&i:ans)
        cout<<i.x1<<' '<<i.y1<<' '<<i.x2<<' '<<i.y2<<'\n';

    return 0;
}