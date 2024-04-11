#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=2003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    string ans;
    int N=int(S.size());
    int left=0,right=N-1;
    while(right-left>=3){
        vector<int> cnt(3,0);
        cnt[S[left]-'a']++;
        cnt[S[left+1]-'a']++;
        cnt[S[right]-'a']++;
        cnt[S[right-1]-'a']++;
        for(int i=0;i<3;i++){
            if(cnt[i]>=2){
                ans+=char('a'+i);
                break;
            }
        }
        left+=2;
        right-=2;
    }
    cout<<ans;
    if(left<=right) cout<<S[left];
    reverse(all(ans));
    cout<<ans<<endl;
}