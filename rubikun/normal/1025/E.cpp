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
const int mod=1000000007,MAX=705,INF=1<<30;

struct mov{
    int sx;
    int sy;
    int gx;
    int gy;
};

int N,M;

void query(int sx,int sy,int gx,int gy,vector<mov> &A){
    A.push_back({sx,sy,gx,gy});
}

vector<mov> solve(vector<pair<int,int>> &A){
    vector<mov> res;
    
    vector<pair<int,int>> X(M);
    for(int i=0;i<M;i++){
        X[i]=mp(A[i].fi,i);
    }
    sort(all(X));
    
    for(int i=0;i<M;i++){
        if(i<X[i].fi){
            for(int j=X[i].fi;j-1>=i;j--){
                query(j,A[X[i].se].se,j-1,A[X[i].se].se,res);
            }
        }
    }
    
    for(int i=M-1;i>=0;i--){
        if(i>X[i].fi){
            for(int j=X[i].fi;j+1<=i;j++){
                query(j,A[X[i].se].se,j+1,A[X[i].se].se,res);
            }
        }
    }
    
    for(int i=0;i<M;i++) X[i].fi=i;
    sort(all(X),[](auto a,auto b){
        return a.se<b.se;
    });
    
    for(int i=0;i<M;i++){
        if(i<A[i].se){
            for(int j=A[i].se;j-1>=i;j--){
                query(X[i].fi,j,X[i].fi,j-1,res);
            }
        }else if(i>A[i].se){
            for(int j=A[i].se;j+1<=i;j++){
                query(X[i].fi,j,X[i].fi,j+1,res);
            }
        }
    }
    
    for(int i=0;i<M;i++){
        if(i<X[i].fi){
            for(int j=X[i].fi;j-1>=i;j--){
                query(j,i,j-1,i,res);
            }
        }else if(i>X[i].fi){
            for(int j=X[i].fi;j+1<=i;j++){
                query(j,i,j+1,i,res);
            }
        }
    }
    
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    vector<pair<int,int>> A(M),B(M);
    for(int i=0;i<M;i++){
        cin>>A[i].fi>>A[i].se;
        A[i].fi--;A[i].se--;
    }
    for(int i=0;i<M;i++){
        cin>>B[i].fi>>B[i].se;
        B[i].fi--;B[i].se--;
    }
    
    auto a=solve(A);
    auto b=solve(B);
    reverse(all(b));
    for(int i=0;i<si(b);i++){
        swap(b[i].sx,b[i].gx);
        swap(b[i].sy,b[i].gy);
    }
    
    cout<<si(a)+si(b)<<endl;
    for(auto x:a){
        cout<<x.sx+1<<" "<<x.sy+1<<" "<<x.gx+1<<" "<<x.gy+1<<endl;
    }
    //cout<<endl;
    for(auto x:b){
        cout<<x.sx+1<<" "<<x.sy+1<<" "<<x.gx+1<<" "<<x.gy+1<<endl;
    }
}