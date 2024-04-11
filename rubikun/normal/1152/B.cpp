#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int x;cin>>x;
    int now=x;
    vector<int> A={0,1};
    while(A[A.size()-1]<10000000){
        A.push_back(A[A.size()-1]*2+1);
    }
    
    int cnt=0;
    vector<int> ans;
    
    while(1){
        bool ok=false;
        for(int i=0;i<A.size();i++) if(A[i]==now) ok=true;
        if(ok) break;
        
        if(cnt%2==0){
            for(int i=A.size()-1;i>=0;i--){
                if(now>A[i]&&!(now&(1<<i-1))){
                    now^=A[i];
                    ans.push_back(i);
                    break;
                }
            }
        }else{
            now++;
        }
        cnt++;
    }
    
    cout<<cnt<<endl;
    for(int a:ans) cout<<a<<" ";
    cout<<endl;
}