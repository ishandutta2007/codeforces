#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=500005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int ans=0;
        map<pair<int,int>,int> MA;
        int x=0,y=0;
        
        for(int i=0;i<si(S);i++){
            if(S[i]=='N'){
                if(MA[{x,y}]&1) ans++;
                else{
                    ans+=5;
                    MA[{x,y}]^=1;
                }
                x++;
            }
            if(S[i]=='S'){
                if(MA[{x-1,y}]&1) ans++;
                else{
                    ans+=5;
                    MA[{x-1,y}]^=1;
                }
                x--;
            }
            if(S[i]=='E'){
                if(MA[{x,y}]&2) ans++;
                else{
                    ans+=5;
                    MA[{x,y}]^=2;
                }
                y++;
            }
            if(S[i]=='W'){
                if(MA[{x,y-1}]&2) ans++;
                else{
                    ans+=5;
                    MA[{x,y-1}]^=2;
                }
                y--;
            }
        }
        cout<<ans<<"\n";
    }
    
}