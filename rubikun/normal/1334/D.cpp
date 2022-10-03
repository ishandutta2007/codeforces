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
    
    int Q;cin>>Q;
    while(Q--){
        ll N,L,R;cin>>N>>L>>R;
        ll sum=0;
        L--;
        vector<int> ans;
        for(ll i=1;i<=N;i++){
            if(sum+2*(N-i)<=L) sum+=2*(N-i);
            else{
                int a=i,b=i+1;
                sum++;
                if(sum>L&&sum<=R) ans.push_back(a);
                
                sum++;
                if(sum>L&&sum<=R) ans.push_back(b);
                
                sum++;
                
                while(sum<=R&&sum<N*(N-1)+1){
                    if(sum&1){
                        if(b==N){
                            a++;
                            b=a+1;
                        }else b++;
                        if(sum>L) ans.push_back(a);
                    }else{
                        if(sum>L) ans.push_back(b);
                    }
                    
                    sum++;
                }
                
                break;
            }
        }
        
        if(R==N*(N-1)+1) ans.push_back(1);
        
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
    }
}