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
const ll INF=1000000000000000000LL;

bool f(string &S){
    if(S=="Yes") return 1;
    else return 0;
}

int main(){
    
    /*std::ifstream in("text.txt");
     std::cin.rdbuf(in.rdbuf());
     cin.tie(0);
     ios::sync_with_stdio(false);*/
    
    mt19937_64 rng(51);
    
    ll N,k;cin>>N>>k;
    
    if(N<=k) k=N-1;
    
    ll left=1,right=N;
    
    int cnt=0;
    
    while(1){
        
        while(right-left>=4*k+1){
            ll mid=(left+right)/2;
            cout<<left<<" "<<mid<<endl;
            string S;cin>>S;
            
            if(left==mid&&f(S)) return 0;
            
            if(S=="Bad"){
                return 0;
            }
            
            if(f(S)){
                left=max(1LL,left-k);
                right=min(N,mid+k);
            }else{
                left=max(1LL,mid+1-k);
                right=min(N,right+k);
            }
        }
        ll Q=(left+right)/2;
        ll p=rng()%(6*k+1)-3*k;
        Q+=p;
        chmax(Q,left);
        chmin(Q,right);
        
        //Q=left;
        
        cout<<Q<<" "<<Q<<endl;
        string S;cin>>S;
        if(S=="Bad"){
            return 0;
        }
        if(f(S)) return 0;
        left=max(1LL,left-k);
        right=min(N,right+k);
        
        cnt++;
    }
}