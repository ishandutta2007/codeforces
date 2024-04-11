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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int pat[15][15];

void make(){
    pat[0][0]=1;
    for(int i=1;i<15;i++){
        for(int j=0;j<=i;j++){
            if(j) pat[i][j]+=pat[i-1][j-1];
            pat[i][j]+=pat[i-1][j];
        }
    }
}

int D,P,X=1,Y=2,G=1000,zero=3000,one=3001;

ll now[5005];

void add(int a,int b,int to){
    now[to]=(now[a]+now[b])%P;
    cout<<"+ "<<a<<" "<<b<<" "<<to<<endl;
}

void rui(int a,int to){
    now[to]=1;
    for(int i=0;i<D;i++){
        now[to]*=now[a];
        now[to]%=P;
    }
    cout<<"^ "<<a<<" "<<to<<endl;
}

void makezero(){
    for(int i=1;i<40;i++){
        add(2000+i-1,2000+i-1,2000+i);
    }
    //2000+i = 2^i
    
    for(ll t=2,i=1;t<=P;t*=2,i++){
        if(P&t) add(zero,2000+int(i),zero);
    }
}

void copy(int from,int to){
    add(from,zero,to);
}

void mul(int a,int b,int to){
    if(b==1) return;
    copy(a,4000);
    for(int i=1;i<40;i++){
        add(4000+i-1,4000+i-1,4000+i);
    }
    
    copy(zero,to);
    
    for(ll t=1,i=0;t<=b;t*=2,i++){
        if(b&t) add(to,4000+int(i),to);
    }
}

ll rui(ll a,ll b,ll P){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%P;
        a=a*a%P;
        b/=2;
    }
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    
    int xx,yy;
    cin>>D>>P>>xx>>yy;
    
    now[1]=xx;
    now[2]=yy;
    for(int i=3;i<=5000;i++) now[i]=1;
    
    makezero();
    
    //cout<<now[zero]<<" "<<now[one]<<endl;
    
    copy(zero,G);
    
    for(int cx=0;cx<=1;cx++){
        for(int cy=0;cy<=1;cy++){
            for(int cz=0;cz<=D-2;cz++){
                if(cx+cy+cz==0) continue;
                
                //cout<<endl;
                //cout<<cx<<" "<<cy<<" "<<cz<<endl;
                
                copy(zero,3);
                if(cx) add(3,X,3);
                if(cy) add(3,Y,3);
                for(int k=0;k<cz;k++) add(3,one,3);
                
                rui(3,3);
                mul(3,pat[D-2][cz],3);
                if((D-(cx+cy+cz))&1) mul(3,P-1,3);
                add(3,G,G);
                
                //cout<<now[G]<<endl;
            }
        }
    }
    
    ll x=1;
    for(int i=1;i<=D;i++){
        x*=i;
        x%=P;
    }
    x=rui(x,P-2,P);
    
    mul(G,x,G);
    
    cout<<"f "<<G<<endl;
    
    //cout<<now[1]<<" "<<now[2]<<" "<<now[G]<<endl;
}