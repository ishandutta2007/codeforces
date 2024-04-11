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
const int mod=998244353,MAX=300005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> cn(N);
    int ki=0;
    int M=0;
    for(int i=0;i<N;i++){
        cin>>cn[i];
        if(cn[i]&1) ki++;
        M+=cn[i];
    }
    if(N==1){
        cout<<M<<"\n";
        for(int i=0;i<M;i++) cout<<'a';
        cout<<"\n";
        return 0;
    }
    if(ki>=2){
        cout<<0<<"\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<cn[i];j++) cout<<char('a'+i);
        }
        cout<<"\n";
        return 0;
    }
    ll g=0;
    for(int i=0;i<N;i++) g=gcd(g,cn[i]);
    if(ki==1){
        cout<<g<<"\n";
        int x=-1;
        for(int i=0;i<N;i++){
            if(cn[i]&1){
                x=i;
                cn[i]-=g;
                break;
            }
        }
        string S;
        for(int i=0;i<N;i++){
            for(int j=0;j<cn[i]/g/2;j++) S+=char('a'+i);
        }
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<cn[i]/g/2;j++) S+=char('a'+i);
        }
        for(int k=0;k<g;k++){
            cout<<char('a'+x);
            cout<<S;
        }
        cout<<"\n";
    }else{
        cout<<g<<"\n";
        for(int t=0;t<g;t++){
            if(t&1){
                for(int i=N-1;i>=0;i--){
                    for(int j=0;j<cn[i]/g;j++) cout<<char('a'+i);
                }
            }else{
                for(int i=0;i<N;i++){
                    for(int j=0;j<cn[i]/g;j++) cout<<char('a'+i);
                }
            }
        }
        cout<<"\n";
    }
}