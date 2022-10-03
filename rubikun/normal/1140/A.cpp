#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000003,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]--;
    }
    int cnt=0;
    set<int> S;
    for(int i=0;i<N;i++){
        S.insert(A[i]);
        S.erase(i);
        if(S.empty()) cnt++;
    }
    cout<<cnt<<endl;
}