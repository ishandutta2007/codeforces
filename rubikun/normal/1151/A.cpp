#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int f(char a,char b){
    if(a>b) swap(a,b);
    
    return min(b-a,26+a-b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    string T="ACTG";
    
    int ans=INF;
    
    for(int i=0;i+3<N;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum+=f(S[i+j],T[j]);
        }
        ans=min(ans,sum);
    }
    
    cout<<ans<<endl;
}