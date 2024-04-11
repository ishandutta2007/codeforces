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
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        string A(N,'.'),B(N,'.');
        int cnt=0,cnt2=0,cnt3=0;
        for(int i=0;i<N;i++) if(S[i]=='1') cnt++;
        
        if(cnt&1){
            cout<<"NO"<<"\n";
            continue;
        }
        
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                cnt2++;
                if(cnt2<=cnt/2) A[i]=B[i]='(';
                else A[i]=B[i]=')';
            }else{
                cnt3++;
                if(cnt3&1){
                    A[i]='(';
                    B[i]=')';
                }else{
                    A[i]=')';
                    B[i]='(';
                }
            }
        }
        
        bool ok=true;
        
        int sum=0;
        for(int i=0;i<N;i++){
            if(A[i]=='(') sum++;
            else sum--;
            
            if(sum<0) ok=false;
        }
        
        sum=0;
        
        for(int i=0;i<N;i++){
            if(B[i]=='(') sum++;
            else sum--;
            
            if(sum<0) ok=false;
        }
        
        if(ok){
            cout<<"YES\n";
            cout<<A<<"\n";
            cout<<B<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
}