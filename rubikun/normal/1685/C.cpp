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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;N*=2;
        string S;cin>>S;
        vector<int> rui(N+1);
        
        bool f=true;
        vector<int> ng;
        for(int i=0;i<N;i++){
            rui[i+1]=rui[i];
            if(S[i]=='(') rui[i+1]++;
            if(S[i]==')') rui[i+1]--;
            f&=(rui[i+1]>=0);
            if(rui[i+1]<0) ng.push_back(i+1);
        }
        
        if(f){
            cout<<0<<"\n";
            continue;
        }
        
        pair<int,int> mal=mp(-1,-1),mar=mp(-1,-1);
        
        for(int i=0;i<ng.front();i++){
            chmax(mal,mp(rui[i],i));
        }
        for(int i=ng.back()+1;i<=N;i++){
            if(rui[i]>mar.fi) mar=mp(rui[i],i);
        }
        
        string T;
        for(int i=0;i<mal.se;i++) T+=S[i];
        for(int i=mar.se-1;i>=mal.se;i--) T+=S[i];
        for(int i=mar.se;i<N;i++) T+=S[i];
        
        int s=0;
        f=true;
        
        for(int i=0;i<N;i++){
            if(T[i]=='(') s++;
            if(T[i]==')') s--;
            f&=(s>=0);
        }
        
        if(f){
            cout<<1<<"\n";
            cout<<mal.se+1<<" "<<mar.se<<"\n";
            continue;
        }
        
        pair<int,int> ma=mp(-1,-1);
        
        for(int i=0;i<=N;i++) chmax(ma,mp(rui[i],i));
        
        cout<<2<<"\n";
        cout<<1<<" "<<ma.se<<"\n";
        cout<<ma.se+1<<" "<<N<<"\n";
    }
}