#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int bit[MAX+1],N;

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
    while(i<=N){
        bit[i]+=x;
        i+=i&-i;
    }
}

struct query{
    int k;
    int pos;
    int id;
};

bool compare(query a,query b){
    return a.k<b.k;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin>>N;
    vector<int> A(N);
    priority_queue<pair<int,int>> PQ;
    
    for(int i=0;i<N;i++){
        //cin>>A[i];
        scanf("%d",&A[i]);
        PQ.push({A[i],-i});
    }
    
    int M;cin>>M;
    
    vector<query> Q(M);
    for(int i=0;i<M;i++){
        //cin>>Q[i].k>>Q[i].pos;
        scanf("%d%d",&Q[i].k,&Q[i].pos);
        Q[i].id=i;
    }
    
    sort(all(Q),compare);
    
    vector<int> ans(M);
    
    for(int i=0;i<M;i++){
        while(N-int(PQ.size())<Q[i].k){
            pair<int,int> p=PQ.top();PQ.pop();
            add(-p.second+1,1);
        }
        
        int left=0,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            int a=sum(mid);
            if(a>=Q[i].pos) right=mid;
            else left=mid;
        }
        
        //cout<<right<<" "<<Q[i].id<<endl;
        
        ans[Q[i].id]=A[right-1];
    }
    
    for(int i=0;i<M;i++){
        //cout<<ans[i]<<"\n";
        printf("%d\n",ans[i]);
    }
}