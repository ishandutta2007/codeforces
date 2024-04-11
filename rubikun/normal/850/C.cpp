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
const int mod=1000000007,MAX=1000005,INF=1<<30;

map<vector<int>,int> MA;

int DFS(vector<int> x){
    if(MA.count(x)) return MA[x];
    
    int a=0;
    for(int i=0;i<si(x);i++) a+=x[i];
    if(a==0) return MA[x]=0;
    
    vector<int> deta(100);
    
    for(int i=1;i<35;i++){
        vector<int> to(35);
        
        bool ok=false;
        
        for(int j=i;j<35;j++){
            if(x[j]) ok=true;
        }
        if(!ok) break;
        
        for(int j=0;j<35;j++){
            if(j<i&&x[j]) to[j]=1;
            if(j+i<35&&x[j+i]) to[j]=1;
        }
        
        int a=DFS(to);
        deta[a]=1;
    }
    
    for(int i=0;i<100;i++){
        if(deta[i]==0){
            return MA[x]=i;
        }
    }
    
    return MA[x]=0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    
    set<int> SE;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        A[i]=a;
        
        for(int j=2;j*j<=a;j++){
            while(a%j==0){
                SE.insert(j);
                a/=j;
            }
        }
        if(a!=1) SE.insert(a);
    }
    
    int x=0;
    
    for(int a:SE){
        vector<int> check(35);
        for(int i=0;i<N;i++){
            int cnt=0;
            while(A[i]%a==0){
                cnt++;
                A[i]/=a;
            }
            check[cnt]=1;
        }
        x^=DFS(check);
    }
    
    if(!x) cout<<"Arpa"<<endl;
    else cout<<"Mojtaba"<<endl;
}