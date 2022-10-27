#include <iostream>
#include <vector>
using namespace std;
const int N=128;
int n,x;
vector<double> p(128,0);
vector<double> mul(vector<double> A, vector<double> B) {
    vector<double> C(128,0);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            C[i^j] += A[i]*B[j];
    return C;
}
vector<double> get(int a){
    if(a==1) return p;
    vector<double> v=get(a/2);
    vector<double> r=mul(v,v);
    if(a%2) r=mul(r,p);
    return r;
}
int main() {
    scanf("%d%d",&n,&x);
    for(int i=0;i<=x;i++) scanf("%lf",&p[i]);
    printf("%.12f\n", 1-get(n)[0]);
}