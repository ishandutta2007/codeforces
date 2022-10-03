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
const int mod=1000000007,MAX=100005;
const ll INF=1<<30;
int A[MAX];
string a;

string solve(int l,int r){
    int L=l,R=r;
    while(L<r&&A[L]==1) L++;
    while(R>=l&&A[R-1]==1) R--;
    string res;
    
    if(L>=R){
        for(int i=l;i<r;i++){
            if(i>l) res+='+';
            res+=a[i];
        }
        return res;
    }
    for(int i=l;i<L;i++){
        res+=a[i];
        res+='+';
    }
    
    ll kake=1;
    
    for(int i=L;i<R;i++){
        kake*=A[i];
        if(kake>3*(R-L)) break;
    }
    
    if(kake>3*(R-L)){
        for(int i=L;i<R;i++){
            if(i>L) res+='*';
            res+=a[i];
        }
        for(int i=R;i<r;i++){
            res+='+';
            res+=a[i];
        }
        
        return res;
    }
    
    vector<int> X;
    for(int i=L;i<R;i++){
        if(A[i]>=2) X.push_back(i);
    }
    
    int M=si(X);
    
    if(M==1){
        res.clear();
        for(int i=l;i<r;i++){
            if(i>l) res+='+';
            res+=a[i];
        }
        return res;
    }
    
    //cout<<"X"<<endl;
    
    pair<int,int> ma={-1,-1};
    for(int bit=0;bit<(1<<(M-1));bit++){
        int sum=0;
        int i=0;
        while(i<M-1){
            if(!(bit&(1<<i))){
                sum+=A[X[i]];
                sum+=X[i+1]-X[i]-1;
                i++;
                
                if(i==M-1) sum+=A[X[M-1]];
            }else{
                int j=i;
                while(j<M-1&&(bit&(1<<j))) j++;
                int xx=1;
                for(int k=i;k<=j;k++){
                    xx*=A[X[k]];
                }
                //cout<<i<<" "<<j<<" "<<xx<<endl;
                sum+=xx;
                if(j<M-1){
                    sum+=X[j+1]-X[j]-1;
                    i=j;
                    i++;
                    
                    if(i==M-1) sum+=A[X[M-1]];
                }else{
                    break;
                }
            }
        }
        
        chmax(ma,mp(sum,bit));
        //cout<<sum<<" "<<bit<<endl;
    }
    
    int bit=ma.se;
    res+=a[X[0]];
    for(int t=0;t<M-1;t++){
        for(int i=X[t]+1;i<=X[t+1];i++){
            if(bit&(1<<t)) res+='*';
            else res+='+';
            
            res+=a[i];
        }
    }
    
    for(int i=R;i<r;i++){
        res+='+';
        res+=a[i];
    }
    
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        a+=char('0'+A[i]);
    }
    string T;cin>>T;
    
    sort(all(T));
    
    if(si(T)==1){
        for(int i=0;i<N;i++){
            if(i) cout<<T;
            cout<<A[i];
        }
        cout<<endl;
        
        return 0;
    }
    
    if(T=="+-"){
        for(int i=0;i<N;i++){
            if(i) cout<<'+';
            cout<<A[i];
        }
        cout<<endl;
        
        return 0;
    }
    
    if(T=="*-"){
        string ans;
        for(int i=0;i<N;i++){
            if(i) ans+='*';
            ans+=char('0'+A[i]);
        }
        for(int i=2;i<si(ans);i+=2){
            if(ans[i]=='0'){
                ans[i-1]='-';
                break;
            }
        }
        
        cout<<ans<<endl;
        
        return 0;
    }
    
    string ans;
    
    int i=0;
    
    while(i<N){
        int j=i;
        while(j<N&&A[j]==0) j++;
        for(int k=i;k<j;k++){
            if(k) ans+='+';
            ans+=a[k];
        }
        
        i=j;
        if(i>=N) break;
        
        while(j<N&&A[j]) j++;
        string S=solve(i,j);
        
        if(i) ans+='+';
        ans+=S;
        
        i=j;
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}