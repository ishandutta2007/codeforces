#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
typedef pair<double,double> pd;
const double eps=1e-9;

bool cmp_x(pd a,pd b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

double det(pd a,pd b,pd c,pd d){
    return (b.first-a.first)*(d.second-c.second)-(b.second-a.second)*(d.first-c.first);
}

vector<pd> convex_hull(vector<pd> &ps,int n){
    sort(all(ps),cmp_x);
    int k=0;
    vector<pd> qs(n*2);
    
    for(int i=0;i<n;i++){
        while(k>1&&(det(qs[k-1],qs[k-2],ps[i],qs[k-1])<=0)) k--;
        qs[k]=ps[i];
        k++;
    }
    
    for(int i=n-2,t=k;i>=0;i--){
        while(k>t&&(det(qs[k-1],qs[k-2],ps[i],qs[k-1])<=0)) k--;
        qs[k]=ps[i];
        k++;
    }
    
    qs.resize(k-1);
    return qs;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pd> S(N);
    for(int i=0;i<N;i++){
        ll a,b;cin>>a>>b;
        S[i]={a,b-a*a};
    }
    
    vector<pd> res=convex_hull(S,N);
    res.push_back(res[0]);
    
    int cnt=0;
    
    for(int i=0;i<res.size()-1;i++){
        if(res[i].first>res[i+1].first) cnt++;
    }
    
    cout<<cnt<<endl;
}