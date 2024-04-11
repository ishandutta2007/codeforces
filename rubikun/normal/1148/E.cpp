#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=203,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    ll sum=0;
    vector<pair<int,int>> s(N),t(N);
    for(int i=0;i<N;i++){
        cin>>s[i].first;
    }
    for(int i=0;i<N;i++){
        cin>>t[i].first;
        s[i].second=t[i].second=i+1;
        sum+=s[i].first-t[i].first;
    }
    vector<pair<int,int>> ans;
    vector<int> d;
    sort(all(s));
    sort(all(t));
    
    bool ok=true;
    
    if(s[0].first>t[0].first||sum!=0) ok=false;
    
    vector<int> D(N),id(N);
    
    for(int i=0;i<N;i++){
        D[i]=s[i].first-t[i].first;
        id[i]=s[i].second;
    }
    
    stack<pair<int,int>> ST;
    
    for(int i=0;i<N;i++){
        if(D[i]==0) continue;
        else if(D[i]>0){
            while(D[i]>0&&!ST.empty()){
                pair<int,int> p=ST.top();
                ST.pop();
                if(p.first<=D[i]){
                    ans.push_back({p.second,id[i]});
                    d.push_back(p.first);
                    D[i]-=p.first;
                }else{
                    ans.push_back({p.second,id[i]});
                    d.push_back(D[i]);
                    ST.push({p.first-D[i],p.second});
                    D[i]=0;
                }
            }
            if(D[i]>0) ok=false;
        }else if(D[i]<0) ST.push({-D[i],id[i]});
    }
    
    /*int ai=0,bi=0;
    
    for(ai;ai<N;ai++){
        if(D[ai]>=0) continue;
        
        while(D[ai]<0){
            if(bi==N){
                ok=false;
                break;
            }
            //if(ai>bi) bi=ai;
            if(D[bi]<=0) bi++;
            else if(D[bi]>=abs(D[ai])){
                ans.push_back({id[ai],id[bi]});
                d.push_back(abs(D[ai]));
                D[bi]-=abs(D[ai]);
                D[ai]=0;
            }else{
                ans.push_back({id[ai],id[bi]});
                d.push_back(abs(D[bi]));
                D[ai]+=D[bi];
                D[bi]=0;
                //bi++;
            }
            
            if(bi==N) break;
        }
        if(!ok) break;
    }*/
    
    if(ok){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<" "<<d[i]<<endl;
        }
    }else cout<<"NO"<<endl;
    
}