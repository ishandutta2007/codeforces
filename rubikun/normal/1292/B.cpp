#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    ll x,y,t;cin>>x>>y>>t;
    vector<ll> A,B;
    
    for(;;a=a*c+e,b=b*d+f){
        A.push_back(a);
        B.push_back(b);
        
        if(a>=20000000000000001||b>=20000000000000001) break;
    }
    
    int ans=0;
    
    for(int i=0;i<A.size();i++){
        int cnt=0;
        ll nowx=x,nowy=y,rem=t;
        if(abs(nowx-A[i])>rem||abs(nowy-B[i])>rem||abs(nowx-A[i])+abs(nowy-B[i])>rem) continue;
        rem-=abs(nowx-A[i])+abs(nowy-B[i]);
        cnt++;
        nowx=A[i];
        nowy=B[i];
        
        for(int j=i-1;j>=0;j--){
            if(abs(nowx-A[j])>rem||abs(nowy-B[j])>rem||abs(nowx-A[j])+abs(nowy-B[j])>rem) break;
            else{
                rem-=abs(nowx-A[j])+abs(nowy-B[j]);
                cnt++;
                nowx=A[j];
                nowy=B[j];
            }
        }
        
        ans=max(ans,cnt);
        
        rem=t-(abs(x-A[i])+abs(y-B[i]));
        cnt=1;
        nowx=A[i];
        nowy=B[i];
        
        for(int j=i+1;j<A.size();j++){
            if(abs(nowx-A[j])>rem||abs(nowy-B[j])>rem||abs(nowx-A[j])+abs(nowy-B[j])>rem) break;
            else{
                rem-=abs(nowx-A[j])+abs(nowy-B[j]);
                cnt++;
                nowx=A[j];
                nowy=B[j];
            }
        }
        
        ans=max(ans,cnt);
    }
    
    cout<<ans<<endl;
}