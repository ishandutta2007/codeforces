#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
LL min(LL a, LL b) {return a<b?a:b;}
const LL N=400000+10;
LL n,x,a[N];
const double PI = acos(-1);
struct Complex {
    double x, y;
    Complex(double x=0.0, double y=0.0) : x(x), y(y) {}
    Complex operator + (const Complex &b) const {
        return Complex(x+b.x, y+b.y);
    }
    Complex operator - (const Complex &b) const {
        return Complex(x-b.x, y-b.y);
    }
    Complex operator * (const Complex &b) const{
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
} x1[N<<2], x2[N<<2];
void change(Complex y[], LL len) {
    for(LL i=1,j=len/2;i<len-1;i++){
        if(i<j) swap(y[i], y[j]);
        LL k=len/2;
        while (j>=k) {
            j-=k; k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft(Complex y[], LL len, LL on){
    change(y, len);
    for(LL h=2;h<=len;h<<=1) {
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for(LL j=0;j<len;j+=h){
            Complex w(1,0);
            for(LL k=j;k<j+h/2;k++) {
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if (on==-1)
        for(LL i=0;i<len;i++) y[i].x /= len;
}

void mul(LL *p, LL& dp, LL* q, LL& dq) {
    LL len=1;
    while(len<=dp+dq) len<<=1;
    for(LL i=0;i<dp;i++) 
        x1[i]=Complex(p[i],0);
    for(LL i=dp;i<len;i++)
        x1[i]=Complex(0,0);
    for(LL i=0;i<dq;i++)
        x2[i]=Complex(q[i],0);
    for(LL i=dq;i<len;i++)
        x2[i]=Complex(0,0);
    fft(x1,len,1);
    fft(x2,len,1);
    for(LL i=0;i<len;i++)
        x1[i]=x1[i]*x2[i];
    fft(x1,len,-1);
    for(LL i=0;i<dp+dq;i++) {
        p[i]=(LL)(x1[i].x+0.5);

    }
    dp+=dq;
}

vector<LL> v;
LL p[N], dp=0;
LL q[N], dq=0;
int main() {
    scanf("%lld%lld",&n,&x);
    v.push_back(0);
    vector<LL> ret; ret.push_back(0);
    LL cnt=0;

    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<x) {
            a[i]=1, v.push_back(i);
            ret[0] += cnt*(cnt+1)/2;
            cnt = 0;
        } else {
            a[i]=0;
            cnt ++;
        }
    }   
    ret[0] += cnt*(cnt+1)/2;
    v.push_back(n+1);

    for(LL i=0;i<(int)v.size()-1;i++)  
        p[dp++] = v[i+1]-v[i];
    for(LL i=(int)v.size()-2;i>=0;i--)
        q[dq++] = v[i+1]-v[i];


    mul(p,dp,q,dq);
    /*
    for(LL i=0;i<dp;i++)
        printf("%lld ", p[i]); printf("\n");
    */
    for(LL i=dq;i<dp;i++) {
        //printf("%lld ", p[i]);
        ret.push_back(p[i]);
    }
    //printf("ok\n");
    for(LL i=0;i<min((int)ret.size(),n+1);i++) {
        printf("%lld ", ret[i]);
    }
    for(LL i=ret.size();i<=n;i++)
        printf("0 ");
    printf("\n");
}