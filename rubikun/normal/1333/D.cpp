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
    
    int N,K;cin>>N>>K;
    string S;cin>>S;
    int cnt=0;
    set<int> SE;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(S[i]=='R'&&S[j]=='L') cnt++;
        }
        if(i+1<N&&S[i]=='R'&&S[i+1]=='L') SE.insert(i);
    }
    if(cnt<K){
        cout<<-1<<endl;
        return 0;
    }
    
    vector<vector<int>> T(K);
    bool ok=true;
    
    for(int t=0;t<K;t++){
        if(cnt==K-t){
            int a=*(SE.begin());
            //cout<<t<<" "<<a<<endl;
            T[t].push_back(a);
            swap(S[a],S[a+1]);
            SE.erase(a);
            cnt--;
            if(a){
                if(S[a-1]=='R'&&S[a]=='L') SE.insert(a-1);
            }
            if(a+2<N){
                if(S[a+1]=='R'&&S[a+2]=='L') SE.insert(a+1);
            }
        }else{
            set<int> to;
            int lim=cnt-(K-t-1);
            for(auto a:SE){
                if(lim<=0){
                    to.insert(a);
                    continue;
                }
                T[t].push_back(a);
                swap(S[a],S[a+1]);
                cnt--;
                lim--;
                if(a){
                    if(S[a-1]=='R'&&S[a]=='L'){
                        to.insert(a-1);
                        //cout<<t<<" "<<a-1<<endl;
                    }
                }
                if(a+2<N){
                    if(S[a+1]=='R'&&S[a+2]=='L'){
                        to.insert(a+1);
                        //cout<<t<<" "<<a+1<<endl;
                    }
                }
            }
            SE=to;
        }
    }
    
    for(int i=0;i<K;i++) if(T[i].size()==0) ok=false;
    
    if(T[K-1].size()&&SE.size()==0&&ok){
        for(int i=0;i<K;i++){
            cout<<T[i].size();
            for(int a:T[i]) cout<<" "<<a+1;
            cout<<"\n";
        }
    }else{
        cout<<-1<<endl;
    }
}