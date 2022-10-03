#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    string S;cin>>S;
    int N=int(S.size());
    vector<int> maxisize((1<<20),0);
    for(int length=1;length<=20;length++){
        if(length>N) continue;
        vector<int> cnt(20,0);
        for(int i=0;i<length;i++){
            cnt[S[i]-'a']++;
        }
        int now=0;
        while(1){
            bool ok=true;
            int sum=0;
            for(int j=0;j<20;j++){
                if(cnt[j]>=2){
                    ok=false;
                }
                if(cnt[j]==1) sum+=(1<<j);
                //cout<<cnt[j]<<" ";
            }
            //cout<<endl;
            if(ok){
                maxisize[sum]=max(maxisize[sum],length);
            }
            if(now+length>=N) break;
            cnt[S[now]-'a']--;
            cnt[S[now+length]-'a']++;
            now++;
        }
    }
    
    for(int bit=0;bit<(1<<20);bit++){
        for(int j=0;j<20;j++){
            if(bit&(1<<j)) continue;
            maxisize[bit|(1<<j)]=max(maxisize[bit|(1<<j)],maxisize[bit]);
        }
    }
    
    int ans=0;
    
    for(int bit=0;bit<(1<<20);bit++){
        int bit2=(1<<20)-1-bit;
        ans=max(ans,maxisize[bit]+maxisize[bit2]);
    }
    
    cout<<ans<<endl;
}