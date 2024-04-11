#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef long double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
bool eq(int i,int p1,int p2,int p3,int p4){
    return i==((((i%p1)%p2)%p3)%p4);
}
void solve(){
    int p1,p2,p3,p4,a,b,s=0;
    cin>>p1>>p2>>p3>>p4>>a>>b;
    for(int i=a;i<=b;++i){
        int c=0;
        if(eq(i,p1,p2,p3,p4))
            ++c;
        if(eq(i,p1,p2,p4,p3))
            ++c;
        if(eq(i,p1,p3,p2,p4))
            ++c;
        if(eq(i,p1,p3,p4,p2))
            ++c;
        if(eq(i,p1,p4,p2,p3))
            ++c;
        if(eq(i,p1,p4,p3,p2))
            ++c;
        if(eq(i,p2,p1,p3,p4))
            ++c;
        if(eq(i,p2,p1,p4,p3))
            ++c;
        if(eq(i,p2,p3,p1,p4))
            ++c;
        if(eq(i,p2,p3,p4,p1))
            ++c;
        if(eq(i,p2,p4,p1,p3))
            ++c;
        if(eq(i,p2,p4,p3,p1))
            ++c;
        if(eq(i,p3,p1,p2,p4))
            ++c;
        if(eq(i,p3,p1,p4,p2))
            ++c;
        if(eq(i,p3,p2,p1,p4))
            ++c;
        if(eq(i,p3,p2,p4,p1))
            ++c;
        if(eq(i,p3,p4,p1,p2))
            ++c;
        if(eq(i,p3,p4,p2,p1))
            ++c;
        if(eq(i,p4,p1,p2,p3))
            ++c;
        if(eq(i,p4,p1,p3,p2))
            ++c;
        if(eq(i,p4,p2,p1,p3))
            ++c;
        if(eq(i,p4,p2,p3,p1))
            ++c;
        if(eq(i,p4,p3,p1,p2))
            ++c;
        if(eq(i,p4,p3,p2,p1))
            ++c;
        if(c>=7){
            ++s;
        }
    }
    cout<<s;
}