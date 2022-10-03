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
    
    int Q;cin>>Q;
    while(Q--){
        int a,b,c,d,e,f,aa,bb,cc,dd,ee,ff;cin>>a>>b>>c>>d>>e>>f;
        vector<int> S(7),ans(7,-1);
        for(int i=0;i<7;i++) cin>>S[i];
        
        for(int i=0;i<=S[1];i++){
            for(int j=0;j<=S[2];j++){
                for(int k=0;k<=S[4];k++){
                    aa=a;
                    bb=b;
                    cc=c;
                    dd=d;
                    ee=e;
                    ff=f;
                    
                    aa-=i;
                    bb-=i;
                    
                    aa-=j;
                    cc-=j;
                    
                    bb-=k;
                    cc-=k;
                    
                    dd-=(S[1]-i);
                    ee-=(S[1]-i);
                    
                    dd-=(S[2]-j);
                    ff-=(S[2]-j);
                    
                    ee-=(S[4]-k);
                    ff-=(S[4]-k);
                    
                    if(aa<0||bb<0||cc<0||dd<0||ee<0||ff<0) continue;
                    
                    int mi=min({aa,bb,cc}),mi2=min({dd,ee,ff});
                    
                    if(S[0]<=mi){
                        aa-=S[0];
                        bb-=S[0];
                        cc-=S[0];
                    }else{
                        int re=S[0]-mi;
                        
                        aa-=mi;
                        bb-=mi;
                        cc-=mi;
                        
                        if(re<=mi2){
                            dd-=re;
                            ee-=re;
                            ff-=re;
                        }else{
                            continue;
                        }
                    }
                    
                    if(aa<0||bb<0||cc<0||dd<0||ee<0||ff<0) continue;
                    
                    if(S[3]<=aa+dd&&S[5]<=bb+ee&&S[6]<=cc+ff){
                        ans[1]=i;
                        ans[2]=j;
                        ans[4]=k;
                        
                        if(S[0]<=mi){
                            ans[0]=S[0];
                        }else{
                            ans[0]=mi;
                        }
                        
                        ans[3]=min(S[3],aa);
                        ans[5]=min(S[5],bb);
                        ans[6]=min(S[6],cc);
                    }
                }
            }
        }
        
        if(ans[0]==-1) cout<<-1<<endl;
        else{
            for(int a:ans) cout<<a<<" ";
            cout<<endl;
        }
    }
}