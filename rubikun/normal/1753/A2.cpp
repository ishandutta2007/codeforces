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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum+=abs(A[i]);
        }
        if(sum&1){
            cout<<-1<<"\n";
            continue;
        }
        vector<pair<int,int>> ans;
        int i=0;
        while(i<N){
            if(A[i]==0){
                ans.push_back(mp(i,i));
                i++;
                continue;
            }
            int j=i+1;
            while(j<N&&A[j]==0) j++;
            if((j-i)&1){
                if(A[i]-A[j]==0){
                    ans.push_back(mp(i,j));
                }else{
                    ans.push_back(mp(i,i));
                    ans.push_back(mp(i+1,j));
                }
            }else{
                if(A[i]+A[j]==0){
                    ans.push_back(mp(i,j));
                }else{
                    ans.push_back(mp(i,i));
                    ans.push_back(mp(i+1,j));
                }
            }
            
            i=j+1;
        }
        
        cout<<si(ans)<<"\n";
        for(auto a:ans) cout<<a.fi+1<<" "<<a.se+1<<"\n";
    }
}