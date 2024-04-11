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
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        string S;cin>>S;
        int sum=0,cnt0=0,cnteven=0;
        
        for(int j=0;j<S.size();j++){
            sum+=int(S[j]-'0');
            if(int(S[j]-'0')==0){
                cnt0++;
            }
            if(int(S[j]-'0')%2==0){
                cnteven++;
            }
        }
        
        if(cnt0>=1&&cnteven>=2&&sum%3==0) cout<<"red"<<endl;
        else cout<<"cyan"<<endl;
    }
}