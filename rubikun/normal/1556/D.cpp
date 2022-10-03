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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<55;

vector<int> X={1,6,4,2,3,5,4};

int orq(int a,int b){
    cout<<"or "<<a+1<<" "<<b+1<<endl;
    //return X[a]|X[b];
    int x;cin>>x;
    return x;
}

int andq(int a,int b){
    cout<<"and "<<a+1<<" "<<b+1<<endl;
    //return X[a]&X[b];
    int x;cin>>x;
    return x;
}

int main(){
    
    int N,K;cin>>N>>K;
    K--;
    vector<int> A(N),B(N);
    for(int i=1;i<N;i++){
        int x=orq(0,i);
        A[i]=x;
        int y=andq(0,i);
        B[i]=y;
    }
    
    int z=orq(1,2);
    
    int S=0;
    
    vector<int> C(N);
    for(int i=1;i<N;i++){
        for(int j=30;j>=0;j--){
            int a=(A[i]&(1<<j)),b=(B[i]&(1<<j)),c=z&(1<<j);
            if(a==b){
                S|=(1<<j);
            }
            if(a&&b){
                C[0]|=(1<<j);
                C[i]|=(1<<j);
            }
        }
    }
    
    for(int i=1;i<N;i++){
        for(int j=30;j>=0;j--){
            int a=(A[i]&(1<<j)),b=(B[i]&(1<<j)),c=z&(1<<j);
            if(S&(1<<j)){
                if(a!=b){
                    if(!(C[0]&(1<<j))) C[i]|=(1<<j);
                }
            }else{
                if(c){
                    C[i]|=(1<<j);
                }else{
                    C[0]|=(1<<j);
                }
            }
        }
    }
    
    //for(int i=0;i<N;i++) cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<endl;
    //cout<<endl;
    
    sort(all(C));
    cout<<"finish "<<C[K]<<endl;
}