#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int x,y;cin>>x>>y;
    vector<int> X(N+1,0),Y(N+1,0);
    for(int i=0;i<N;i++){
        X[i+1]=X[i];
        Y[i+1]=Y[i];
        
        if(S[i]=='U') Y[i+1]++;
        if(S[i]=='D') Y[i+1]--;
        if(S[i]=='L') X[i+1]--;
        if(S[i]=='R') X[i+1]++;
    }
    
    if(abs(x)+abs(y)>N||(N-abs(x)-abs(y))%2==1) cout<<-1<<endl;
    else if(x==X[N]&&y==Y[N]) cout<<0<<endl;
    else{
        int left=N%2-2,right=N;
        while(right-left>1){
            bool ok=false;
            int mid=(left+right)/2;
            for(int i=1;i+mid-1<=N;i++){
                int xx=X[N]-X[i+mid-1]+X[i-1],yy=Y[N]-Y[i+mid-1]+Y[i-1];
                if(abs(xx-x)+abs(yy-y)<=mid) ok=true;
            }
            if(ok) right=mid;
            else left=mid;
        }
        cout<<right<<endl;
    }
}