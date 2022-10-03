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
    for(int i=0;i<N;i++){
        //cin>>A[i];
        scanf("%d",&A[i]);
    }
    
    bool ok=true;
    vector<int> S;
    
    int i=0;
    
    while(i<N){
        set<int> used,now;
        int cnt=0;
        while(i<N){
            if(A[i]>0){
                if(used.size()>=1&&*used.lower_bound(A[i])==A[i]) ok=false;
                if(now.size()>=1&&*now.lower_bound(A[i])==A[i]) ok=false;
                now.insert(A[i]);
            }else{
                if(now.size()>=1&&*now.lower_bound(-A[i])==(-A[i])){
                    now.erase(-A[i]);
                    used.insert(-A[i]);
                }else ok=false;
            }
            i++;
            cnt++;
            if(now.size()==0) break;
        }
        if(now.size()>=1) ok=false;
        S.push_back(cnt);
    }
    
    if(!ok){
        cout<<-1<<endl;
        return 0;
    }
    
    cout<<S.size()<<endl;
    for(int i=0;i<S.size();i++){
        if(i) cout<<" ";
        cout<<S[i];
    }
    
    cout<<endl;
    
}