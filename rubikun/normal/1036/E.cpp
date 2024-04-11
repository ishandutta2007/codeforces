#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=(((1<<30)-1)<<1)+1;

struct point{
    long double x;
    long double y;
};

bool intersect(point a,point b,point s,point t){
    if((((b.x-a.x)*(s.y-a.y)-(b.y-a.y)*(s.x-a.x))*((b.x-a.x)*(t.y-a.y)-(b.y-a.y)*(t.x-a.x)))<=0) return 1;
    else return 0;
}//1

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

point GetCrossPoint(point a,point b,point c,point d){
    point base={d.x-c.x,d.y-c.y};
    point vec1={a.x-c.x,a.y-c.y};
    point vec2={b.x-c.x,b.y-c.y};
    long double d1=abs(base.x*vec1.y-base.y*vec1.x),d2=abs(base.x*vec2.y-base.y*vec2.x);
    long double t=d1/(d1+d2);
    
    return {a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t};
}

const long double eps=1e-13;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    ll cnt=0;
    vector<point> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i].x>>A[i].y>>B[i].x>>B[i].y;
        ll d=gcd(ll(abs(B[i].x-A[i].x)),ll(abs(B[i].y-A[i].y)));
        cnt+=d+1;
    }
    
    //cout<<cnt<<endl;
    
    map<pair<ll,ll>,set<int>> MA;
    
    for(int i=0;i<N;i++){
        set<pair<ll,ll>> pre;
        for(int j=i+1;j<N;j++){
            if(intersect(A[i],B[i],A[j],B[j])&&intersect(A[j],B[j],A[i],B[i])){
                auto p=GetCrossPoint(A[i],B[i],A[j],B[j]);
                if(abs(p.x-floor(p.x+eps))<eps&&abs(p.y-floor(p.y+eps))<eps){
                    MA[{floor(p.x+eps),floor(p.y+eps)}].insert(i);
                    MA[{floor(p.x+eps),floor(p.y+eps)}].insert(j);
                }
            }
        }
    }
    
    for(auto it=MA.begin();it!=MA.end();it++){
        cnt-=((*it).second.size()-1);
    }
    
    cout<<cnt<<endl;
}