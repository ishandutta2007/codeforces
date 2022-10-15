#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;

const int N=55;
struct kal{
    int x,y,i;
    kal(int a,int b,int c):x(a),y(b),i(c){}
};
int f[N][N];
int fx[N],fy[N],x[N],y[N];
struct movement{
    int a,b,c,d;
};
vector<movement>ans;
std::ostream & operator <<(std::ostream & os, movement & p) {
    return os << p.a << ' ' << p.b << ' ' << p.c << ' ' << p.d;
}
void mv(int x1,int y1,int x2,int y2){
    ans.push_back({x1,y1,x2,y2});
    int num=f[x1][y1];
    x[num]=x2;
    y[num]=y2;
    f[x1][y1]=0;
    f[x2][y2]=num;
    dbg(ans.back());
}

vector<pii> fly[N];
int num[N];

int32_t main() {

    int n,m;
    cin>>n>>m;
    for(int i =1;i<=m;++i){
        cin>>x[i]>>y[i];
        f[x[i]][y[i]]=i;
    }
    for(int i =1;i<=m;++i){
        cin>>fx[i]>>fy[i];
        fly[fy[i]].pb(-fx[i],i);
    }

    int boom=0;
    for(int j=1;j<=n;++j){
        sort(fly[j].begin(), fly[j].end());
        for(int k=0;k<fly[j].size();++k)
            num[fly[j][k].s]=k;
        if(f[1][j]){
            for(int k=j;k>boom+1;--k){
                mv(1,k,1,k-1);
            }
            boom++;
        }
    }
    dbg("first line ok");
    vector<kal>a;
    for(int i =1;i<=m;++i)
        if(x[i]!=1)
            a.pb(x[i],y[i],i);

    sort(a.begin(), a.end(),[](const auto&p1,const auto&p2){
        return p1.x==p2.x?p1.y>p2.y:p1.x<p2.x;
    });

    for (kal i:a){
        // for(int k=i.y;k<n;++k)
        //     mv(i.x,k,i.x,k+1);
        for (int k=i.x;k>2;--k)
            mv(k,i.y,k-1,i.y);
        for (int k=i.y;k<=boom;++k)
            mv(2,k,2,k+1);
        mv(2,y[i.i],1,y[i.i]);
        for(int k=y[i.i];k>boom+1;--k){
            mv(1,k,1,k-1);
        }
        boom++;
    }

    dbg("all first line");
    assert(boom==m);

    a.clear();
    for(int i=1;i<=m;++i){
        assert(x[i]==1);
        a.pb(x[i],y[i],i);
    }

    sort(a.begin(), a.end(),[&](const auto&p1,const auto&p2){
        return num[p1.i]<num[p2.i];
    });

    for (int z=0;z<m;++z){
        kal c=a[z];
        int ox=1;
        if (z==m-1){
            ;
        }else{
            ox=2;
            mv(1,c.y,2,c.y);
        }
        if(c.y<fy[c.i]){
            for (int k=c.y;k<fy[c.i];++k){
                mv(ox,k,ox,k+1);
            }
        }else if(c.y>fy[c.i]){
            for (int k=c.y;k>fy[c.i];--k){
                mv(ox,k,ox,k-1);
            }            
        }
        int flx=n-num[c.i];
        for (int k=ox;k<flx;++k){
            mv(k,fy[c.i],k+1,fy[c.i]);
        }
    }
    dbg("all in rows");

    for (int j=1;j<=n;++j){
        if(fly[j].empty()) continue;
        for (int z=fly[j].size()-1;z>=0;--z){
            for (int k=n-z;k>fx[fly[j][z].s];--k)
                mv(k,j,k-1,j);
        }
    }
    dbg("okay");

    for(int i=1;i<=m;++i)
        assert(x[i]==fx[i]&&y[i]==fy[i]);

    cout<<ans.size()<<'\n';
    for(auto i:ans)
        cout<<i<<'\n';
    return 0;
}