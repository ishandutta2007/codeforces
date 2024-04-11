#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int solve(int left,int right,int bit,int plus,vector<int> &A){
    if(bit==30) return 0;
    if((A[left]&(1<<29-bit))==(A[right-1]&(1<<29-bit))){
        return solve(left,right,bit+1,plus+(A[left]&(1<<29-bit)),A);
    }else{
        int a=lower_bound(all(A),plus+(1<<29-bit))-A.begin();
        return (1<<29-bit)+min(solve(left,a,bit+1,plus,A),solve(a,right,bit+1,plus+(1<<29-bit),A));
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    
    cout<<solve(0,N,0,0,A)<<endl;
    
    //cout<<(1<<30)<<endl;
}