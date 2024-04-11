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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,S,T;cin>>N>>S>>T;
    vector<pair<ll,int>> C(N);
    vector<int> A(N+1,INF),B(N+1,INF),X(N+1,INF),Y(N+1,INF),mi1,mi2;
    for(int i=0;i<N;i++){
        cin>>C[i].fi;
        C[i].se=i;
    }
    
    sort(all(C));
    
    for(int i=1;i<=N;i++){
        int left=N,right=-1;
        while(left-right>1){
            int mid=(left+right)/2;
            if(C[mid].fi*i>=S) left=mid;
            else right=mid;
        }
        if(left<N&&N-left>=i) A[i]=left;
        
        left=N;right=-1;
        while(left-right>1){
            int mid=(left+right)/2;
            if(C[mid].fi*i>=T) left=mid;
            else right=mid;
        }
        if(left<N&&N-left>=i) B[i]=left;
    }
    
    for(int i=1;i<=N;i++){
        if(A[i]!=INF) chmin(X[A[i]],i);
        if(B[i]!=INF) chmin(Y[B[i]],i);
    }
    
    mi1=X;
    mi2=Y;
    
    for(int i=N-1;i>=0;i--){
        chmin(mi1[i],mi1[i+1]);
        chmin(mi2[i],mi2[i+1]);
    }
    
    for(int x=1;x<=N;x++){
        int ax=A[x];
        if(ax==INF) continue;
        int y=mi2[ax];
        if(x+y<=N-ax){
            cout<<"Yes"<<endl;
            cout<<x<<" "<<y<<endl;
            vector<int> ans1,ans2;
            for(int i=ax;i<ax+x;i++) ans1.push_back(C[i].se);
            for(int i=N-1;i>=N-y;i--) ans2.push_back(C[i].se);
            sort(all(ans1));
            sort(all(ans2));
            
            for(int a:ans1) cout<<a+1<<" ";
            cout<<endl;
            for(int a:ans2) cout<<a+1<<" ";
            cout<<endl;
            
            return 0;
        }
    }
    
    for(int y=1;y<=N;y++){
        int by=B[y];
        if(by==INF) continue;
        int x=mi1[by];
        if(x+y<=N-by){
            cout<<"Yes"<<endl;
            cout<<x<<" "<<y<<endl;
            vector<int> ans1,ans2;
            for(int i=N-1;i>=N-x;i--) ans1.push_back(C[i].se);
            for(int i=by;i<by+y;i++) ans2.push_back(C[i].se);
            sort(all(ans1));
            sort(all(ans2));
            
            for(int a:ans1) cout<<a+1<<" ";
            cout<<endl;
            for(int a:ans2) cout<<a+1<<" ";
            cout<<endl;
            
            
            return 0;
        }
    }
    
    cout<<"No"<<endl;
    
    return 0;
    
    for(int i=1;i<=N;i++) cout<<X[i]<<" ";
    cout<<endl;
    for(int i=1;i<=N;i++) cout<<Y[i]<<" ";
    cout<<endl;
}