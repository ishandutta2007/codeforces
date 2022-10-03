#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=500003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int now=0,maxi=0;
    for(int i=0;i<N;i++){
        if(S[i]=='(') now++;
        else now--;
        maxi=max(maxi,now);
    }
    
    vector<int> ans(N);
    for(int i=0;i<N;i++){
        if(S[i]=='('){
            now++;
            if(now<=maxi/2) ans[i]=0;
            else ans[i]=1;
        }else{
            if(now<=maxi/2) ans[i]=0;
            else ans[i]=1;
            now--;
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<ans[i];
    }
    cout<<endl;
}