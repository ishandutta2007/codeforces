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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;
vector<int> G[MAX];

int ask(vector<int> A){
    if(si(A)==1) return 0;
    cout<<"? "<<si(A)<<endl;
    for(int a:A) cout<<a+1<<" ";
    cout<<endl;
    
    int res;cin>>res;
    return res;
}

vector<int> bubun(vector<int> &A,int l,int r){
    vector<int> res;
    for(int i=l;i<r;i++) res.push_back(A[i]);
    return res;
}

pair<int,int> make(vector<int> A,vector<int> B){
    int left=0,right=si(A);
    int a,b,c;
    b=ask(B);
    while(right-left>1){
        int mid=(left+right)/2;
        vector<int> X=bubun(A,left,mid);
        a=ask(X);
        for(int a:B) X.push_back(a);
        c=ask(X);
        
        if(a+b==c) left=mid;
        else right=mid;
    }
    
    A={A[left]};
    
    a=ask(A);
    
    left=0;right=si(B);
    
    while(right-left>1){
        int mid=(left+right)/2;
        vector<int> X=bubun(B,left,mid);
        b=ask(X);
        for(int a:A) X.push_back(a);
        c=ask(X);
        
        if(a+b==c) left=mid;
        else right=mid;
    }
    
    B={B[left]};
    
    G[A[0]].push_back(B[0]);
    G[B[0]].push_back(A[0]);
    
    return mp(A[0],B[0]);
}

int color[MAX];

void DFS(int u){
    for(int to:G[u]){
        if(color[to]==0){
            color[to]=3-color[u];
            DFS(to);
        }
    }
}

pair<int,int> solve(vector<int> A,vector<int> B){
    while(1){
        int a=ask(A);
        if(a){
            B=bubun(A,si(A)/2,si(A));
            A=bubun(A,0,si(A)/2);
            continue;
        }
        int b=ask(B);
        if(b){
            A=bubun(B,0,si(B)/2);
            B=bubun(B,si(B)/2,si(B));
            continue;
        }
        break;
    }
    
    return make(A,B);
}

vector<int> trail;
bool ok=false;
int s,g;

void DFS2(int u,int p){
    if(u==g){
        trail.push_back(u);
        ok=true;
        return;
    }
    for(int to:G[u]){
        if(to==p) continue;
        DFS2(to,u);
        if(ok){
            trail.push_back(u);
            return;
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    if(N==1){
        cout<<"Y 0"<<endl;
        return 0;
    }
    
    vector<int> A(1),B(N-1);
    iota(all(B),1);
    
    for(int t=0;t<N-1;t++){
        int x=make(A,B).se;
        B.erase(lower_bound(all(B),x));
        A.push_back(x);
    }
    
    color[0]=1;
    DFS(0);
    
    vector<int> C,D;
    for(int i=0;i<N;i++){
        if(color[i]==1) C.push_back(i);
        else D.push_back(i);
    }
    
    int x=ask(C);
    int y=ask(D);
    
    if(x==0&&y==0){
        cout<<"Y "<<si(C)<<endl;
        for(int a:C) cout<<a+1<<" ";
        cout<<endl;
    }else{
        if(y){
            swap(x,y);
            swap(C,D);
        }
        
        A=bubun(C,0,si(C)/2);
        B=bubun(C,si(C)/2,si(C));
        
        auto z=solve(A,B);
        
        G[z.fi].pop_back();
        G[z.se].pop_back();
        
        s=z.fi;
        g=z.se;
        
        DFS2(z.fi,-1);
        
        cout<<"N "<<si(trail)<<endl;
        
        for(int a:trail) cout<<a+1<<" ";
        cout<<endl;
    }
}