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
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        vector<int> now(N);
        
        cout<<1<<"\n";
        now[0]=1;
        
        int t=0;
        for(int i=1;i<N;i++){
            bool ok=false;
            for(int j=t;j>=0;j--){
                if(now[j]+1==A[i]){
                    for(int k=0;k<j;k++){
                        if(k) cout<<'.';
                        cout<<now[k];
                    }
                    if(j) cout<<'.';
                    now[j]++;
                    cout<<now[j]<<"\n";
                    for(int k=j+1;k<=t;k++) now[k]=0;
                    t=j;
                    ok=true;
                    break;
                }
            }
            if(ok) continue;
            
            assert(A[i]==1);
            for(int j=0;j<=t;j++){
                if(j) cout<<'.';
                cout<<now[j];
            }
            cout<<'.'<<1<<"\n";
            t++;
            now[t]=1;
            
            //for(int j=0;j<=t;j++) cout<<t<<"   "<<now[j]<<" ";
            //cout<<endl;
        }
    }
}