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
const int mod=998244353,MAX=105,INF=1<<30;

int N;
int A[MAX][MAX];

void paint1(){
    for(int h=0;h<N;h++){
        for(int w=0;w<N;w++){
            if((h+w)%2==0){
                if(A[h][w]==0){
                    A[h][w]=1;
                    cout<<1<<" "<<h+1<<" "<<w+1<<endl;
                    return;
                }
            }
        }
    }
    
    for(int h=0;h<N;h++){
        for(int w=0;w<N;w++){
            if(A[h][w]==0){
                A[h][w]=3;
                cout<<3<<" "<<h+1<<" "<<w+1<<endl;
                return;
            }
        }
    }
}

void paint2(){
    for(int h=0;h<N;h++){
        for(int w=0;w<N;w++){
            if((h+w)&1){
                if(A[h][w]==0){
                    A[h][w]=2;
                    cout<<2<<" "<<h+1<<" "<<w+1<<endl;
                    return;
                }
            }
        }
    }
    
    for(int h=0;h<N;h++){
        for(int w=0;w<N;w++){
            if(A[h][w]==0){
                A[h][w]=3;
                cout<<3<<" "<<h+1<<" "<<w+1<<endl;
                return;
            }
        }
    }
}

void paint3(){
    for(int h=0;h<N;h++){
        for(int w=0;w<N;w++){
            if((h+w)&1){
                if(A[h][w]==0){
                    A[h][w]=2;
                    cout<<2<<" "<<h+1<<" "<<w+1<<endl;
                    return;
                }
            }else{
                if(A[h][w]==0){
                    A[h][w]=1;
                    cout<<1<<" "<<h+1<<" "<<w+1<<endl;
                    return;
                }
            }
        }
    }
}

int main(){
    
    cin>>N;
    
    for(int i=0;i<N*N;i++){
        int a;cin>>a;
        if(a==1){
            paint2();
        }
        if(a==2){
            paint1();
        }
        if(a==3){
            paint3();
        }
    }
}