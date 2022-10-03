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
const int mod=1000000007,MAX=200005;
const int INF=1<<30;
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        string S;cin>>S;
        int sum=0,cnt=0;
        
        vector<int> B;
        
        for(int i=0;i<N;i++){
            if(S[i]=='W'){
                if(i&&S[i-1]=='W') sum+=2;
                else sum++;
            }else cnt++;
        }
        
        int i=0;
        while(i<N){
            while(i<N&&S[i]=='W') i++;
            if(i==N) break;
            int j=i;
            while(j<N&&S[j]=='L') j++;
            B.push_back(j-i);
            i=j;
        }
        
        if(S[0]=='L') B[0]=INF;
        if(S[N-1]=='L') B.back()=INF;
        
        sort(all(B));
        
        //for(int a:B) cout<<a<<" ";
        //cout<<endl;
        
        chmin(K,cnt);
        
        if(sum==0){
            if(K==0) cout<<0<<"\n";
            else cout<<1+(K-1)*2<<"\n";
        }else{
            sum+=2*K;
            
            for(int i=0;i<si(B);i++){
                if(B[i]<=K){
                    K-=B[i];
                    sum++;
                }
            }
            cout<<sum<<"\n";
        }
    }
    
}