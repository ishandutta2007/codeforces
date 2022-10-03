#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<13,INF=1<<30;

int n;
int dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
    }
}

void add(int k,int a){
    k+=n-1;
    dat[k]+=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
}

int query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return dat[k];
    else{
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
}

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}


int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<pair<int,int>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i;
    }
    
    sort(all(A));
    int before=A[0].first;
    A[0].first=1;
    
    for(int i=1;i<N;i++){
        if(A[i].first==before) A[i].first=A[i-1].first;
        else{
            before=A[i].first;
            A[i].first=A[i-1].first+1;
        }
    }
    
    sort(all(A),compare);
    
    int ans=N;
    
    for(int l=0;l<N;l++){
        init(N);
        for(int j=0;j<N;j++){
            add(A[j].first,1);
        }
        for(int r=l;r<N;r++){
            if(query(0,N+1,0,0,n)<=1){
                ans=min(ans,r-l);
                break;
            }
            add(A[r].first,-1);
        }
        if(query(0,N+1,0,0,n)<=1){
            ans=min(ans,N-l);
        }
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}