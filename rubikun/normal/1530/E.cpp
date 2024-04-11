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
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> X[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int N=si(S);
        vector<int> cnt(26);
        for(char c:S) cnt[int(c-'a')]++;
        
        string T=S;
        sort(all(T));
        if(T.front()==T.back()){
            cout<<T<<"\n";
            continue;
        }
        int ma=-1,mi=INF;
        for(int i=0;i<26;i++){
            chmax(ma,cnt[i]);
            if(cnt[i]) chmin(mi,cnt[i]);
        }
        if(ma==1){
            cout<<T<<"\n";
            continue;
        }
        
        if(mi==1){
            for(int i=0;i<26;i++){
                if(cnt[i]==1){
                    cout<<char('a'+i);
                    cnt[i]--;
                    for(int j=0;j<26;j++){
                        while(cnt[j]){
                            cout<<char('a'+j);
                            cnt[j]--;
                        }
                    }
                    cout<<"\n";
                    break;
                }
            }
            continue;
        }
        
        for(int i=0;i<26;i++){
            if(cnt[i]){
                if(cnt[i]-2<=N-cnt[i]){
                    string A(cnt[i],char('a'+i)),B;
                    for(int j=i+1;j<26;j++){
                        while(cnt[j]){
                            B+=char('a'+j);
                            cnt[j]--;
                        }
                    }
                    string ans;
                    ans+=A[0];
                    int a=1,b=0;
                    bool f=false;
                    while(a<si(A)||b<si(B)){
                        if(!f){
                            if(a<si(A)) ans+=A[a];
                            a++;
                            f=true;
                        }else{
                            if(b<si(B)) ans+=B[b];
                            b++;
                            f=false;
                        }
                    }
                    cout<<ans<<"\n";
                }else{
                    int syu=0;
                    for(int k=0;k<26;k++) if(cnt[k]) syu++;
                    if(syu>=3){
                        cout<<char('a'+i);
                        cnt[i]--;
                        for(int j=i+1;j<26;j++){
                            if(cnt[j]){
                                cout<<char('a'+j);
                                cnt[j]--;
                                while(cnt[i]){
                                    cout<<char('a'+i);
                                    cnt[i]--;
                                }
                                for(int k=j+1;k<26;k++){
                                    if(cnt[k]){
                                        cout<<char('a'+k);
                                        cnt[k]--;
                                        
                                        for(int x=0;x<26;x++){
                                            while(cnt[x]){
                                                cout<<char('a'+x);
                                                cnt[x]--;
                                            }
                                        }
                                        cout<<"\n";
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    }else{
                        cout<<char('a'+i);
                        cnt[i]--;
                        for(int j=i+1;j<26;j++){
                            while(cnt[j]){
                                cout<<char('a'+j);
                                cnt[j]--;
                            }
                        }
                        while(cnt[i]){
                            cout<<char('a'+i);
                            cnt[i]--;
                        }
                        cout<<"\n";
                        
                    }
                }
                break;
            }
        }
        
    }
}