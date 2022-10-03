#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N;cin>>N;
        string S;cin>>S;
        if(N==2&&S[0]>=S[1]) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<2<<endl;
            for(int i=0;i<N;i++){
                if(i==1) cout<<" ";
                cout<<S[i];
            }
            cout<<endl;
        }
    }
}