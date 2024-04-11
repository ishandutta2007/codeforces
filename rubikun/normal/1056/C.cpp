#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=20005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> A(2*N),B(2*N,-1),id(2*N),used(2*N);
    for(int i=0;i<2*N;i++){
        cin>>A[i];
    }
    
    iota(all(id),0);
    
    sort(all(id),[&](auto a,auto b){
        return A[a]>A[b];
    });
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        B[a]=b;
        B[b]=a;
    }
    
    int t;cin>>t;
    
    if(t==1){
        for(int t=0;t<N;t++){
            bool ok=false;
            for(int i=0;i<2*N;i++){
                if(B[id[i]]!=-1&&!used[id[i]]){
                    cout<<id[i]+1<<endl;
                    used[id[i]]=1;
                    int x;cin>>x;x--;
                    used[x]=1;
                    
                    ok=true;
                    break;
                }
            }
            if(ok) continue;
            
            for(int i=0;i<2*N;i++){
                if(!used[id[i]]){
                    cout<<id[i]+1<<endl;
                    used[id[i]]=1;
                    int x;cin>>x;x--;
                    used[x]=1;
                    
                    break;
                }
            }
        }
    }else{
        int rem=N;
        
        while(1){
            int x;cin>>x;x--;
            used[x]=1;
            if(B[x]==-1){
                for(int t=0;t<rem-1;t++){
                    bool ok=false;
                    for(int i=0;i<2*N;i++){
                        if(B[id[i]]!=-1&&!used[id[i]]){
                            cout<<id[i]+1<<endl;
                            used[id[i]]=1;
                            int x;cin>>x;x--;
                            used[x]=1;
                            
                            ok=true;
                            break;
                        }
                    }
                    if(ok) continue;
                    
                    for(int i=0;i<2*N;i++){
                        if(!used[id[i]]){
                            cout<<id[i]+1<<endl;
                            used[id[i]]=1;
                            int x;cin>>x;x--;
                            used[x]=1;
                            
                            break;
                        }
                    }
                }
                for(int i=0;i<2*N;i++){
                    if(!used[id[i]]){
                        cout<<id[i]+1<<endl;
                        
                        return 0;
                    }
                }
            }else{
                cout<<B[x]+1<<endl;
                used[B[x]]=1;
                rem--;
            }
            
            if(rem==0) break;
        }
    }
}