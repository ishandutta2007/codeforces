#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<vector>
#define INF 2e9
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        long long n,m,k; cin>>n>>m>>k;
        if(n>m) swap(m,n);
        long long cnt=n;
        if( (m-n)%2==1 ){
            cnt+=m-n-1;
            k-=cnt;
            if(k<=0){ cout<<-1<<endl; }
            else{
                k-=1;
                cnt+=k;
                cout<<cnt<<endl;
            }
        }
        else{
            cnt+=m-n;
            k-=cnt;
            if( k<0 ) cout<<-1<<endl;
            else if( k==0 ) cout<<cnt<<endl;
            else{
                if(k%2==0) cout<<cnt+k<<endl;
                else{
                    if(k==1) cout<<cnt-1<<endl;
                    else cout<<cnt+k-2<<endl;
                }
            }
        }
    }
    return 0;
}