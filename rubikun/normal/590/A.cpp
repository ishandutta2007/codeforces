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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N+2);
    for(int i=0;i<N;i++){
        cin>>A[i+1];
    }
    A[0]=A[1];
    A[N+1]=A[N];
    int ma=0;
    for(int i=0;i<=N;){
        if(A[i]!=A[i+1]){
            int j=i;
            while(j<=N&&A[j]!=A[j+1]) j++;
            chmax(ma,(j-i)/2);
            i=j;
        }else{
            i++;
        }
    }
    cout<<ma<<endl;
    vector<pair<int,int>> S;
    for(int i=0;i<=N+1;){
        if(A[i]==A[i+1]){
            int j=i;
            while(j<=N+1&&A[i]==A[j]) j++;
            S.push_back(mp(i,j-1));
            i=j;
        }else{
            i++;
        }
    }
    for(int i=0;i+1<si(S);i++){
        if(A[S[i].se]==A[S[i+1].fi]){
            for(int j=S[i].se+1;j<S[i+1].fi;j++) A[j]=A[S[i].se];
        }else{
            int k=(S[i+1].fi-S[i].se)/2;
            for(int j=S[i].se+1;j<=S[i].se+k;j++) A[j]=A[S[i].se];
            for(int j=S[i].se+k+1;j<=S[i].se+k+k;j++) A[j]=A[S[i+1].fi];
        }
    }
    
    for(int i=1;i<=N;i++) cout<<A[i]<<" ";
    cout<<endl;
}