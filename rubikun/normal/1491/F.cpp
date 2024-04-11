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
        vector<int> X,ans;
        int mag=-1;
        for(int i=2;i<=N;i++){
            cout<<"? 1 "<<i-1<<endl;
            cout<<i<<endl;
            for(int j=1;j<i;j++) cout<<j<<" ";
            cout<<endl;
            
            int x;cin>>x;
            if(x){
                mag=i;
                break;
            }
        }
        
        for(int i=mag+1;i<=N;i++){
            cout<<"? 1 1"<<endl;
            cout<<mag<<endl;
            cout<<i<<endl;
            
            int x;cin>>x;
            if(x==0) ans.push_back(i);
        }
        
        int left=1,right=mag;
        while(right-left>1){
            int mid=(left+right)/2;
            cout<<"? 1 "<<mid-left<<endl;
            cout<<mag<<endl;
            for(int i=left;i<mid;i++) cout<<i<<" ";
            cout<<endl;
            
            int x;cin>>x;
            if(x) right=mid;
            else left=mid;
        }
        
        for(int i=1;i<mag;i++) if(i!=left) ans.push_back(i);
        
        sort(all(ans));
        
        cout<<"! "<<si(ans)<<" ";
        for(int a:ans) cout<<a<<" ";
        cout<<endl;
    }
}