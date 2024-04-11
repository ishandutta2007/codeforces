#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> when[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]=N-A[i];
    }
    int now=1;
    
    for(int i=0;i<N;i++){
        when[A[i]].push_back(i);
        if(when[A[i]].size()==A[i]){
            for(int j:when[A[i]]) B[j]=now;
            now++;
            when[A[i]].clear();
        }
    }
    
    for(int i=0;i<=N;i++) if(when[i].size()>=1) now=-1;
    
    if(now==-1) cout<<"Impossible"<<endl;
    else{
        cout<<"Possible"<<endl;
        for(int i:B) cout<<i<<" ";
        cout<<endl;
    }
    
}