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
        int n;cin>>n;
        string S;cin>>S;
        string T;
        int id=0;
        while(id<n&&S[id]=='0'){
            T+='0';
            id++;
        }
        for(int i=n-1;i>=id;i--){
            if(S[i]=='0'){
                T+='0';
                for(int j=i+1;j<n;j++) T+='1';
                break;
            }
            if(i==id){
                for(int j=i;j<n;j++) T+='1';
            }
        }
        
        cout<<T<<"\n";
    }
}