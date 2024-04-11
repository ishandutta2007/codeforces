#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 ll;
struct item{
    int num;
    int pos;
}p[100+2];
bool cmp(item a,item b){
    return a.num<b.num;
}
int main(){
    int m,n,k;cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>p[i].num;
        p[i].pos=i;
    }
    sort(p+1,p+1+k,cmp);
    ll res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;cin>>a;
            res+=p[a].pos;
            for(int tmp=1;tmp<=k;tmp++){
                if(p[tmp].pos<p[a].pos) p[tmp].pos++;
            }
            p[a].pos=1;
        }
    }
    cout<<res<<endl;
    return 0;
}