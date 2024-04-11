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
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

const int D=153;

using bs=bitset<D>;
using mat=array<bs,D>;
int N;

mat mul(mat A,mat B) {
    mat C;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i][j]) C[i]|=B[j];
        }
    }
    return C;
}

mat pow(mat A,ll n){
    mat B;
    for(int i=0;i<N;i++){
        B[i][i]=1;
    }
    
    while(n>0){
        if(n&1) B=mul(A,B);
        A=mul(A,A);
        n/=2;
    }
    return B;
}

struct edge{
    int a;
    int b;
    int c;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M;cin>>N>>M;
    vector<edge> E(M);
    for(int i=0;i<M;i++){
        cin>>E[i].a>>E[i].b>>E[i].c;
        E[i].a--;E[i].b--;
    }
    E.push_back({N-1,N-1,0});
    E.push_back({N-1,N-1,1000000400});
    E.push_back({N-1,N-1,1000000800});
    sort(all(E),[](auto a,auto b){
        return a.c<b.c;
    });
    
    mat now;
    now[0][0]=true;
    
    mat X;
    
    int i=0;
    while(i<si(E)){
        int j=i;
        while(j<si(E)&&E[i].c==E[j].c){
            j++;
        }
        if(j==si(E)){
            cout<<"Impossible\n";
            return 0;
        }
        for(int k=i;k<j;k++){
            X[E[k].b][E[k].a]=true;
        }
        mat Y=X;
        Y=pow(Y,E[j].c-E[i].c);
        mat Z=mul(Y,now);
        if(Z[N-1][0]){
            int left=0,right=E[j].c-E[i].c;
            while(right-left>1){
                int mid=(left+right)/2;
                Y=pow(X,mid);
                Z=mul(Y,now);
                if(Z[N-1][0]) right=mid;
                else left=mid;
            }
            cout<<right+E[i].c<<"\n";
            return 0;
        }else{
            now=Z;
            i=j;
        }
        
        /*
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<now[i][j];
            }
            cout<<endl;
        }
         */
    }
}