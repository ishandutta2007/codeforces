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
const int mod=1000000007,MAX=5005,INF=1<<30;

pair<short,short> A[MAX][MAX],B[MAX][MAX];
short cnt1[MAX],cnt2[MAX],cnt3[MAX],pos[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=si(S);
    
    for(int i=0;i<N;i++){
        int sum=0,mi=0;
        for(int j=i;j<N;j++){
            if(S[j]==')') sum--;
            else sum++;
            chmin(mi,sum);
            A[i][j]=mp(sum,mi);
        }
        
        sum=0;mi=0;
        for(int j=i;j<N;j++){
            if(S[j]=='(') sum++;
            else sum--;
            chmin(mi,sum);
            B[i][j]=mp(sum,mi);
        }
        
        cnt1[i+1]=cnt1[i];
        cnt2[i+1]=cnt2[i];
        cnt3[i+1]=cnt3[i];
        
        if(S[i]=='(') cnt1[i+1]++;
        if(S[i]==')') cnt2[i+1]++;
        if(S[i]=='?') cnt3[i+1]++;
    }
    
    memset(pos,-1,sizeof(pos));
    
    int ans=0;
    
    for(int i=0;i<N;i++){
        int cn=0;
        for(int j=i;j<N;j++){
            if(S[j]=='?'){
                cn++;
                pos[i][cn]=j;
            }
        }
        for(int j=i+1;j<N;j+=2){
            int a=cnt1[j+1]-cnt1[i];
            int b=cnt2[j+1]-cnt2[i];
            int c=cnt3[j+1]-cnt3[i];
            
            if(abs(a-b)>c) continue;
            
            int x=(c-a+b)/2,y=c-x;
            
            if(x==0){
                if(y==0){
                    if(A[i][j].se>=0) ans++;
                }else{
                    if(B[i][j].se>=0) ans++;
                }
                continue;
            }
            int p=pos[i][x];
            if(p==-1) continue;
            
            if(A[i][p].se<0) continue;
            if(A[i][p].fi+B[p+1][j].se<0) continue;
            
            ans++;
            
        }
    }
    
    cout<<ans<<endl;
}