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
const int mod=1000000007,MAX=105,INF=1<<30;

vector<ll> len;
string f0="What are you doing at the end of the world? Are you busy? Will you save us?";
string f1="What are you doing while sending ";
string f2="? Are you busy? Will you send ";

char solve(int N,ll K){
    //cout<<N<<" "<<K<<endl;
    if(N==0) return f0[K];
    if(K<=32) return f1[K];
    if(K==33) return '"';
    if(N>=si(len)) return solve(N-1,K-34);
    if(33+len[N-1]>=K) return solve(N-1,K-34);
    if(K==34+len[N-1]) return '"';
    if(64+len[N-1]>=K) return f2[K-len[N-1]-35];
    if(K==65+len[N-1]) return '"';
    if(K==66+len[N-1]+len[N-1]) return '"';
    if(K==67+len[N-1]+len[N-1]) return '?';
    return solve(N-1,K-66-len[N-1]);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    len.push_back(75);
    while(len.back()<=2e18){
        len.push_back(68LL+len.back()*2);
    }
    
    //for(int i=0;i<10;i++) cout<<i<<" "<<len[i]<<endl;
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll K;cin>>N>>K;
        K--;
        if(N<si(len)&&K>=len[N]){
            cout<<'.';
            continue;
        }else{
            cout<<solve(N,K);
        }
    }
    
    cout<<endl;
}