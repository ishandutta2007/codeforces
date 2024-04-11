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
    string S;cin>>S;
    vector<int> iin(10);
    
    for(int i=0;i<N;i++){
        if(S[i]=='L'){
            for(int j=0;j<10;j++){
                if(iin[j]==0){
                    iin[j]=1;
                    break;
                }
            }
        }else if(S[i]=='R'){
            for(int j=9;j>=0;j--){
                if(iin[j]==0){
                    iin[j]=1;
                    break;
                }
            }
        }else{
            iin[S[i]-'0']=0;
        }
    }
    
    for(int a:iin) cout<<a;
    cout<<endl;
    
}