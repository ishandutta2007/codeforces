#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

struct data{
    int from;
    int to;
    ll cost;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<int,ll>> sum(N);
    for(int i=0;i<N;i++) sum[i].first=i;
    for(int i=0;i<M;i++){
        int a,b;ll c;cin>>a>>b>>c;
        a--;b--;
        sum[a].second-=c;
        sum[b].second+=c;
    }
    
    sort(all(sum),[](pair<int,ll> a,pair<int,ll> b){
        return a.second<b.second;
    });
    
    vector<data> ans;
    
    int left=0,right=N-1;
    
    if(sum[left].second==0&&sum[right].second==0){
        cout<<0<<endl;
        return 0;
    }
    
    while(1){
        while(left<N&&sum[left].second==0) left++;
        if(left==N) break;
        
        while(right>=0&&sum[right].second==0) right--;
        if(right==-1) break;
        
        if(abs(sum[left].second)>=abs(sum[right].second)){
            ans.push_back({sum[left].first,sum[right].first,sum[right].second});
            sum[left].second+=sum[right].second;
            sum[right].second=0;
        }else{
            ans.push_back({sum[left].first,sum[right].first,abs(sum[left].second)});
            sum[right].second-=abs(sum[left].second);
            sum[left].second=0;
        }
    }
    
    cout<<ans.size()<<endl;
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].from+1<<" "<<ans[i].to+1<<" "<<ans[i].cost<<endl;
    }
}