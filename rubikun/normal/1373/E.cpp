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
const int mod=1000000007,MAX=15;
const ll INF=1LL<<60;

int one[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    vector<int> D={0,1,3,6,10,15,21,28,36,45};
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=j;k++){
                one[i][j]+=(i+k)%10;
            }
            //cout<<one[i][j]<<" ";
        }
        //cout<<endl;
    }
    
    while(Q--){
        int N,K;cin>>N>>K;
        if(N<D[K]){
            cout<<-1<<"\n";
            continue;
        }
        
        ll ans=INF;
        
        for(int i=0;i<10;i++){
            int rem=N-one[i][K];
            if(rem<0) continue;
            if(i+K<10){
                if(rem==0){
                    chmin(ans,ll(i));
                    continue;
                }
                if(rem%(K+1)==0){
                    rem/=(K+1);
                    string S;
                    while(rem){
                        if(rem>=9){
                            S+='9';
                            rem-=9;
                        }else{
                            S+=char('0'+rem);
                            rem=0;
                        }
                    }
                    reverse(all(S));
                    chmin(ans,stoll(S)*10+i);
                }
            }else{
                ll b=i+(K+1)-10,a=K+1-b;
                
                for(int x=0;x<=200;x++){
                    for(int y=(x+1)%9;y<=200;y+=9){
                        if(a*x+b*y!=rem) continue;
                        
                        string S;
                        ll rrr=x;
                        while(rrr){
                            if(rrr>=9){
                                S+='9';
                                rrr-=9;
                            }else{
                                S+=char('0'+rrr);
                                rrr=0;
                            }
                        }
                        reverse(all(S));
                        if(si(S)==0) S="0";
                        ll A=stoll(S);
                        ll B=A+1;
                        ll bbb=0;
                        while(B){
                            bbb+=B%10;
                            B/=10;
                        }
                        if(bbb==y) chmin(ans,A*10+i);
                        
                        S.clear();
                        rrr=x;
                        
                        if(rrr<=8) continue;
                        
                        S+='8';
                        rrr-=8;
                        while(rrr){
                            if(rrr>=9){
                                S+='9';
                                rrr-=9;
                            }else{
                                S+=char('0'+rrr);
                                rrr=0;
                            }
                        }
                        reverse(all(S));
                        
                        A=stoll(S);
                        B=A+1;
                        bbb=0;
                        while(B){
                            bbb+=B%10;
                            B/=10;
                        }
                        if(bbb==y) chmin(ans,A*10+i);
                    }
                }
            }
        }
        if(ans==INF) ans=-1;
        
        cout<<ans<<"\n";
    }
}