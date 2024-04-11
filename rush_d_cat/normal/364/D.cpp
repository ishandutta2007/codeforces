#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N=1000000+10;
int n; LL a[N];
int mp1[2][N],mp2[2][N];

LL res=0;
LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}
vector<LL> getFac(LL x){
    vector<LL> v;
    for(LL g=1;g*g<=x;g++){
        if(x%g==0){
            v.push_back(g);
            if(g*g!=x) v.push_back(x/g);
        }
    }
    sort(v.begin(),v.end());
    return v;
}

void upd(LL x){
    for(int i=1;i<=n;i++){
        LL g=gcd(x,a[i]);
        if(g<=1000000 && g*g <= x)
            mp1[0][g]++;
        else {
            mp1[1][x/g]++;
        }
    }

    vector<LL> v=getFac(x);
    
    for(int i=0;i<v.size();i++) {
        for(int j=i;j<v.size();j++)
            if(v[j]%v[i]==0){
                LL dt = (v[j]>1e6||v[j]*v[j]>x)?mp1[1][x/v[j]]:mp1[0][v[j]];
                if(v[i]<=1e6 && v[i]*v[i]<=x){
                    mp2[0][v[i]] += dt;
                } else {
                    mp2[1][x/v[i]] += dt;
                }
            }
    }

    for(auto d: v){
        if(d<=1e6 && d*d<=x) {
            if(mp2[0][d]*2>=n) res=max(res,d);
            mp2[0][d]=0;mp1[0][d]=0;
        } else {
            if(mp2[1][x/d]*2>=n) res=max(res,d);
            mp2[1][x/d]=0;mp1[1][x/d]=0;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);

    for(int i=1;i<=10;i++){
        upd(a[1LL*rand()*rand()%n+1]);
    }
    cout<<res<<endl;
}