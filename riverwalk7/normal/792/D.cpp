#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef long long ll;
ll N;
int Q;
ll u;
string v;
ll v_2(ll num) {
    if(num==0) {
        return 10000;
    }
    if(num%2!=0) {
        return 0;
    }
    else {
        return v_2(num/2)+1;
    }
}
ll power(ll x) {
    if(x==0) {
        return 1;
    }
    else {
        return 2*power(x-1);
    }
}
ll next_node(ll cur, char x) {
    if(x=='U') {
        if(cur==(N+1)/2) {
            return cur;
        }
        if(v_2(cur + power(v_2(cur)))==(v_2(cur)+1)) {
            return cur+power(v_2(cur));
        }
        else {
            return cur-power(v_2(cur));
        }
    }
    if(x=='L') {
        if(v_2(cur)==0) {
            return cur;
        }
        else {
            return cur - power(v_2(cur/2));
        }
    }
    if(x=='R') {
        if(v_2(cur)==0) {
            return cur;
        }
        else {
            return cur + power(v_2(cur/2));
        }
    }
}
int main()
{
    cin>>N>>Q;
    for(int i=0; i<Q; i++) {
        cin>>u>>v;
        for(int j=0; j<v.length(); j++) {
            u = next_node(u, v[j]); 
        }
        cout<<u<<endl;
    }
}