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
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    map<int,int> ma;
    for(int i=0;i<N;i++) ma[A[i]]++;
    vector<pair<int,int>> siz;
    for(auto it=ma.begin();it!=ma.end();it++){
        siz.push_back({ma[(*it).first],(*it).first});
    }
    sort(all(siz));
    int M=siz.size();
    vector<int> sum(M+1);
    for(int i=1;i<=M;i++) sum[i]=sum[i-1]+siz[i-1].first;
    
    int ans=0,x=0,y=0,anscnt=0;
    
    for(int i=1;i*i<=N;i++){
        int cnt=siz.end()-lower_bound(all(siz),make_pair(i,-1));
        if(sum[(M-cnt)]+i*cnt>=i*i){
            //cout<<sum[(M-cnt)]+i*cnt<<endl;
            if(ans<(sum[(M-cnt)]+i*cnt)/i*i){
                ans=(sum[(M-cnt)]+i*cnt)/i*i;
                anscnt=cnt;
                x=i;
                y=ans/x;
            }
        }
    }
    cout<<ans<<endl;
    cout<<x<<" "<<y<<endl;
    
    vector<vector<int>> res(x,vector<int>(y));
    for(int j=0;j<anscnt;j++){
        for(int i=0;i<x;i++){
            res[i][(i+j)%y]=siz[M-1-j].second;
        }
    }
    
    vector<int> use;
    for(int i=0;i<M-anscnt;i++){
        for(int j=0;j<siz[i].first;j++){
            use.push_back(siz[i].second);
        }
    }
    int now=0;
    
    for(int j=anscnt;j<y;j++){
        for(int i=0;i<x;i++){
            res[i][(i+j)%y]=use[now];
            now++;
        }
    }
    
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}