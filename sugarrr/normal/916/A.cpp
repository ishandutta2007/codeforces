


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
int mod(ll a){
    int c=a%1000000007;
    if(c>=0)return c;
    else return c+1000000007;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
#define inf 100000000/*10^8*/

/////////////////////////////////

bool check(int h,int m){
    bool flag=false;
    if(m%10==7)flag=true;
    else if(h%10==7)flag=true;
    return flag;
}

int main(){
    int x;cin>>x;
    int h,m;cin>>h>>m;
    int count=0;
    while(!check(h,m)){
        count++;
        if(m<x){
            if(h>0)h--;
            else h=23;
            m+=60;
        }
        m-=x;
    }
    cout<<count<<endl;
    return 0;
}