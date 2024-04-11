#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    int cnt=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(abs(A[i])%2==1) cnt++;
    }
    cnt/=2;
    
    for(int i=0;i<N;i++){
        if(abs(A[i])%2==1){
            if(cnt>=1){
                if(A[i]>=0){
                    cout<<A[i]/2+1<<endl;
                    cnt--;
                }else{
                    cout<<abs(A[i])/2*(-1)<<endl;
                    cnt--;
                }
            }else{
                if(A[i]>=0){
                    cout<<A[i]/2<<endl;
                }else{
                    cout<<abs(A[i]-1)/2*(-1)<<endl;
                }
            }
        }else cout<<A[i]/2<<endl;
    }
}