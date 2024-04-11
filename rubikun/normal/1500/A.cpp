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
const int mod=1000000007,MAX=5000005,INF=1<<30;

pair<int,int> deta[MAX];

vector<int> when[MAX/2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++){
        cin>>A[i];
        when[A[i]].push_back(i);
    }
    
    vector<int> P;
    
    for(int i=1;i<MAX/2;i++){
        if(si(when[i])>=4){
            cout<<"YES"<<endl;
            for(int j=0;j<4;j++) cout<<when[i][j]<<" ";
            cout<<endl;
            return 0;
        }
        if(si(when[i])>=2){
            P.push_back(when[i][0]);
            P.push_back(when[i][1]);
        }
    }
    
    if(si(P)>=4){
        cout<<"YES"<<endl;
        cout<<P[0]<<" "<<P[2]<<" "<<P[1]<<" "<<P[3]<<endl;
        return 0;
    }
    
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            int X=A[i]+A[j];
            if(deta[X].fi){
                if(i==deta[X].fi) continue;
                if(j==deta[X].fi) continue;
                if(i==deta[X].se) continue;
                if(j==deta[X].se) continue;
                
                cout<<"YES"<<endl;
                cout<<deta[X].fi<<" "<<deta[X].se<<" "<<i<<" "<<j<<endl;
                return 0;
            }else{
                deta[X].fi=i;
                deta[X].se=j;
            }
        }
    }
    
    cout<<"NO"<<endl;
}