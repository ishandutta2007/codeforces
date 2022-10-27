#include <iostream>
using namespace std;
typedef long long LL;
int t,n,a,b,k;
int c1,v1;
int c2,v2;
int main(){
    cin>>t>>n>>a>>b>>k;
    if(k>n)return !printf("0\n");
    if(n==1){
        printf("%d\n", min(a,t));return 0;
    }
    if(a>b) {
        c1=(n+1)/2; v1=a;
        c2=(n)/2; v2=b;
    } else {
        c1=(n)/2; v1=b;
        c2=(n+1)/2; v2=a;
    }
    if(k<=c1 || v1-v2<=1) {
        LL tot = 1LL*c1*v1+1LL*c2*v2;
        cout<<min(tot/k,t*1LL)<<endl; return 0;
    } else {
        LL x1=c1,x2=k-c1;
        LL L=0,R=min(1LL*c1*v1/x1, 1LL*c2*v2/x2);
        //printf("c2=%d,v2=%d,x2=%d,R=%d\n", c2,v2,x2,R);
        while(R-L>1) {
            LL h1,h2,k1,k2;
            LL mid=(L+R)>>1;
            h1=(1LL*c1*v1-x1*mid) / c1; h2 = (1LL*c1*v1-x1*mid +c1-1) / c1;
            k1=(1LL*c2*v2-x2*mid) / c2; k2 = (1LL*c2*v2-x2*mid +c2-1) / c2;
            //printf("mid=%d, %d %d %d %d\n", mid, h1,h2,k1,k2);
            if(h2<=k2) R=mid;
            else L=mid;
        }
        LL ans = R;

        //printf("R=%d\n", R);
        LL h1 = (1LL*c1*v1-x1*R) / c1;
        LL k2 = (1LL*c2*v2-x2*R +c2-1) / c2; //cout<<k2<<endl;
        //cout<<h1<<" "<<k2<<endl;
        if(k2==h1||k2==h1+1) ans = R + (1LL*c1*v1+1LL*c2*v2 - x1*R - x2*R) / (k);
        cout<<min(ans,t*1LL)<<endl;
    }
}