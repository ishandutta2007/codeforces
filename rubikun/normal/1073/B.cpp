#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    
    set<int> S;
    int j=0;
    
    for(int i=0;i<N;i++){
        int cnt=0;
        while(S.find(B[i])==S.end()){
            S.insert(A[j]);
            j++;
            cnt++;
        }
        if(i) printf(" ");
        printf("%d",cnt);
    }
    printf("\n");
    
}