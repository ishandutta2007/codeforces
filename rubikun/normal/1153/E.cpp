#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    int N;cin>>N;
    vector<int> A(N+1),B(N+1);
    
    for(int i=1;i<=N-1;i++){
        cout<<"? 1 1 "<<i<<" "<<N<<endl;
        cin>>A[i];
    }
    
    for(int i=1;i<=N-1;i++){
        cout<<"? 1 1 "<<N<<" "<<i<<endl;
        cin>>B[i];
    }
    
    int a1=-1,a2=-1,b1=-1,b2=-1;
    
    for(int i=0;i<N;i++){
        if(A[i]%2!=A[i+1]%2){
            if(a1==-1) a1=i+1;
            else a2=i+1;
        }
        
        if(B[i]%2!=B[i+1]%2){
            if(b1==-1) b1=i+1;
            else b2=i+1;
        }
    }
    
    if(a2!=-1&&b2!=-1){
        cout<<"? "<<a1<<" "<<b1<<" "<<a1<<" "<<b1<<endl;
        int a;cin>>a;
        if(a%2==1){
            cout<<"! "<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
        }else{
            cout<<"! "<<a1<<" "<<b2<<" "<<a2<<" "<<b1<<endl;
        }
    }else{
        if(a2==-1){
            int left=0,right=N;
            while(right-left>1){
                int mid=(left+right)/2;
                cout<<"? "<<1<<" "<<b1<<" "<<mid<<" "<<b1<<endl;
                int a;cin>>a;
                if(a%2) right=mid;
                else left=mid;
            }
            cout<<"! "<<right<<" "<<b1<<" "<<right<<" "<<b2<<endl;
        }else{
            int left=0,right=N;
            while(right-left>1){
                int mid=(left+right)/2;
                cout<<"? "<<a1<<" "<<1<<" "<<a1<<" "<<mid<<endl;
                int a;cin>>a;
                if(a%2) right=mid;
                else left=mid;
            }
            cout<<"! "<<a1<<" "<<right<<" "<<a2<<" "<<right<<endl;
        }
    }
}