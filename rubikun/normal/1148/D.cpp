#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;

bool compare1(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return a.first.first>b.first.first;
}

bool compare2(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return a.first.first<b.first.first;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<pair<pair<int,int>,int>> A,B;
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        if(a<b) A.push_back({{a,b},i+1});
        else B.push_back({{a,b},i+1});
    }
    
    if(A.size()<B.size()){
        sort(all(B),compare2);
        
        cout<<B.size()<<endl;
        for(int i=0;i<B.size();i++) cout<<B[i].second<<" ";
        cout<<endl;
    }else{
        sort(all(A),compare1);
        
        cout<<A.size()<<endl;
        for(int i=0;i<A.size();i++) cout<<A[i].second<<" ";
        cout<<endl;
    }
}