#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19,INF=1<<30;

int bit[MAX+1],n;

//1-indexed

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

//st=sum(t)-sum(s-1)

void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}

vector<int> plu[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,Q;cin>>N>>M>>Q;
    vector<int> cnt(M);
    for(int i=0;i<N;i++){
        int a;cin>>a;
        a--;
        cnt[a]++;
    }
    n=M;
    
    vector<pair<ll,int>> S(Q);
    for(int i=0;i<Q;i++){
        cin>>S[i].first;
        S[i].second=i;
    }
    sort(all(S));
    
    for(int i=0;i<M;i++){
        plu[cnt[i]].push_back(i);
    }
    
    ll su=N,qid=0;
    
    for(int ti=0;ti<=N;ti++){
        for(int a:plu[ti]) add(a+1,1);
        
        while(qid<Q&&su+sum(M)>=S[qid].first){
            int left=0,right=M;
            while(right-left>1){
                int mid=(left+right)/2;
                if(su+sum(mid)>=S[qid].first) right=mid;
                else left=mid;
            }
            S[qid].first=right;
            qid++;
        }
        su+=sum(M);
    }
    
    while(qid<Q){
        S[qid].first=(S[qid].first-su-1)%M+1;
        qid++;
    }
    
    sort(all(S),[](pair<ll,int> a,pair<ll,int> b){
        return a.second<b.second;
    });
    
    for(int i=0;i<Q;i++){
        cout<<S[i].first<<"\n";
    }
    
    
}