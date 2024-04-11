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
const int mod=1000000007,MAX=105;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,s;ll t;
    cin>>N>>M>>s>>t;
    s--;
    
    while(t%N){
        if(s<M) s+=t%N;
        else s+=N-t%N;
        s%=N;
        t--;
    }
    
    if(t==0){
        cout<<s+1<<endl;
        return 0;
    }
    
    vector<ll> when(N,-1),st;
    ll timer=1;
    
    when[s]=0;
    st.push_back(s);
    
    while(timer*N<=t){
        for(int q=N-1;q>=1;q--){
            if(s<M) s+=q;
            else s+=N-q;
            s%=N;
            //t--;
        }
        
        if(when[s]!=-1){
            t/=N;
            t-=when[s];
            ll syuuki=timer-when[s];
            cout<<st[when[s]+t%syuuki]+1<<endl;
            
            return 0;
        }else{
            when[s]=timer;
            st.push_back(s);
            
            timer++;
        }
    }
    
    cout<<s+1<<endl;
}