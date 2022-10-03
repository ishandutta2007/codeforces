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
const int mod=1000000007,MAX=3005,INF=1<<30;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

typedef pair<pair<vector<int>,vector<int>>,int> T;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<int> X(K);
    for(int j=0;j<K;j++){
        cin>>X[j];
    }
    cout<<1<<"\n";
    
    tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> SE;
    SE.insert(mp(mp(X,X),1));
    
    for(int i=1;i<N;i++){
        vector<int> S(K);
        for(int j=0;j<K;j++){
            cin>>S[j];
        }
        
        int left=-1,right=si(SE);
        while(right-left>1){
            int mid=(left+right)/2;
            auto ma=(*(SE.find_by_order(mid))).fi.fi;
            bool ok=false;
            for(int j=0;j<K;j++){
                if(S[j]<ma[j]) ok=true;
            }
            if(ok) right=mid;
            else left=mid;
        }
        
        if(right==si(SE)){
            cout<<1<<"\n";
            SE.insert(mp(mp(S,S),1));
        }else{
            auto it=SE.find_by_order(right);
            int cn=1;
            vector<int> inma=S,inmi=S;
            while(1){
                if(it==SE.end()) break;
                
                bool ok=false;
                auto ma=(*it).fi.fi;
                auto mi=(*it).fi.se;
                for(int j=0;j<K;j++){
                    if(S[j]>mi[j]) ok=true;
                }
                if(ok){
                    cn+=(*it).se;
                    for(int j=0;j<K;j++){
                        chmax(inma[j],ma[j]);
                        chmin(inmi[j],mi[j]);
                    }
                    it=SE.erase(it);
                }else{
                    break;
                }
            }
            
            SE.insert(mp(mp(inma,inmi),cn));
            
            cout<<(*SE.rbegin()).se<<"\n";
        }
    }
}