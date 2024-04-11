#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int L,R;cin>>L>>R;
    int ans=-1;
    for(int i=L;i<=R;i++){
        vector<int> A(10,0);
        int k=i;
        while(k){
            A[k%10]++;
            k/=10;
        }
        sort(all(A));
        if(A[9]<=1) ans=i;
    }
    cout<<ans<<endl;
}