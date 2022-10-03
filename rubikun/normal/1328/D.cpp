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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        bool ok=true;
        for(int i=1;i<N;i++) if(A[i]!=A[0]) ok=false;
        
        if(ok){
            cout<<1<<"\n";
            for(int i=0;i<N;i++) cout<<1<<" ";
            cout<<"\n";
            continue;
        }
        
        ok=true;
        
        A.push_back(A[0]);
        A.push_back(A[1]);
        
        vector<int> color(N+2);
        color[0]=1;
        for(int i=1;i<N;i++){
            if(A[i-1]==A[i]) color[i]=color[i-1];
            else color[i]=3-color[i-1];
        }
        color[N]=color[0];
        color[N+1]=color[1];
        
        for(int i=1;i<=N;i++){
            if(A[i-1]!=A[i]&&color[i-1]==color[i]) ok=false;
            if(A[i]!=A[i+1]&&color[i]==color[i+1]) ok=false;
        }
        
        if(ok){
            cout<<2<<"\n";
            for(int i=0;i<N;i++) cout<<color[i]<<" ";
            cout<<"\n";
            continue;
        }
        
        ok=true;
        int cnt=0;
        
        color[0]=1;
        for(int i=1;i<N;i++){
            if(A[i-1]==A[i]){
                if(cnt==0){
                    color[i]=3-color[i-1];
                    cnt++;
                }else color[i]=color[i-1];
            }else color[i]=3-color[i-1];
        }
        color[N]=color[0];
        color[N+1]=color[1];
        
        for(int i=1;i<=N;i++){
            if(A[i-1]!=A[i]&&color[i-1]==color[i]) ok=false;
            if(A[i]!=A[i+1]&&color[i]==color[i+1]) ok=false;
        }
        
        if(ok){
            cout<<2<<"\n";
            for(int i=0;i<N;i++) cout<<color[i]<<" ";
            cout<<"\n";
            continue;
        }
        
        
        else{
            cout<<3<<"\n";
            if(N%3==0){
                for(int i=0;i<N;i++) cout<<(i%3)+1<<" ";
                cout<<"\n";
            }else if(N%3==1){
                for(int i=0;i<N-1;i++) cout<<(i%3)+1<<" ";
                cout<<2<<" ";
                cout<<"\n";
            }else{
                for(int i=0;i<N;i++) cout<<(i%3)+1<<" ";
                cout<<"\n";
            }
        }
        
    }
}