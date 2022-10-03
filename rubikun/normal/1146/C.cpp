#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T){
        int N;cin>>N;
        int maxi=-1;
        cout<<"1 "<<N-1<<" 1";
        for(int i=2;i<=N;i++){
            cout<<" "<<i;
        }
        cout<<endl;
        fflush(stdout);
        cin>>maxi;
        int left=2,right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            cout<<"1 "<<(mid-left)<<" 1";
            for(int i=left;i<mid;i++){
                cout<<" "<<i;
            }
            cout<<endl;
            fflush(stdout);
            int a;cin>>a;
            if(a==maxi) right=mid;
            else left=mid;
        }
        
        cout<<1<<" "<<N-1<<" "<<left;
        for(int i=1;i<=N;i++){
            if(i==left) continue;
            cout<<" "<<i;
        }
        cout<<endl;
        fflush(stdout);
        cin>>maxi;
        
        cout<<-1<<" "<<maxi<<endl;
        fflush(stdout);
        
        T--;
    }
    
}