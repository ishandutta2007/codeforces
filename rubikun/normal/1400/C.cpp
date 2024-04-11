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
const int mod=1000000007,MAX=2005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int x;cin>>x;
        int N=si(S);
        vector<int> check(N,0);
        
        bool ok=true;
        
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                if(i-x>=0&&i+x<N) continue;
                if(i-x<0&&i+x>=N) ok=false;
                
                if(i-x>=0) check[i-x]|=2;
                if(i+x<N) check[i+x]|=2;
            }else{
                if(i-x>=0) check[i-x]|=1;
                if(i+x<N) check[i+x]|=1;
            }
        }
        
        for(int i=0;i<N;i++){
            if(check[i]==3) ok=false;
        }
        
        if(!ok) cout<<-1<<"\n";
        else{
            string T;
            for(int i=0;i<N;i++){
                if(check[i]==1) T+='0';
                else T+='1';
            }
            
            for(int i=0;i<N;i++){
                if(S[i]=='1'){
                    if((i-x>=0&&T[i-x]=='1')||(i+x<N&&T[i+x]=='1')) {}
                    else ok=false;
                }else{
                    if((i-x>=0&&T[i-x]=='1')||(i+x<N&&T[i+x]=='1')) ok=false;
                }
            }
            
            if(ok) cout<<T<<"\n";
            else cout<<-1<<"\n";
        }
    }
}