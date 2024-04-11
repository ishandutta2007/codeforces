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

// xxx

template<typename T>
vector<T> fzt(vector<T> A,bool wh){
    int n=si(A);
    vector<T> res=A;
    
    for(int i=1;i<n;i*=2){
        for(int j=0;j<n;j++){
            if((j&i)==0){
                if(wh) res[j|i]+=res[j];
                else res[j]+=res[j|i];
            }
        }
    }
    
    return res;
}//wh==0 jx wh==1 xj x

template<typename T>
vector<T> fmt(vector<T> A,bool wh){
    int n=si(A);
    vector<T> res=A;
    
    for(int i=1;i<n;i*=2){
        for(int j=0;j<n;j++){
            if((j&i)==0){
                if(wh) res[j|i]-=res[j];
                else res[j]-=res[j|i];
            }
        }
    }
    
    return res;
}//wh==0 jx wh==1 xj xfzt

template<typename T>
vector<T> fwt_and(vector<T> A,vector<T> B){
    int n=si(A);
    A=fzt(A,0);
    B=fzt(B,0);
    vector<T> res(n);
    
    for(int i=0;i<n;i++) res[i]=A[i]*B[i];
    
    res=fmt(res,0);
    
    return res;
}

template<typename T>
vector<T> fwt_or(vector<T> A,vector<T> B){
    int n=si(A);
    A=fzt(A,1);
    B=fzt(B,1);
    vector<T> res(n);
    
    for(int i=0;i<n;i++) res[i]=A[i]*B[i];
    
    res=fmt(res,1);
    
    return res;
}

template<typename T>
vector<T> fwt_xor_sub(vector<T> A,bool t){
    int n=si(A);
    vector<T> res=A;
    
    for(int i=1;i<n;i*=2){
        for(int j=0;j<n;j++){
            if((j&i)==0){
                T x=res[j],y=res[j|i];
                if(t==0){
                    res[j]=x+y;
                    res[j|i]=x-y;
                }else{
                    res[j]=(x+y)/2;
                    res[j|i]=(x-y)/2;
                }// modint/2  *x(998244353*499122177)
            }
        }
    }
    
    return res;
}// t==0  t==1 

template<typename T>
vector<T> fwt_xor(vector<T> A,vector<T> B){
    int n=si(A);
    A=fwt_xor_sub(A,0);
    B=fwt_xor_sub(B,0);
    vector<T> res(n);
    
    for(int i=0;i<n;i++) res[i]=A[i]*B[i];
    
    res=fwt_xor_sub(res,1);
    
    return res;
}// modintfwt_xor_sub/2  *x(998244353*499122177)


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int N,M,P;cin>>N>>M>>P;
    vector<string> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    pair<int,vector<int>> ans=mp(-1,vector<int>{});
    
    for(int tt=0;tt<25;tt++){
        int u=rng()%N;
        vector<string> T(N);
        vector<int> use;
        
        for(int j=0;j<M;j++){
            if(S[u][j]=='1'){
                for(int i=0;i<N;i++) T[i]+=S[i][j];
                use.push_back(j);
            }
        }
        
        vector<int> X((1<<si(T[0])));
        for(int i=0;i<N;i++){
            int a=0;
            for(int j=0;j<si(T[i]);j++){
                if(T[i][j]=='1') a+=(1<<j);
            }
            X[a]++;
        }
        vector<int> Y=fzt(X,0);
        
        for(int i=0;i<(1<<si(T[0]));i++){
            if(Y[i]>=(N+1)/2){
                int k=__builtin_popcount(i);
                vector<int> Z;
                for(int j=0;j<si(T[0]);j++) if(i&(1<<j)) Z.push_back(use[j]);
                
                chmax(ans,mp(k,Z));
            }
        }
    }
    
    string res(M,'0');
    for(int a:ans.se) res[a]='1';
    
    cout<<res<<endl;
}