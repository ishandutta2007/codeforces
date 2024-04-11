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
const int mod=1000000007,MAX=200005,INF=1<<30;
const double M_PI=acos((long double)-1.0L);
struct C{
    double x;
    double y;
    
    C operator + (const C &other)const{
        return {x+other.x , y+other.y};
    };
    
    C operator - (const C &other)const{
        return {x-other.x , y-other.y};
    };
    
    C operator * (const C &other)const{
        return {x*other.x-y*other.y , x*other.y+y*other.x};
    };
    
};

vector<C> fft(vector<C> &a,bool inverse){//inverse==1
    int n=a.size();
    int h=0;
    for(int i=0;(1<<i)<n;i++) h++;
    
    for(int i=0;i<n;i++){
        int j=0;
        for(int k=0;k<h;k++) j|=((i>>k)&1)<<(h-1-k);
        if(i<j) swap(a[i],a[j]);
    }
    
    for(int b=1;b<n;b<<=1){
        for(int j=0;j<b;j++){
            C w;
            if(inverse==1){
                double re=cos((2*M_PI)/(2*b)*j*1),im=sin((2*M_PI)/(2*b)*j*1);
                w=C{re,im};
            }else{
                double re=cos((2*M_PI)/(2*b)*j*(-1)),im=sin((2*M_PI)/(2*b)*j*(-1));
                w=C{re,im};
            }
            
            for(int k=0;k<n;k+=b*2){
                C s=a[j+k];
                C t=a[j+k+b]*w;
                a[j+k]=s+t;
                a[j+k+b]=s-t;
            }
        }
    }
    
    if(inverse) for(int i=0;i<n;i++){
        a[i].x/=n;
        a[i].y/=n;
    }
    return a;
}

vector<C> fft(vector<double> &a,bool inverse){//
    
    vector<C> a_complex(a.size());
    for(int i=0;i<a.size();i++) a_complex[i]=C{a[i],0};
    return fft(a_complex,inverse);
}

vector<double> convolve(vector<double> &a,vector<double> &b){//
    
    int s=a.size()+b.size()-1;
    int t=1;
    while(t<s) t*=2;
    
    a.resize(t);
    b.resize(t);
    
    vector<C> A=fft(a,0),B=fft(b,0);
    for(int i=0;i<t;i++) A[i]=A[i]*B[i];
    
    A=fft(A,1);
    a.resize(s);
    for(int i=0;i<s;i++) a[i]=A[i].x;
    return a;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        vector<double> a(N),b(N);
        
        for(int i=0;i<N;i++){
            if(S[i]=='V') a[i]+=1.0;
            if(S[i]=='K') b[N-1-i]+=1.0;
        }
        
        vector<double> c=convolve(a,b);
        
        vector<int> ok(N+1,1);
        
        for(int i=0;i<si(c);i++){
            if(abs(c[i])>=0.2) ok[abs(i-(N-1))]=0;
        }
        
        vector<int> ans(N+1,1);
        
        for(int i=1;i<=N;i++){
            for(int j=1;i*j<=N;j++){
                if(!ok[i*j]) ans[i]=0;
            }
        }
        
        int cnt=0;
        
        for(int i=1;i<=N;i++) if(ans[i]) cnt++;
        
        cout<<cnt<<"\n";
        for(int i=1;i<=N;i++) if(ans[i]) cout<<i<<" ";
        cout<<"\n";
    }
}