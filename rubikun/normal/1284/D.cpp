#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod1=1000000007,mod2=1000000009,mod3=998244353,MAX=100005,INF=1<<30;
struct data{
    int left;
    int right;
    int id;
};

struct point{
    ll hash1;
    ll hash2;
    ll hash3;
    int id;
};

ll mm1[MAX],mm2[MAX],mm3[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    srand((unsigned int)time(NULL));
    ll N;cin>>N;
    vector<data> A(N),B(N);
    vector<point> C(N+1),D(N+1);
    for(int i=0;i<N;i++){
        cin>>A[i].left>>A[i].right;
        A[i].id=i;
        
        cin>>B[i].left>>B[i].right;
        B[i].id=i;
    }
    
    sort(all(A),[](data a,data b){
        if(a.left==b.left) return a.id<b.id;
        return a.left<b.left;
    });
    
    sort(all(B),[](data a,data b){
        if(a.left==b.left) return a.id<b.id;
        return a.left<b.left;
    });
    
    for(int i=0;i<N;i++) C[i].id=A[i].id;
    for(int i=0;i<N;i++) D[i].id=B[i].id;
    
    C[N].id=INF;
    D[N].id=INF;
    
    ll h1=rand(),h2=rand(),h3=rand();
    /*h1=1;
    h2=1;
    h3=1;*/
    
    mm1[0]=h1;
    mm2[0]=h2;
    mm3[0]=h3;
    
    for(int i=1;i<=N;i++){
        mm1[i]=mm1[i-1]*h1;
        mm1[i]%=mod1;
        
        mm2[i]=mm2[i-1]*h2;
        mm2[i]%=mod2;
        
        mm3[i]=mm3[i-1]*h3;
        mm3[i]%=mod3;
    }
    
    vector<ll> sum1(N+1),sum2(N+1),sum3(N+1);
    
    for(int i=N-1;i>=0;i--){
        sum1[i]=sum1[i+1]+mm1[A[i].id];
        sum2[i]=sum2[i+1]+mm2[A[i].id];
        sum3[i]=sum3[i+1]+mm3[A[i].id];
        
        sum1[i]%=mod1;
        sum2[i]%=mod2;
        sum3[i]%=mod3;
    }
    
    for(int i=0;i<N;i++){
        int l=0,r=N-1;
        if(A[i].right<A[0].left){
            C[0].hash1+=mm1[A[i].id];
            C[0].hash2+=mm2[A[i].id];
            C[0].hash3+=mm3[A[i].id];
            
            C[i].hash1+=sum1[0];
            C[i].hash2+=sum2[0];
            C[i].hash3+=sum3[0];
            
            C[i+1].hash1+=mod1-sum1[0];
            C[i+1].hash2+=mod2-sum2[0];
            C[i+1].hash3+=mod3-sum3[0];
            
            continue;
        }
        if(A[N-1].left<=A[i].right){
            continue;
        }
        while(r-l>1){
            int mid=(l+r)/2;
            if(A[i].right<A[mid].left) r=mid;
            else l=mid;
        }
        
        C[r].hash1+=mm1[A[i].id];
        C[r].hash2+=mm2[A[i].id];
        C[r].hash3+=mm3[A[i].id];
        
        C[i].hash1+=sum1[r];
        C[i].hash2+=sum2[r];
        C[i].hash3+=sum3[r];
        
        C[i+1].hash1+=mod1-sum1[r];
        C[i+1].hash2+=mod2-sum2[r];
        C[i+1].hash3+=mod3-sum3[r];
        
    }
    
    sum1[N]=0;
    sum2[N]=0;
    sum3[N]=0;
    
    for(int i=N-1;i>=0;i--){
        sum1[i]=sum1[i+1]+mm1[B[i].id];
        sum2[i]=sum2[i+1]+mm2[B[i].id];
        sum3[i]=sum3[i+1]+mm3[B[i].id];
        
        sum1[i]%=mod1;
        sum2[i]%=mod2;
        sum3[i]%=mod3;
    }
    
    for(int i=0;i<N;i++){
        int l=0,r=N-1;
        if(B[i].right<B[0].left){
            D[0].hash1+=mm1[B[i].id];
            D[0].hash2+=mm2[B[i].id];
            D[0].hash3+=mm3[B[i].id];
            
            D[i].hash1+=sum1[0];
            D[i].hash2+=sum2[0];
            D[i].hash3+=sum3[0];
            
            D[i+1].hash1+=mod1-sum1[0];
            D[i+1].hash2+=mod2-sum2[0];
            D[i+1].hash3+=mod3-sum3[0];
            
            continue;
        }
        if(B[N-1].left<=B[i].right){
            continue;
        }
        while(r-l>1){
            int mid=(l+r)/2;
            if(B[i].right<B[mid].left) r=mid;
            else l=mid;
        }
        
        D[r].hash1+=mm1[B[i].id];
        D[r].hash2+=mm2[B[i].id];
        D[r].hash3+=mm3[B[i].id];
        
        D[i].hash1+=sum1[r];
        D[i].hash2+=sum2[r];
        D[i].hash3+=sum3[r];
        
        D[i+1].hash1+=mod1-sum1[r];
        D[i+1].hash2+=mod2-sum2[r];
        D[i+1].hash3+=mod3-sum3[r];
    }
    
    C[0].hash1%=mod1;
    C[0].hash2%=mod2;
    C[0].hash3%=mod3;
    for(int i=1;i<=N;i++){
        C[i].hash1+=C[i-1].hash1;
        C[i].hash1%=mod1;
        
        C[i].hash2+=C[i-1].hash2;
        C[i].hash2%=mod2;
        
        C[i].hash3+=C[i-1].hash3;
        C[i].hash3%=mod3;
    }
    
    D[0].hash1%=mod1;
    D[0].hash2%=mod2;
    D[0].hash3%=mod3;
    for(int i=1;i<=N;i++){
        D[i].hash1+=D[i-1].hash1;
        D[i].hash1%=mod1;
        
        D[i].hash2+=D[i-1].hash2;
        D[i].hash2%=mod2;
        
        D[i].hash3+=D[i-1].hash3;
        D[i].hash3%=mod3;
    }
    
    sort(all(C),[](point a,point b){
        return a.id<b.id;
    });
    
    sort(all(D),[](point a,point b){
        return a.id<b.id;
    });
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        if(C[i].hash1!=D[i].hash1) ok=false;
        if(C[i].hash2!=D[i].hash2) ok=false;
        if(C[i].hash3!=D[i].hash3) ok=false;
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    //cout<<h1<<" "<<h2<<" "<<h3<<endl;
    
    /*for(int i=0;i<N;i++){
        cout<<C[i].hash1<<" "<<C[i].hash2<<" "<<C[i].hash3<<endl;
        cout<<D[i].hash1<<" "<<D[i].hash2<<" "<<D[i].hash3<<endl;
        cout<<endl;
    }*/
    
    //cout<<C[1].hash1<<" "<<C[1].hash2<<" "<<C[1].hash3<<endl;
}