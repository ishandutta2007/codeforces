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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int N;cin>>N;
    vector<ll> A;
    for(int i=0;i<N;i++){
        ll x;cin>>x;
        if(A.empty()||A.back()!=x) A.push_back(x);
    }
    N=si(A);
    if(N<=40){
        for(ll j=1;;j++){
            ll l=j*j-A[0],r=j*j+j-A[0];
            if(r<0) continue;
            chmax(l,0LL);
            bool f=true;
            for(ll x:A){
                ll n=x+l;
                ll t=sqrt(n);
                if(t*t<=n&&n<=t*t+t){
                    chmin(r,t*t+t-x);
                }else{
                    t++;
                    if(x+r<t*t){
                        f=false;
                        break;
                    }
                    chmax(l,t*t-x);
                }
                if(l>r){
                    f=false;
                    break;
                }
            }
            if(f){
                cout<<l<<endl;
                return 0;
            }
        }
    }else{
        for(ll j=1;;j++){
            ll l=j*j-A[0],r=j*j+j-A[0];
            if(r<0) continue;
            chmax(l,0LL);
            bool f=true;
            for(int q=0;q<min(6000,N);q++){
                ll x=A[rng()%N];
                ll n=x+l;
                ll t=sqrt(n);
                if(t*t<=n&&n<=t*t+t){
                    chmin(r,t*t+t-x);
                }else{
                    t++;
                    if(x+r<t*t){
                        f=false;
                        break;
                    }
                    chmax(l,t*t-x);
                }
                if(l>r){
                    f=false;
                    break;
                }
            }
            if(f){
                for(ll x:A){
                    ll n=x+l;
                    ll t=sqrt(n);
                    if(t*t<=n&&n<=t*t+t){
                        chmin(r,t*t+t-x);
                    }else{
                        t++;
                        if(x+r<t*t){
                            f=false;
                            break;
                        }
                        chmax(l,t*t-x);
                    }
                    if(l>r){
                        f=false;
                        break;
                    }
                }
                if(f){
                    cout<<l<<endl;
                    return 0;
                }
            }
        }
    }
}