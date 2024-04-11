#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
struct amul{
    string s;
    amul(){}
    void fill(char a,char b,char c,char d){
        char A[3],B[3],C[3],D[3];
        A[0]=a;A[1]=0;
        B[0]=b;B[1]=0;
        C[0]=c;C[1]=0;
        D[0]=d;D[1]=0;
        s= min(min(string(A)+B+C+D,string(B)+C+D+A),min(string(C)+D+A+B,string(D)+A+B+C));
    }
    bool operator<(const amul&x)const{
        return s<x.s;
    }
    bool operator ==(const amul&x)const{
        return s==x.s;
    }
};
int main() {
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    int n;
    amul am[1111];
    cin>>n;
    for(int i=0;i<n;++i){
        char a,b,c,d;
        char s[10];
        cin>>a>>b>>c>>d;
        if(i!=n-1)
            cin>>s;
        am[i].fill(a,b,d,c);
    }
    sort(am,am+n);
    cout<<unique(am,am+n)-am;
    return 0;
}