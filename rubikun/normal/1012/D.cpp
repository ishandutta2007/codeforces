#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

vector<pair<int,int>> ans;
vector<int> rs,rt;
string S,T;
int N,M;

void f(int a,int b){
    ans.push_back(mp(a,b));
    
    if(a) rs.pop_back();
    if(b) rt.pop_back();
    
    if(a){
        if(si(rt)) rt.back()+=a;
        else rt.push_back(a);
    }
    
    if(b){
        if(si(rs)) rs.back()+=b;
        else rs.push_back(b);
    }
}

void g(int a,int b){
    ans.push_back(mp(a,b));
    string U,V;
    U+=T.substr(0,b);
    V+=S.substr(0,a);
    
    U+=S.substr(a);
    V+=T.substr(b);
    
    S=U;
    T=V;
    N=si(S);
    M=si(T);
}

void make(string &X,vector<int> &s){
    s.clear();
    int ii=0;
    while(ii<si(X)){
        int j=ii;
        while(j<si(X)&&X[ii]==X[j]) j++;
        s.push_back(j-ii);
        ii=j;
    }
    reverse(all(s));
}

void output(){
    cout<<S<<" "<<T<<endl;
    
    for(auto a:rs) cout<<a<<" ";
    cout<<endl;
    for(auto a:rt) cout<<a<<" ";
    cout<<endl;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>S>>T;
    N=si(S);M=si(T);
    
    make(S,rs);
    make(T,rt);
    
    if(si(rs)==1&&si(rt)==1){
        cout<<0<<endl;
        return 0;
    }
    
    bool ch=false;
    
    if(si(rs)<si(rt)){
        ch=true;
        swap(S,T);
        swap(N,M);
        swap(rs,rt);
        for(auto &a:ans) swap(a.se,a.fi);
    }
    
    if(abs(si(rs)-si(rt))>=2){
        if((si(rs)&1)&&(si(rt)&1)){
            if(S[0]==T[0]){
                int k=(si(rs)+si(rt)-1)/2;
                if(k&1){
                    int sum=0;
                    for(int i=0;i<k-(si(rt)-1);i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }else{
                    int sum=0;
                    for(int i=0;i<k+1-(si(rt)-1);i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }
            }else{
                int k=(si(rs)+si(rt)-1)/2;
                if(k&1){
                    int sum=0;
                    for(int i=0;i<k+1-(si(rt)-1);i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }else{
                    int sum=0;
                    for(int i=0;i<k-(si(rt)-1);i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }
            }
        }else if((si(rs)&1)==(si(rt)&1)){
            if(S[0]==T[0]){
                int k=(si(rs)+si(rt)-1)/2;
                if(k&1){
                    int sum=0;
                    for(int i=0;i<k+1-(si(rt)-1);i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }else{
                    int sum=0;
                    for(int i=0;i<k-(si(rt)-1);i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }
            }else{
                int k=(si(rs)+si(rt)-1)/2;
                if(k&1){
                    int sum=0;
                    for(int i=0;i<k-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                    g(sum,rt.back());
                }else{
                    int sum=0;
                    for(int i=0;i<k+1-(si(rt)-1);i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }
            }
        }else if(si(rs)&1){
            if(S[0]==T[0]){
                int k=(si(rs)+si(rt)-2)/2;
                if(k&1){
                    int sum=0;
                    for(int i=0;i<k+1-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                    g(sum,rt.back());
                }else{
                    int sum=0;
                    for(int i=0;i<k-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                    g(sum,rt.back());
                }
            }else{
                int k=(si(rs)+si(rt)-2)/2;
                if(k&1){
                    int sum=0;
                    for(int i=0;i<k-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                    g(sum,rt.back());
                }else{
                    int sum=0;
                    for(int i=0;i<k+1-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                    g(sum,rt.back());
                }
            }
        }else{
            if(si(rt)==1){
                if(S[0]==T[0]){
                    int k;
                    if(si(rs)%4==0) k=si(rs)/2-1;
                    else k=si(rs)/2;
                    int sum=0;
                    
                    for(int i=0;i<k;i++) sum+=rs[si(rs)-1-i];
                    g(sum,0);
                }else{
                    int k=si(rs)/2;
                    int sum=0;
                    for(int i=0;i<k;i++) sum+=rs[si(rs)-1-i];
                    if(si(rs)%4==2) g(sum,rt.back());
                    else g(sum,0);
                }
            }else{
                if(S[0]==T[0]){
                    int k=(si(rs)+si(rt)-2)/2;
                    int sum=0;
                    for(int i=0;i<k-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                    if(k&1) g(sum,rt.back());
                    else g(sum,0);
                }else{
                    int k=(si(rs)+si(rt)-2)/2;
                    if(k&1){
                        int sum=0;
                        for(int i=0;i<k+1-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                        g(sum,rt.back());
                    }else{
                        int sum=0;
                        for(int i=0;i<k-(si(rt)-2);i++) sum+=rs[si(rs)-1-i];
                        g(sum,rt.back());
                    }
                }
            }
        }
    }
    
    if(ch){
        swap(S,T);
        swap(N,M);
        swap(rs,rt);
        for(auto &a:ans) swap(a.se,a.fi);
    }
    
    make(S,rs);
    N=si(S);
    make(T,rt);
    M=si(T);
    
    //output();
    
    bool sw=false;
    
    if(si(rs)<si(rt)){
        sw=true;
        swap(S,T);
        swap(N,M);
        swap(rs,rt);
        if(si(ans)){
            for(auto &a:ans) swap(a.se,a.fi);
        }
    }
    
    if(S[0]==T[0]){
        if(si(rs)==si(rt)) f(0,rt.back());
        else f(rs.back(),0);
    }
    
    while(!(si(rs)==1&&si(rt)==1)){
        f(rs.back(),rt.back());
    }
    
    cout<<si(ans)<<endl;
    
    for(auto x:ans){
        if(sw) cout<<x.se<<" "<<x.fi<<"\n";
        else cout<<x.fi<<" "<<x.se<<"\n";
    }
}