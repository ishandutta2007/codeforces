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
        int N;ll K;cin>>N>>K;
        if(N<=62&&(1LL<<(N-1))<K){
            cout<<-1<<"\n";
            continue;
        }
        
        vector<int> ans;
        
        for(int t=0;t<N;t++){
            for(int i=t;i<N;i++){
                if((N-1-i)>=62||i==N-1||(1LL<<(N-2-i))>=K){
                    ans.push_back(i);
                    int s=i-1;
                    while(s>=t){
                        ans.push_back(s);
                        s--;
                    }
                    t=i;
                    break;
                }else{
                    K-=(1LL<<(N-2-i));
                }
            }
        }
        
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }
}