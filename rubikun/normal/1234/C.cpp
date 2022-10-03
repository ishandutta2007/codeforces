#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        int N;cin>>N;
        vector<string> A(2);
        cin>>A[0]>>A[1];
        int now=0;
        bool ok=true;
        for(int i=0;i<N;i++){
            if(now==0){
                if(A[0][i]=='1'||A[0][i]=='2') continue;
                if(A[1][i]=='1'||A[1][i]=='2') ok=false;
                else now=1;
            }else{
                if(A[1][i]=='1'||A[1][i]=='2') continue;
                if(A[0][i]=='1'||A[0][i]=='2') ok=false;
                else now=0;
            }
        }
        if(now==1&&ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        Q--;
    }
}