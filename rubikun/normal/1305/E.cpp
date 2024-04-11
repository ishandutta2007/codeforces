#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1000000000;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> ans(N+1);
    int can=0;
    for(int i=1;i<=N;i++){
        ans[i]=i;
        can+=(i-1)/2;
    }
    if(can<M){
        cout<<-1<<endl;
        return 0;
    }else{
        int id=N;
        while(id>=1&&M<can){
            if(can-M>(id-1)/2){
                ans[id]=INF-(N-id)*100000;
                can-=(id-1)/2;
            }else if(can-M==(id-1)/2){
                ans[id]=INF-(N-id)*100000;
                can-=(id-1)/2;
                break;
            }else{
                ans[id]+=2*(can-M);
                break;
            }
            
            id--;
        }
        
        for(int i=1;i<=N;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}