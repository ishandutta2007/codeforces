#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
typedef __int64 ll;
ll x[2000+2];
ll y[2000+2];
ll q[4000000+2];
struct point{ll x;ll y;}p[4000000+2];
bool cmp(point a,point b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int main(){
    int n;
    cin>>n;
    if(n<=3){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int index=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            p[index].x=x[i]+x[j];
            p[index].y=y[i]+y[j];
            index++;
        }
    }
    sort(p,p+index,cmp);
    ll res=0;
    for(ll i=0;i<index-1;i++){
        if(p[i].x==p[i+1].x&&p[i].y==p[i+1].y){
            res++;
            ll tmp=i-1;
            while(p[tmp].x==p[i].x&&p[tmp].y==p[i].y){
                res++;
                tmp--;
                if(tmp<0) break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}