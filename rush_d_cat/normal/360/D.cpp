#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long LL;

const int N=100000+10;
vector<int> vec;
set<int> st;
map<int,int> cof,nex;

int n,m,p;
int a[N],b[N],r[N],cnt[N];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y){
    if(x==0) return y;
    if(y==0) return x;
    return (LL)x*y/gcd(x,y);
}
int mpow(int a,int x){
    if(x==0)return 1;
    int t=mpow(a,x>>1);
    if(x%2==0) return 1LL*t*t%p;
    return 1LL*t*t%p*a%p;
}

int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]),b[i]=gcd(b[i], p-1);

    int t=p-1; for(int i=1;i<=n;i++) t=gcd(t,b[i]);
    // (g^t) ^ (r[i]*k)  
    // (g^t) ^ (k*r[i]) 

    for(int i=1;i*i<=(p-1);i++){
        if((p-1)%i == 0) {
            vec.push_back(i); vec.push_back((p-1)/i);
        }
    }

    sort(vec.begin(), vec.end());
    
    int T=(p-1)/t;
    for(int i=1;i<=n;i++) {
        for(auto x: vec) {
            if(mpow(a[i], x) == 1) {
                r[i] = (p-1)/x; break;
            }
        }
        r[i]=gcd(r[i],T);
        st.insert(r[i]);
        //printf("r[%d] = %d\n", i, r[i]);
    }


    for(auto x: vec) cof[x]=0; cof[0]=-1;
    for(auto x: st) {
        nex=cof;
        for(auto p: cof) {
            //printf("(%d, %d)\n", p.first, p.second);
            nex[lcm(x, p.first)] -= p.second;
        }
        cof=nex;
    }
    int ans=0;
    for(auto p: cof){
        if(p.first) {
            //printf("[%d, %d]\n", p.first,p.second);
            ans=ans+1LL* T/p.first * p.second;
        }
    }
    cout<<ans<<endl;
}