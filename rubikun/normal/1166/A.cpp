#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> cnt(26);
    for(int i=0;i<N;i++){
        string S;cin>>S;
        cnt[S[0]-'a']++;
    }
    
    int ans=0;
    
    for(int i=0;i<26;i++){
        int a=cnt[i]/2,b=cnt[i]-a;
        
        ans+=a*(a-1)/2+b*(b-1)/2;
    }
    
    cout<<ans<<endl;
}