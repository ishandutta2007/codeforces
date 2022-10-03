#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300003,INF=1<<30;

vector<int> when[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> C(N);
    for(int i=0;i<N;i++){
        int a;cin>>a;
        C[i]=a;
        when[a].push_back(i);
    }
    
    int ans=0;
    
    for(int i=0;i<N;i++){
        if(when[C[i]][0]!=i) continue;
        int maxi=N-1;
        while(maxi>=0&&C[maxi]==C[i]) maxi--;
        
        ans=max(ans,maxi-i);
    }
    
    cout<<ans<<endl;
}