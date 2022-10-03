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
const int mod=1000000007,MAX=200005,INF=1<<29;

int score(int al,int ar,int bl,int br){
    if(al>bl){
        swap(al,bl);
        swap(ar,br);
    }
    return max(0,min(ar,br)-bl+1);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<pair<int,int>> A(M);
    for(int i=0;i<M;i++){
        cin>>A[i].fi>>A[i].se;
        A[i].fi--;A[i].se--;
        A[i].fi+=N;
        A[i].se+=N;
    }
    
    vector<int> ups(M),upg(M),downs(M),downg(M);
    
    int ans=0;
    
    for(int i=0;i<M;i++){
        vector<int> B(3*N);
        for(int j=K-1;j<3*N;j++){
            B[j]=score(j-(K-1),j,A[i].fi,A[i].se);
        }
        //for(int j=0;j<3*N;j++) cout<<B[j]<<" ";
        //cout<<endl;
        for(int j=0;j+1<3*N;j++){
            if(B[j]<B[j+1]){
                ups[i]=j+1;
                break;
            }
        }
        for(int j=0;j+1<3*N;j++){
            if(B[j]==B[j+1]&&B[j]){
                upg[i]=j+1;
                break;
            }
            if(B[j]>B[j+1]){
                upg[i]=j+1;
                break;
            }
        }
        for(int j=0;j+1<3*N;j++){
            if(B[j]>B[j+1]){
                downs[i]=j+1;
                break;
            }
        }
        for(int j=0;j+1<3*N;j++){
            if(B[j]>B[j+1]&&B[j+1]==0){
                downg[i]=j+2;
                break;
            }
        }
        
        //cout<<ups[i]<<" "<<upg[i]<<" "<<downs[i]<<" "<<downg[i]<<endl;
    }
    
    for(int a=K-1;a<3*N;a++){
        int sum=0;
        vector<int> imo(3*N+3);
        for(int i=0;i<M;i++){
            int d=score(a-(K-1),a,A[i].fi,A[i].se);
            sum+=d;
            
            imo[min(upg[i],ups[i]+d)]++;
            imo[upg[i]]--;
            
            imo[downs[i]]--;
            imo[max(downs[i],downg[i]-d)]++;
        }
        
        for(int j=1;j<3*N+3;j++) imo[j]+=imo[j-1];
        for(int j=1;j<3*N+3;j++) imo[j]+=imo[j-1];
        
        sort(all(imo));
        
        chmax(ans,sum+imo.back());
    }
    
    cout<<ans<<endl;
}