#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

vector<int> when[MAX];

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,Q;cin>>N>>Q;
    vector<int> A(N),used(MAX,0);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        //cin>>A[i];
        A[i]--;
        when[A[i]].push_back(i);
    }
    
    int ans=0;
    
    int now=-1,end=-1;
    
    for(int i=0;i<N;i++){
        if(A[i]==now){
            if(end==i) now=-1;
        }else if(now==-1){
            if(!used[A[i]]){
                now=A[i];
                end=when[now][when[now].size()-1];
            }
        }else if(!used[A[i]]){
            if(when[now].size()>=when[A[i]].size()){
                ans+=when[A[i]].size();
                used[A[i]]=1;
                end=max(end,when[A[i]][when[A[i]].size()-1]);
            }else{
                ans+=when[now].size();
                used[now]=1;
                end=max(end,when[A[i]][when[A[i]].size()-1]);
                now=A[i];
            }
        }
        
        if(end==i) now=-1;
    }
    
    cout<<ans<<endl;
}