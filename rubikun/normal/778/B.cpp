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

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    map<string,int> dic;
    int sz=1;
    dic["?"]=0;
    vector<vector<string>> S(N+1);
    for(int i=0;i<N;i++){
        string A;cin>>A;
        dic[A]=sz;sz++;
        string z;cin>>z;
        string B;cin>>B;
        if(B[0]=='0'||B[0]=='1'){
            S[i+1]={B};
        }else{
            string C,D;cin>>C>>D;
            S[i+1]={to_string(dic[B]),C,to_string(dic[D])};
        }
    }
    
    string mi,ma;
    for(int t=0;t<M;t++){
        vector<int> sum(2);
        for(int q=0;q<2;q++){
            vector<int> T(N+1);
            T[0]=q;
            for(int i=1;i<=N;i++){
                if(si(S[i])==1){
                    T[i]=(int)(S[i][0][t]-'0');
                }else{
                    int a=stoi(S[i][0]),b=stoi(S[i][2]);
                    if(S[i][1]=="AND"){
                        T[i]=T[a]&T[b];
                    }
                    if(S[i][1]=="OR"){
                        T[i]=T[a]|T[b];
                    }
                    if(S[i][1]=="XOR"){
                        T[i]=T[a]^T[b];
                    }
                }
            }
            for(int i=1;i<=N;i++) sum[q]+=T[i];
        }
        if(sum[0]==sum[1]){
            mi+='0';
            ma+='0';
        }else if(sum[0]<sum[1]){
            mi+='0';
            ma+='1';
        }else{
            mi+='1';
            ma+='0';
        }
    }
    
    cout<<mi<<"\n";
    cout<<ma<<"\n";
}