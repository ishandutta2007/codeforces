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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        int N;cin>>N;
        if(N<=30) cout<<"NO\n";
        else if(N>=45){
            cout<<"YES\n";
            cout<<"6 10 14 "<<N-30<<"\n";
        }else if(N==36){
            cout<<"YES\n";
            cout<<"6 10 15 5"<<"\n";
        }else if(N==40){
            cout<<"YES\n";
            cout<<"6 10 15 9"<<"\n";
        }else if(N==44){
            cout<<"YES\n";
            cout<<"6 10 15 13"<<"\n";
        }else{
            cout<<"YES\n";
            cout<<"6 10 14 "<<N-30<<"\n";
        }
    }
}