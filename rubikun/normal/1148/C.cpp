#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;
 
int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> P(N+1),where(N+1),copy(N+1);
    for(int i=1;i<=N;i++){
        cin>>P[i];
        //scanf("%d",&P[i]);
        where[P[i]]=i;
        copy[i]=P[i];
    }
    
    vector<pair<int,int>> ans;
    
    for(int i=N/2;i>=1;i--){
        if(where[i]<=N/2){
            
            if(where[i]==i) continue;
            ans.push_back({where[i],N});
            ans.push_back({N,i});
            
            int a=where[i],b=P[N];
            
            swap(P[where[i]],P[N]);
            
            where[i]=N;
            where[b]=a;
            
            int c=P[i];
            
            swap(P[N],P[i]);
            
            where[i]=i;
            where[c]=N;
            
        }else{
            if(i==1){
                if(where[i]!=1){
                    ans.push_back({where[i],1});
                    int a=P[1],b=where[i];
                    
                    swap(P[where[i]],P[1]);
                    
                    where[a]=b;
                    where[i]=1;
                }
                continue;
            }
            
            if(where[i]==N){
                ans.push_back({where[i],i});
                int a=P[i],b=where[i];
                
                swap(P[where[i]],P[i]);
                
                where[a]=b;
                where[i]=i;
                
                continue;
            }
            ans.push_back({where[i],1});
            ans.push_back({1,N});
            ans.push_back({N,i});
            
            int a=P[1],b=i,c=P[N],d=P[i],e=where[i];
            
            swap(P[where[i]],P[1]);
            swap(P[1],P[N]);
            swap(P[N],P[i]);
            
            where[a]=e;
            where[b]=i;
            where[c]=1;
            where[d]=N;
        }
    }
    
    for(int i=N/2+1;i<=N;i++){
        
        if(i==N){
            if(where[i]==i) continue;
            else ans.push_back({1,N});
        }else if(where[i]==1){
                ans.push_back({1,i});
          //ans.push_back({0,0});
          int a=P[i];
                swap(P[1],P[i]);
                
                where[a]=1;
                where[i]=i;
            }else{
            
            if(where[i]==i) continue;
            
            ans.push_back({where[i],1});
            ans.push_back({1,i});
            
            int a=P[1],b=i,c=P[i],d=where[i];
            
            swap(P[where[i]],P[1]);
            swap(P[1],P[i]);
            
            where[a]=d;
            where[b]=i;
            where[c]=1;
            
          //ans.push_back({0,0});
        }
      
    }
    
    cout<<ans.size()<<endl;
    
    for(pair<int,int> a:ans) cout<<a.first<<" "<<a.second<<"\n";
    
    /*for(int i=0;i<ans.size();i++){
        int a=ans[i].first,b=ans[i].second;
        swap(copy[a],copy[b]);
    }*/
    
    //for(int a:copy) cout<<a<<" ";
}