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
const int INF=1<<30;
//const ll INF=1LL<<60;

vector<string> res;
set<ll> SE;

ll add(ll a,ll b){
    string U;
    U+=to_string(a);
    U+=" + ";
    U+=to_string(b);
    res.push_back(U);
    
    SE.insert(a+b);
    return a+b;
}

ll xo(ll a,ll b){
    string U;
    U+=to_string(a);
    U+=" ^ ";
    U+=to_string(b);
    res.push_back(U);
    
    SE.insert(a^b);
    return a^b;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll X;cin>>X;
    
    SE.insert(X);
    
    while(1){
        int m=-1;
        for(int k=61;k>=0;k--){
            if(X&(1LL<<k)){
                m=k;
                break;
            }
        }
        ll now=X;
        while(1){
            bool ok=false;
            for(int k=0;k<62;k++){
                if(now&(1LL<<k)){
                    if(k==m) ok=true;
                    break;
                }
            }
            if(ok) break;
            now=add(now,now);
        }
        
        ll A=xo(X,now);
        ll B=add(X,now);
        ll C=xo(A,B);
        
        //cout<<"X    "<<bitset<62>(X)<<endl;
        //cout<<"now  "<<bitset<62>(now)<<endl;
        //cout<<"A    "<<bitset<62>(A)<<endl;
        //cout<<"B    "<<bitset<62>(B)<<endl;
        //cout<<"C    "<<bitset<62>(C)<<endl;
        
        int m2=-1;
        for(int k=61;k>=0;k--){
            if(C&(1LL<<k)){
                m2=k;
                break;
            }
        }
        ll now2=C;
        
        //cout<<"now2 "<<bitset<62>(now2)<<endl;
        
        if(__builtin_popcountll(now2)==1){
            while(now2<=A){
                if(A&now2) A=xo(A,now2);
                now2=add(now2,now2);
            }
            ll Y=xo(X,A);
            X=xo(X,Y);
        }else{
            ll D=add(now2,now2);
            ll E=xo(D,now2);
            //2
            
            //cout<<"E    "<<bitset<62>(E)<<endl;
            
            int m3=-1,m4=-1;
            for(int k=61;k>=0;k--){
                if(E&(1LL<<k)){
                    if(m3==-1)m3=k;
                    else m4=k;
                }
            }
            ll now3=E;
            
            while(1){
                bool ok=false;
                for(int k=0;k<62;k++){
                    if(now3&(1LL<<k)){
                        if(k==m3) ok=true;
                        break;
                    }
                }
                if(ok) break;
                now3=add(now3,now3);
            }
            
            ll F=xo(E,now3);
            ll G=add(E,now3);
            ll H=xo(F,G);
            
            //cout<<"H    "<<bitset<62>(H)<<endl;
            
            ll I=xo(H,H^(H>>(m3-m4)));
            
            while(1){
                if(E&I) break;
                I=add(I,I);
            }
            E=xo(E,I);
            
            now2=E;
            
            while(now2<=A){
                if(A&now2) A=xo(A,now2);
                now2=add(now2,now2);
            }
            ll Y=xo(X,A);
            X=xo(X,Y);
        }
        
        if(SE.count(1)) break;
    }
    
    cout<<si(res)<<"\n";
    for(string X:res) cout<<X<<"\n";
}