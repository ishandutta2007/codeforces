#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;

const ll mod = 998244353;


//Unionfind
struct unionfind {
	//-1
	//id
	  vector<long long> r;
	  unionfind(long long N) {
		    r = vector<long long>(N, -1);
	  }
	  long long root(long long x) {
		    if (r[x] < 0) return x;
		    return r[x] = root(r[x]);
	  }
	  bool unite(long long x, long long y) {
		    x = root(x);
		    y = root(y);
		    if (x == y) return false;
		    if (r[x] > r[y]) swap(x, y);
		    r[x] += r[y];
		    r[y] = x;
		    return true;
	  }
	  long long size(long long x) {
		    return max(-r[root(x)],0LL);
	  }
  
  // 2x, ytrue
    bool same(long long x, long long y) { 
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
    void eval(ll i,ll x){
        r[i] = (-1)*x;
    }
};
  //main unionfind friends(N+1);
  //  friends.unite(a,b);
  //


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    string id1 = "hahah";
    string id2 = "ahaha";
    rep(ii,T){
        ll ans = 0;
        ll N; cin >> N;
        map<string,ll> lab;
        vector<tuple<ll,ll,ll,ll,ll>> div(N);
        vector<Tp> con(N);
        vector<string> SS(N);
        rep(i,N){
            string S; cin >> S; int j;
            if(!lab.count(S)){
                lab[S] = i; SS[i] = S; j = i;
            }
            else{
                j = lab[S];
            }
            string op; cin >> op;
            if(op==":="){
                string T; cin >> T;
                bool con1 = false;
                rep(k,T.size()){
                    if(T[k]!=id1[k]) break;
                    if(k==T.size()-1) con1 = true;
                }
                rep(k,T.size()){
                    if(T[k]!=id2[k]) break;
                    if(k==T.size()-1) con1 = true;
                }
                if(con1){
                    ll a1 = 0,b1= 0,c1=0;
                    if(T[0]=='a') a1 = 1;
                    if(T[T.size()-1]=='h') c1 = 1;
                    b1 = ((ll)(T.size())-(a1+c1))/2;
                    con[j] = make_tuple(a1,b1,c1);
                    div[j] = make_tuple(-1,-1,-1,-1,-1);
                    //cout << a1 << " " << b1 << " " << c1 << "\n";
                }
                else{
                    con[j] = make_tuple(-1,-1,-1);
                    ll a1 = 0,b1= 0,c1=0,d1 = 0,e1 = 0;
                    if(T[0]=='a') a1 = 1;
                    if(T[T.size()-1]=='h') e1 = 1;
                    if((ll)(T.size())-(a1+e1)>=2){
                        if(T.substr(a1,2)=="ha") b1 = 1;
                        if(T.substr((ll)(T.size())-2-e1,2)=="ha") d1 = 1;
                    }
                    if((ll)(T.size())-(a1+e1)>=4){
                        if(T.substr(a1,4)=="haha") b1 = 2;
                        if(T.substr((ll)(T.size())-4-e1,4)=="haha") d1 = 2;
                    }
                    div[j] = make_tuple(a1,b1,c1,d1,e1);
                    //cout << a1 << " " << b1 << " " << c1  << " " << d1 << " " << e1 << "\n";
                }
            }
            else{
                string U,V; cin >> U >> op >> V;
                int k1 = lab[U]; int k2 = lab[V];
                auto[a1,b1,c1] = con[k1]; auto[a2,b2,c2] = con[k2];
                auto[d1,e1,f1,g1,h1] = div[k1]; auto[d2,e2,f2,g2,h2] = div[k2];
                if(a1>=0&&a2>=0){
                    if((c1+a2)%2==0){
                        con[j] = make_tuple(a1,b1+(c1+a2)/2+b2,c2);
                        div[j] = make_tuple(-1,-1,-1,-1,-1);
                    }
                    else{
                        con[j] = make_tuple(-1,-1,-1);
                        div[j] = make_tuple(a1,b1,0,b2,c2);
                    }
                }
                else if(a1>=0){
                    con[j] = make_tuple(-1,-1,-1);
                    if((c1+d2)%2==0){
                        div[j] = make_tuple(a1,b1+(c1+d2)/2+e2,f2,g2,h2);
                    }
                    else{
                        div[j] = make_tuple(a1,b1,f2+max(0LL,e2-1),g2,h2);
                    }
                }
                else if(a1<0&&a2>=0){
                    con[j] = make_tuple(-1,-1,-1);
                    if((h1+a2)%2==0){
                        div[j] = make_tuple(d1,e1,f1,g1+(h1+a2)/2+b2,c2);
                    }
                    else{
                        div[j] = make_tuple(d1,e1,f1+max(0LL,g1-1),b2,c2);
                    }
                }
                else{
                    con[j] = make_tuple(-1,-1,-1);
                    if((h1+d2)%2==0){
                        div[j] = make_tuple(d1,e1,f1+f2+max(0LL,g1+(h1+d2)/2+e2-1),g2,h2);
                    }
                    else{
                        div[j] = make_tuple(d1,e1,f1+f2+max(0LL,g1-1)+max(0LL,e2-1),g2,h2);
                    }
                }
            }
            // if(ii==T-1){
            //     auto[aa,bb,cc] = con[j]; auto[dd,ee,ff,gg,hh] = div[j];
            //     if(aa>=0){
            //         //ans = max(0LL,bb-1);
            //         cout << aa << " " << bb << " " << cc << "\n";
            //     }
            //     else{
            //         //ans = ff + max(0LL,ee-1) + max(0LL,gg-1);
            //         cout << dd << " " << ee << " " << ff  << " " << gg << " " << hh << "\n";
            //     }
            // }
            if(i==N-1){
                auto[aa,bb,cc] = con[j]; auto[dd,ee,ff,gg,hh] = div[j];
                if(aa>=0){
                    ans = max(0LL,bb-1);
                    //cout << aa << " " << bb << " " << cc << "\n";
                }
                else{
                    ans = ff + max(0LL,ee-1) + max(0LL,gg-1);
                    //cout << dd << " " << ee << " " << ff  << " " << gg << " " << hh << "\n";
                }
            }
        }
        cout << ans << "\n";
    }
    
    //cout << ans << endl;
}