#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int k=0;k<Q;k++){
        string S,T,P;cin>>S>>T>>P;
        bool ok=false;
        int i=0,j=0;
        while(j<T.size()){
            while(j<T.size()&&S[i]!=T[j]) j++;
            if(j==T.size()) break;
            i++;
            j++;
            if(i==S.size()) ok=true;
        }
        vector<int> cnt(26,0);
        for(int i=0;i<S.size();i++){
            cnt[S[i]-'a']++;
        }
        for(int i=0;i<P.size();i++){
            cnt[P[i]-'a']++;
        }
        for(int i=0;i<T.size();i++){
            cnt[T[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]<0) ok=false;
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}