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
        string S;cin>>S;
        int N=si(S);
        vector<deque<int>> pos(10);
        for(int i=0;i<N;i++){
            pos[(int)(S[i]-'0')].push_back(i);
        }
        
        int now=-1;
        
        vector<int> cn(10),rem(10);
        
        while(now<N){
            for(int i=0;i<10;i++){
                while(si(pos[i])&&pos[i].front()<now){
                    rem[i]++;
                    pos[i].pop_front();
                }
            }
            for(int i=0;i<10;i++){
                if(si(pos[i])){
                    int a=pos[i][0];pos[i].pop_front();
                    cn[(int)(S[a]-'0')]++;
                    now=a;
                    break;
                }
                
                if(i==9){
                    now=N;
                    break;
                }
            }
        }
        
        for(int i=0;i<10;i++){
            for(int j=0;j<cn[i];j++) cout<<i;
            for(int j=0;j<rem[i];j++) cout<<min(9,i+1);
        }
        cout<<"\n";
    }
}