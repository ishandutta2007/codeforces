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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll A,B,C;cin>>N>>A>>B>>C;
        string S;cin>>S;
        vector<pair<int,int>> RL;
        for(int i=0;i<N;i++){
            if(si(RL)&&RL.back().fi==(int)(S[i]-'0')) RL.back().se++;
            else RL.push_back(mp((int)(S[i]-'0'),1));
        }
        ll cn0=0,cn1=0;
        for(auto a:RL){
            if(a.fi==0) cn0+=a.se-1;
            else cn1+=a.se-1;
        }
        vector<int> ER;
        for(int i=1;i+1<si(RL);i++){
            if(RL[i].fi==0) ER.push_back(RL[i].se-1);
        }
        sort(all(ER));
        
        ll ans=0;
        if(cn0==cn1) chmax(ans,cn0*A+cn1*B);
        else if(cn0>cn1) chmax(ans,(cn1+1)*A+cn1*B);
        else chmax(ans,cn0*A+(cn0+1)*B);
        
        swap(A,B);
        
        if(si(RL)>=2){
            {
                ll ERsum=0;
                for(ll i=-1;i<si(ER);i++){
                    if(i>=0) ERsum+=ER[i];
                    if(cn1>ERsum){
                        ll a=cn1+(i+1),b=cn0+(i+1);
                        if(a==b) chmax(ans,a*A+cn0*B-(i+1)*C);
                        else if(a>b) chmax(ans,(b+1)*A+cn0*B-(i+1)*C);
                        else chmax(ans,a*A+(a-(i+1))*B-(i+1)*C);
                    }
                    if(cn1>=ERsum){
                        ll a=cn1+(i+1),b=cn0+(i+1);
                        if(a==b) chmax(ans,a*A+cn0*B-(i+1)*C);
                        else if(a>b) chmax(ans,b*A+cn0*B-(i+1)*C);
                        else chmax(ans,a*A+(a+1-(i+1))*B-(i+1)*C);
                    }
                }
            }
            
            if(RL.front().fi+RL.back().fi==1){
                ll ERsum=0;
                for(ll i=-1;i<si(ER);i++){
                    if(i>=0) ERsum+=ER[i];
                    if(cn1>ERsum){
                        ll a=cn1+(i+1),b=cn0+(i+1);
                        ll bon=0;
                        if(a>b+1) chmax(bon,A-C);
                        if(a==b) chmax(ans,a*A+cn0*B-(i+1)*C);
                        else if(a>b) chmax(ans,(b+1)*A+cn0*B-(i+1)*C+bon);
                        else chmax(ans,a*A+(a-(i+1))*B-(i+1)*C);
                    }
                    if(cn1>=ERsum){
                        ll a=cn1+(i+1),b=cn0+(i+1);
                        ll bon=0;
                        if(a>b) chmax(bon,A-C);
                        if(a==b) chmax(ans,a*A+cn0*B-(i+1)*C);
                        else if(a>b) chmax(ans,b*A+cn0*B-(i+1)*C+bon);
                        else chmax(ans,a*A+(a+1-(i+1))*B-(i+1)*C);
                    }
                }
            }
            
            if(RL.front().fi+RL.back().fi==0){
                ll ERsum=0;
                for(ll i=-1;i<si(ER);i++){
                    if(i>=0) ERsum+=ER[i];
                    if(cn1>ERsum){
                        ll a=cn1+(i+1),b=cn0+(i+1);
                        ll bon=0;
                        if(a>b+1) chmax(bon,A-C);
                        if(a>b+2) chmax(bon,(A-C)*2);
                        if(a==b) chmax(ans,a*A+cn0*B-(i+1)*C);
                        else if(a>b) chmax(ans,(b+1)*A+cn0*B-(i+1)*C+bon);
                        else chmax(ans,a*A+(a-(i+1))*B-(i+1)*C);
                    }
                    if(cn1>=ERsum){
                        ll a=cn1+(i+1),b=cn0+(i+1);
                        ll bon=0;
                        if(a>b) chmax(bon,A-C);
                        if(a>b+1) chmax(bon,(A-C)*2);
                        if(a==b) chmax(ans,a*A+cn0*B-(i+1)*C);
                        else if(a>b) chmax(ans,b*A+cn0*B-(i+1)*C+bon);
                        else chmax(ans,a*A+(a+1-(i+1))*B-(i+1)*C);
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}