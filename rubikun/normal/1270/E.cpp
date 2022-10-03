#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int par[MAX],size[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        size[i]=1;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)){
        size[root(a)]+=size[root(b)];
        par[root(b)]=root(a);
    }
}

bool check(int a,int b){
    return root(a)==root(b);
}

int color[MAX];

struct edge{
    int idl;
    int idr;
    ll dis;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    vector<ll> X(N),Y(N);
    
    for(int i=0;i<N;i++){
        cin>>X[i]>>Y[i];
    }
    
    init(N);
    
    for(int i=0;i<N;i++){
        vector<pair<ll,int>> S;
        
        for(int j=0;j<N;j++){
            if(i==j) continue;
            ll dis=(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
            S.push_back({dis,j});
        }
        
        sort(all(S));
        
        for(int j=1;j<S.size();j++){
            if(S[j-1].first==S[j].first) unite(S[j-1].second,S[j].second);
        }
    }
    
    vector<edge> S;
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            S.push_back({i,j,(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j])});
        }
    }
    
    sort(all(S),[](edge a,edge b){
        return a.dis<b.dis;
    });
    
    for(int i=1;i<S.size();i++){
        S[i-1].idl=root(S[i-1].idl);
        S[i-1].idr=root(S[i-1].idr);
        S[i].idl=root(S[i].idl);
        S[i].idr=root(S[i].idr);
        
        if(S[i-1].dis!=S[i].dis) continue;
        
        if(check(S[i-1].idl,S[i].idl)) continue;
        if(check(S[i-1].idl,S[i].idr)) continue;
        if(check(S[i-1].idr,S[i].idl)) continue;
        if(check(S[i-1].idr,S[i].idr)) continue;
              
        
        if(color[S[i-1].idl]==0&&color[S[i-1].idr]==0){
            if(color[S[i].idl]==0&&color[S[i].idr]==0){
                color[S[i-1].idl]=color[S[i-1].idr]=1;
                color[S[i].idl]=color[S[i].idr]=2;
            }else{
                if(color[S[i].idl]==0){
                    color[S[i].idl]=color[S[i].idr];
                    color[S[i-1].idl]=color[S[i-1].idr]=3-color[S[i].idr];
                }else{
                    if(color[S[i].idl]==color[S[i].idr]){
                        color[S[i-1].idl]=color[S[i-1].idr]=3-color[S[i].idr];
                    }else if(color[S[i].idr]==0){
                        color[S[i].idr]=color[S[i].idl];
                        color[S[i-1].idl]=color[S[i-1].idr]=3-color[S[i].idr];
                    }else{
                        color[S[i-1].idl]=color[S[i].idl];
                        color[S[i-1].idr]=color[S[i].idr];
                    }
                }
            }
        }else if(color[S[i-1].idl]==0){
            if(color[S[i].idl]==0&&color[S[i].idr]==0){
                color[S[i-1].idl]=color[S[i-1].idr];
                color[S[i].idl]=color[S[i].idr]=3-color[S[i-1].idr];
            }else{
                if(color[S[i].idl]==0){
                    if(color[S[i-1].idr]==color[S[i].idr]){
                        color[S[i-1].idl]=3-color[S[i-1].idr];
                        color[S[i].idl]=3-color[S[i].idr];
                    }else{
                        color[S[i-1].idl]=color[S[i-1].idr];
                        color[S[i].idl]=color[S[i].idr];
                    }
                }else{
                    if(color[S[i].idl]==color[S[i].idr]){
                        color[S[i-1].idl]=color[S[i-1].idr];
                    }else if(color[S[i].idr]==0){
                        if(color[S[i-1].idr]==color[S[i].idl]){
                            color[S[i-1].idl]=color[S[i].idr]=3-color[S[i].idl];
                        }else{
                            color[S[i-1].idl]=color[S[i-1].idr];
                            color[S[i].idr]=color[S[i].idl];
                        }
                    }else{
                        color[S[i-1].idl]=3-color[S[i-1].idr];
                    }
                }
            }
        }else if(color[S[i-1].idr]==color[S[i-1].idl]){
            if(color[S[i].idl]==0&&color[S[i].idr]==0){
                color[S[i].idl]=color[S[i].idr]=3-color[S[i-1].idr];
            }else{
                if(color[S[i].idl]==0){
                    color[S[i].idl]=color[S[i].idr];
                }else{
                    color[S[i].idr]=color[S[i].idl];
                }
            }
        }else if(color[S[i-1].idr]==0){
            swap(S[i-1].idl,S[i-1].idr);
            if(color[S[i].idl]==0&&color[S[i].idr]==0){
                color[S[i-1].idl]=color[S[i-1].idr];
                color[S[i].idl]=color[S[i].idr]=3-color[S[i-1].idr];
            }else{
                if(color[S[i].idl]==0){
                    if(color[S[i-1].idr]==color[S[i].idr]){
                        color[S[i-1].idl]=3-color[S[i-1].idr];
                        color[S[i].idl]=3-color[S[i].idr];
                    }else{
                        color[S[i-1].idl]=color[S[i-1].idr];
                        color[S[i].idl]=color[S[i].idr];
                    }
                }else{
                    if(color[S[i].idl]==color[S[i].idr]){
                        color[S[i-1].idl]=color[S[i-1].idr];
                    }else if(color[S[i].idr]==0){
                        if(color[S[i-1].idr]==color[S[i].idl]){
                            color[S[i-1].idl]=color[S[i].idr]=3-color[S[i].idl];
                        }else{
                            color[S[i-1].idl]=color[S[i-1].idr];
                            color[S[i].idr]=color[S[i].idl];
                        }
                    }else{
                        color[S[i-1].idl]=3-color[S[i-1].idr];
                    }
                }
            }
        }else{
            if(color[S[i].idl]==0&&color[S[i].idr]==0){
                color[S[i].idl]=1;
                color[S[i].idr]=2;
            }else{
                if(color[S[i].idl]==0){
                    color[S[i].idl]=3-color[S[i].idr];
                }else{
                    color[S[i].idr]=3-color[S[i].idl];
                }
            }
        }
    }
    
    int cnt1=0,cnt2=0;
    
    for(int i=0;i<N;i++){
        if(color[root(i)]==1) cnt1++;
        else if(color[root(i)]==2) cnt2++;
    }
    
    //cout<<cnt1<<" "<<cnt2<<endl;
    
    for(int i=0;i<N;i++){
        if(color[root(i)]==0){
            if(cnt1==0){
                color[root(i)]=1;
                cnt1++;
            }else{
                color[root(i)]=2;
            }
        }
    }
    
    vector<int> a,b;
    
    for(int i=0;i<N;i++){
        if(color[root(i)]==1) a.push_back(i+1);
        //else b.push_back(i+1);
    }
    
    cout<<a.size()<<endl;
    for(int i:a) cout<<i<<" ";
    cout<<endl;
    
    /*cout<<b.size()<<endl;
    for(int i:b) cout<<i<<" ";
    cout<<endl;*/
}