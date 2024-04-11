#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;
vector<int> S(MAX);

void solve(int A,int B,int left,int right,vector<int> used){
    
    if(left+2==right){
        S[left]=A;
        S[left+1]=B;
        return;
    }
    
    for(int i=0;i<18;i++){
        if((A&(1<<i))!=(B&(1<<i))){
            bool ok=true;
            for(int k=0;k<used.size();k++){
                if(i==used[k]) ok=false;
            }
            if(!ok) continue;
            
            int T=A-(A&(1<<i));
            int j;
            for(j=0;j<18;j++){
                if(i!=j){
                    bool ok=true;
                    for(int k=0;k<used.size();k++){
                        if(j==used[k]) ok=false;
                    }
                    if(ok) break;
                }
            }
            
            used.push_back(i);
            
            solve(A,(T^(1<<j))+(A&(1<<i)),left,(left+right)/2,used);
            solve((T^(1<<j))+(B&(1<<i)),B,(left+right)/2,right,used);
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
    int A=0,B;cin>>B;
    
    if(B>=(1<<N)){
        cout<<(1<<N)-1<<endl;
        for(int i=1;i<(1<<N);i++){
            for(int j=N;j>=0;j--){
                if(i%(1<<j)==0){
                    cout<<(1<<j)<<" ";
                    break;
                }
            }
        }
        cout<<endl;
        return 0;
    }
    
    vector<int> c;
    
    solve(A,B,0,(1<<N),c);
    
    cout<<(1<<(N-1))-1<<endl;
    
    for(int i=0;i+1<(1<<(N-1));i++){
        cout<<(S[i]^S[i+1])<<" ";
    }
    cout<<endl;
}