#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;

int sums[MAX],sumt[MAX],maxs[MAX],maxt[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S,T;cin>>S>>T;
    
    int N=si(S),M=si(T);
    
    for(int i=0;i<N;i++){
        if(S[i]=='C') S[i]='B';
        if(S[i]=='B') sums[i+1]++;
    }
    
    for(int i=0;i<M;i++){
        if(T[i]=='C') T[i]='B';
        if(T[i]=='B') sumt[i+1]++;
    }
    
    for(int i=1;i<=N;i++) sums[i]+=sums[i-1];
    for(int i=1;i<=M;i++) sumt[i]+=sumt[i-1];
    
    for(int i=N;i>=1;i--){
        int j=i;
        while(j&&S[j-1]=='A') j--;
        j++;
        for(int k=i;k>=j;k--){
            maxs[k]=k-(j-1);
        }
        i=j-1;
    }
    
    for(int i=M;i>=1;i--){
        int j=i;
        while(j&&T[j-1]=='A') j--;
        j++;
        for(int k=i;k>=j;k--){
            maxt[k]=k-(j-1);
        }
        i=j-1;
    }
    
    int Q;cin>>Q;
    while(Q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;c--;
        
        int x1,y1,x2,y2;
        y1=min(b-a,maxs[b]);
        y2=min(d-c,maxt[d]);
        x1=sums[b-y1]-sums[a];
        x2=sumt[d-y2]-sumt[c];
        
        if(y1<y2){
            cout<<0;
            continue;
        }
        if(y1>y2){
            if((y1-y2)%3==0){
                if(x1==0&&x2) x1+=2;
            }else{
                x1+=2;
            }
        }
        
        if(x1==x2) cout<<1;
        else if(x1>x2) cout<<0;
        else if(x1==0) cout<<0;
        else if((x2-x1)%2) cout<<0;
        else cout<<1;
    }
    cout<<endl;
}