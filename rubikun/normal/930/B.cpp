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
int cnt[26][MAX][26];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=si(S);
    
    for(int i=0;i<N;i++){
        for(int k=1;k<N;k++){
            int j=(i+k)%N;
            cnt[int(S[i]-'a')][k][int(S[j]-'a')]++;
        }
    }
    
    double ans=0;
    
    for(int i=0;i<26;i++){
        int ma=0;
        for(int k=1;k<N;k++){
            int can=0;
            for(int j=0;j<26;j++){
                if(cnt[i][k][j]==1) can++;
            }
            chmax(ma,can);
        }
        ans+=ma;
        
    }
    
    cout<<fixed<<setprecision(25)<<(double)(ans)/N<<endl;
}