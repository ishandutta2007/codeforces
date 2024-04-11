#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    ll X,Y;cin>>N>>X>>Y;
    string S;cin>>S;
    
    int i=0,cnt=0;
    bool check=false;
    while(i<N){
        if(S[i]=='1'){
            i++;
            check=true;
        }else{
            while(i<N&&S[i]=='0') i++;
            cnt++;
        }
    }
    
    if(!check){
        cout<<Y<<endl;
    }else{
        if(cnt==0) cout<<0<<endl;
        
        else cout<<min(X,Y)*(cnt-1)+Y<<endl;
    }
}