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
        string S;cin>>S;
        int N=si(S);
        
        int ma=-1;
        
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                int now=0;
                int sum=0;
                
                while(now<N){
                    if(sum&1){
                        if(int(S[now]-'0')==j){
                            sum++;
                        }
                    }else{
                        if(int(S[now]-'0')==i){
                            sum++;
                        }
                    }
                    now++;
                }
                if(i==j) chmax(ma,sum);
                else chmax(ma,sum/2*2);
            }
        }
        
        cout<<N-ma<<"\n";
    }
}