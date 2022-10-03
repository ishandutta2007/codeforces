#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S,T;cin>>S>>T;
    int N=T.size();
    vector<int> left(N),right(N);
    int now=0;
    for(int i=0;i<N;i++){
        while(S[now]!=T[i]) now++;
        left[i]=now;
        now++;
    }
    now=S.size()-1;
    for(int i=N-1;i>=0;i--){
        while(S[now]!=T[i]) now--;
        right[i]=now;
        now--;
    }
    
    int ans=0;
    
    for(int i=0;i<N-1;i++){
        ans=max(ans,right[i+1]-left[i]-1);
    }
    
    ans=max({ans,right[0],int(S.size()-1-left[N-1])});
    cout<<ans<<endl;
}