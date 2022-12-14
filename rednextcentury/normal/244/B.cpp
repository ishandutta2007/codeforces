#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int ret=0;
int x,y;
int len;
void bt(int i,ll val, bool A=0, bool B=0){
    if (i==len){
        if (val<=n && A && B)ret++;
    } else{
        if (i!=0 || x!=0)
        bt(i+1, val*10+x, 1, B);
        if (i!=0 || y!=0)
        bt(i+1,val*10+y, A, 1);
    }
}
void bt2(int i,ll val){
    if (i==len){
        if (val<=n)ret++;
    } else{
        bt2(i+1, val*10+x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;

    for (len=1;len<=10;len++){
        for (x=0;x<=9;x++){
            if (x)
            bt2(0,0);
            for (y=x+1;y<=9;y++)bt(0,0);
        }
    }
    cout<<ret<<endl;
}