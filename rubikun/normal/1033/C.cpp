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
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;

bool aru[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),id(N),grundy(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    iota(all(id),0);
    sort(all(id),[&](int a,int b){
        return A[a]>A[b];
    });
    
    for(int i:id){
        for(int j=i-A[i];j>=0;j-=A[i]){
            if(A[j]>A[i]) aru[grundy[j]]=1;
        }
        for(int j=i+A[i];j<N;j+=A[i]){
            if(A[j]>A[i]) aru[grundy[j]]=1;
        }
        
        for(int j=0;;j++){
            if(!aru[j]){
                grundy[i]=j;
                break;
            }
        }
        
        for(int j=i-A[i];j>=0;j-=A[i]){
            if(A[j]>A[i]) aru[grundy[j]]=0;
        }
        for(int j=i+A[i];j<N;j+=A[i]){
            if(A[j]>A[i]) aru[grundy[j]]=0;
        }
        
    }
    
    for(int i=0;i<N;i++){
        if(grundy[i]) cout<<'A';
        else cout<<'B';
    }
    
    cout<<endl;
    
}