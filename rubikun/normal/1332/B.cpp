#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200001,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    vector<int> A={2,3,5,7,11,13,17,19,23,29,31};
    while(Q--){
        int N;cin>>N;
        vector<int> B(N),ans(N),to(11);
        set<int> SE;
        for(int i=0;i<N;i++){
            cin>>B[i];
            for(int j=0;j<11;j++){
                if(B[i]%A[j]==0){
                    ans[i]=j;
                    SE.insert(j);
                    break;
                }
            }
        }
        int id=0;
        for(auto a:SE){
            to[a]=id;
            id++;
        }
        cout<<id<<"\n";
        
        for(int i=0;i<N;i++){
            ans[i]=to[ans[i]];
            cout<<ans[i]+1<<" ";
        }
        cout<<"\n";
        
    }
}