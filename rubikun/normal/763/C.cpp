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
const int mod=998244353,MAX=300005,INF=1<<30;

// https://judge.yosupo.jp/submission/1669

ll P;//P=mod

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%P;
        a=a*a%P;
        b/=2;
    }
    return ans;
}

#include <stdio.h>
//#define ll long long
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}


//mod p
//Cipolla's algorithm
ll sqrtp(ll n,int p){
    //
    n%=p;
    if(n<2)return n;
    if(pom(n,p/2,p)!=1)return -1;
    
    ll ans;
    if(p%4==3){
        //p=4k+3nn^(2k+1)=1
        //n^(2k+2)=nn^(k+1)
        ans=pom(n,p/4+1,p);
    }else if(p%8==5){
        //p=8k+5nn^(4k+2)=1
        //n^(2k+1)=1
        if(pom(n,p/4,p)==1){
            //n^(2k+1)=1
            //n^(2k+2)=nn^(k+1)
            ans=pom(n,p/8+1,p);
        }else{
            //n^(2k+1)=-1
            //2
            //2^(4k+2)=-1(4n)^(2k+1)=1
            ll t=pom(4*n,p/8+1,p);
            if(t%2)ans=(t+p)/2;
            else ans=t/2;
        }
    }else{
        //x=m^2-nm
        ll m=1;
        while(pom(m*m-n+p,p/2,p)==1)m++;
        ll x=(m*m-n+p)%p;
        /*
         Fp(x)(m+x)^p = m^p+x^((p-1)/2+1/2) = m-x 
         (m+x)^(p+1)=m*m-x=n
         (m+x)^((p+1)/2)=a+bx
         n=(a+bx)^2=(a*a+b*b*x)+2*a*b*x
         b0a=0b*b*x=n 
         (m+x)^((p+1)/2)Fp
         */
        //Fp(x)=Fp^2
        ll i=p/2+1;
        ll aa=m,bb=1,a=1,b=0,ta,tb;
        while(i){
            if(i%2){
                ta=(a*aa+b*bb%p*x)%p;
                tb=(a*bb+b*aa)%p;
                a=ta;b=tb;
            }
            ta=(aa*aa+bb*bb%p*x)%p;
            tb=(aa*bb*2)%p;
            aa=ta;bb=tb;
            i/=2;
        }
        ans=(a+p)%p;
    }
    if(ans*2>p)return p-ans;
    else return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>P;
    ll N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    if(N==1){
        cout<<A[0]<<" "<<0<<endl;
        return 0;
    }
    if(N==P){
        cout<<A[0]<<" "<<1<<endl;
        return 0;
    }
    if(N==P-1){
        set<ll> SE;
        for(int i=0;i<N;i++) SE.insert(A[i]);
        for(int i=0;i<P;i++){
            if(!SE.count(i)){
                cout<<(i+1)%P<<" "<<1<<endl;
                return 0;
            }
        }
    }
    ll sum1=0,sum2=0;
    for(int i=0;i<N;i++){
        sum1+=A[i];
        sum1%=P;
        sum2+=(A[i]*A[i])%P;
        sum2%=P;
    }
    sum1*=rui(N,P-2);sum1%=P;
    sum2*=rui(N,P-2);sum2%=P;
    
    ll X=(P+sum2-sum1*sum1%P)%P;
    X*=12;X%=P;
    X*=rui((N*N-1)%P,P-2);X%=P;
    
    ll d=sqrtp(X,P);
    if(d==-1){
        cout<<-1<<endl;
        return 0;
    }
    
    ll x=(P+sum1-(N-1)*d%P*rui(2,P-2)%P)%P;
    
    //cout<<x<<" "<<d<<endl;
    //cout<<sum1<<" "<<sum2<<endl;
    
    set<ll> S,T;
    for(int i=0;i<N;i++){
        S.insert((x+d*i)%P);
        T.insert(A[i]);
    }
    if(S==T){
        cout<<x<<" "<<d<<endl;
    }else{
        cout<<-1<<endl;
    }
}