#include<iostream>
using namespace std;
typedef __int64 ll;
int n,m;
int q[1000000+2];
int main(){
    bool flag=false;
    int res=0;
    cin>>n>>m;
    int minx=1000000+2,maxn=-1;
    memset(q,0,sizeof(q));
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        if(a>b)
        {
            int c=b;
            b=a;a=c;
        }
        q[a]=1;q[b]=2;
        if(b<=minx) minx=b;
        if(a>=maxn) maxn=a;
    }
    if(minx-maxn<=0){
        cout<<0<<endl;
    }else{
        if(m!=0){
            res=minx-maxn;
            cout<<res<<endl;
        }else{
            cout<<n-1<<endl;
        }
    }
    return 0;
}