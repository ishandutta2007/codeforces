#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    if(N%2){
        cout<<"YES"<<endl;
        vector<int> ans(2*N);
        int cnt=1,now=0;
        
        while(cnt<=2*N){
            ans[now]=cnt;
            now+=N;
            now%=2*N;
            cnt++;
            
            ans[now]=cnt;
            now++;
            now%=2*N;
            cnt++;
        }
        
        for(int a:ans) cout<<a<<" ";
        cout<<endl;
    }else cout<<"NO"<<endl;
}