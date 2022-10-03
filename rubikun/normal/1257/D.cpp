#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=300003,INF=1<<30;

int n;
ll dat[2*MAX-1];

void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
    }
}

void update(int k,ll a){
    k+=n-1;
    dat[k]=a;
    
    while(k>0){
        k=(k-1)/2;
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
}

ll query(int a,int b,int k,int l,int r){
    
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return dat[k];
    else{
        ll vl=query(a,b,2*k+1,l,(l+r)/2);
        ll vr=query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
}


int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int N;cin>>N;
        init(N);
        for(int i=0;i<N;i++){
            int a;
            //cin>>a;
            scanf("%d",&a);
            update(i,a);
        }
        int M;cin>>M;
        vector<int> maxi(N+1,0);
        for(int i=0;i<M;i++){
            int p,s;
            //cin>>p>>s;
            scanf("%d%d",&p,&s);
            maxi[s]=max(maxi[s],p);
        }
        
        for(int i=N-1;i>=0;i--) maxi[i]=max(maxi[i],maxi[i+1]);
        
        int now=0,cnt=0;
        
        while(now<N){
            if(query(now,now+1,0,0,n)>maxi[1]){
                cnt=-1;
                break;
            }
            if(query(now,N,0,0,n)<=maxi[N-now]){
                cnt++;
                break;
            }
            int left=1,right=N-now;
            while(right-left>1){
                int mid=(left+right)/2;
                if(query(now,now+mid,0,0,n)>maxi[mid]) right=mid;
                else left=mid;
            }
            now+=left;
            cnt++;
        }
        
        cout<<cnt<<"\n";
        
        T--;
    }
    
}