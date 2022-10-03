#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> A,B;
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        if(b>=0) A.push_back({a,b});
        else B.push_back({a,b});
    }
    
    sort(all(A));
    
    bool ok=true;
    
    for(int i=0;i<A.size();i++){
        if(M<A[i].first) ok=false;
        M+=A[i].second;
    }
    
    sort(all(B),[&](pair<int,int> a,pair<int,int> b){
        if(a.first==b.first) return a.second>b.second;
        return a.first>b.first;
    });
    
    for(int i=0;i<B.size();i++){
        if(M<B[i].first) ok=false;
        for(int j=i+1;j<B.size();j++){
            if(M+B[i].second<B[j].first){
                //cout<<M+B[i].second<<" "<<B[j].first<<endl;
                M+=B[j].second;
                B[j]={0,0};
                //cout<<i<<" "<<j<<endl;
            }
        }
        for(int j=i+1;j<B.size();j++){
            if(M+B[j].second>=B[i].first){
                M+=B[j].second;
                B[j]={0,0};
            }
        }
        if(M<B[i].first){
            ok=false;
            //cout<<M<<" "<<B[i].first<<endl;
        }
        M+=B[i].second;
    }
    if(M<0) ok=false;
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}