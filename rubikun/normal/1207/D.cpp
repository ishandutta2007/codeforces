#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=300005,INF=1<<30;

ll per[MAX];

void make(){
    per[0]=1;
    per[1]=1;
    for(ll i=2;i<=MAX;i++){
        per[i]=(per[i-1]*i)%mod;
    }
}

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    make();
    
    int N;cin>>N;
    vector<pair<int,int>> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i].first>>S[i].second;
    }
    sort(all(S));
    
    bool ok=true;
    
    for(int i=1;i<N;i++){
        if(S[i-1].second>S[i].second) ok=false;
    }
    
    ll cnt1=1,cnt2=1,cnt3=1;
    int pre1=S[0].first,c=1;
    for(int i=1;i<N;i++){
        if(S[i].first==pre1) c++;
        else{
            cnt1*=per[c];
            cnt1%=mod;
            c=1;
            pre1=S[i].first;
        }
        if(i==N-1){
            cnt1*=per[c];
            cnt1%=mod;
        }
    }
    
    sort(all(S),compare);
    
    int pre2=S[0].second;c=1;
    for(int i=1;i<N;i++){
        if(S[i].second==pre2) c++;
        else{
            cnt2*=per[c];
            cnt2%=mod;
            c=1;
            pre2=S[i].second;
        }
        if(i==N-1){
            cnt2*=per[c];
            cnt2%=mod;
        }
    }
    pre1=S[0].first;pre2=S[0].second;c=1;
    
    sort(all(S));
    
    for(int i=1;i<N;i++){
        if(S[i].first==pre1&&S[i].second==pre2) c++;
        else{
            cnt3*=per[c];
            cnt3%=mod;
            c=1;
            pre1=S[i].first;
            pre2=S[i].second;
        }
        if(i==N-1){
            cnt3*=per[c];
            cnt3%=mod;
        }
    }
    
    if(!ok) cnt3=0;
    cout<<(per[N]-cnt1-cnt2+cnt3+2*mod)%mod<<endl;
}