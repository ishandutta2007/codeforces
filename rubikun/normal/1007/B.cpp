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
const int mod=1000000007,MAX=100005,INF=1<<30;

vector<int> yaku[MAX];
int MA[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i) yaku[j].push_back(i);
    }
    
    int Q;cin>>Q;
    while(Q--){
        vector<int> A(3),cnt(8);
        for(int i=0;i<3;i++){
            cin>>A[i];
            for(int a:yaku[A[i]]){
                if(MA[a]) cnt[MA[a]]--;
                MA[a]|=(1<<i);
                cnt[MA[a]]++;
            }
        }
        
        int ans=0;
        
        for(int i=1;i<=7;i++){
            for(int j=i;j<=7;j++){
                for(int k=j;k<=7;k++){
                    if((i|j|k)<7) continue;
                    if((i==j||j==k)&&(__builtin_popcount(j)==1)) continue;
                    
                    if(i==j&&j==k){
                        ans+=cnt[j]*(cnt[j]+1)*(cnt[j]+2)/6;
                        continue;
                    }
                    
                    if(i==j){
                        ans+=cnt[j]*(cnt[j]+1)*cnt[k]/2;
                        continue;
                    }
                    
                    if(j==k){
                        ans+=cnt[j]*(cnt[j]+1)*cnt[i]/2;
                        continue;
                    }
                    
                    ans+=cnt[i]*cnt[j]*cnt[k];
                }
            }
        }
        
        cout<<ans<<"\n";
        
        for(int i=0;i<3;i++){
            for(int a:yaku[A[i]]){
                MA[a]=0;
            }
        }
    }
}