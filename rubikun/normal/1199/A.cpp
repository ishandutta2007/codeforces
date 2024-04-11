#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());

    int N,X,Y;cin>>N>>X>>Y;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    for(int i=0;i<N;i++){
        bool ok=true;
        for(int j=i-X;j<=i+Y;j++){
            if(i==j) continue;
            if(j<0) continue;
            if(j>=N) continue;
            if(A[i]>A[j]) ok=false;
        }
        if(ok){
            cout<<i+1<<endl;
            break;
        }
    }
}