#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> cnt(N);
        int k=0;
        for(int i=0;i<N;i++){
            int a;cin>>a;
            a--;
            cnt[a]++;
            if(cnt[a]==1) k++;
        }
        sort(all(cnt));
        
        int a=min(k-1,cnt[N-1]);
        int b=min(k,cnt[N-1]-1);
        cout<<max(a,b)<<"\n";
    }
}