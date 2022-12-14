#include <bits/stdc++.h>
#define pii pair<long long ,long long >
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair

using namespace std;

const long long  N = 1e5+10,mod = 998244353;

namespace fft
{
    struct num
    {
        double x,y;
        num() {x=y=0;}
        num(double x,double y):x(x),y(y){}
    };
    inline num operator+(num a,num b) {return num(a.x+b.x,a.y+b.y);}
    inline num operator-(num a,num b) {return num(a.x-b.x,a.y-b.y);}
    inline num operator*(num a,num b) {return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
    inline num conj(num a) {return num(a.x,-a.y);}

    long long  base=1;
    vector<num> roots={{0,0},{1,0}};
    vector<long long > rev={0,1};
    const double PI=acosl(-1.0);

    void ensure_base(long long  nbase)
    {
        if(nbase<=base) return;
        rev.resize(1<<nbase);
        for(long long  i=0;i<(1<<nbase);i++)
            rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
        roots.resize(1<<nbase);
        while(base<nbase)
        {
            double angle=2*PI/(1<<(base+1));
            for(long long  i=1<<(base-1);i<(1<<base);i++)
            {
                roots[i<<1]=roots[i];
                double angle_i=angle*(2*i+1-(1<<base));
                roots[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
            }
            base++;
        }
    }

    void fft(vector<num> &a,long long  n=-1)
    {
        if(n==-1) n=a.size();
        assert((n&(n-1))==0);
        long long  zeros=__builtin_ctz(n);
        ensure_base(zeros);
        long long  shift=base-zeros;
        for(long long  i=0;i<n;i++)
            if(i<(rev[i]>>shift))
                swap(a[i],a[rev[i]>>shift]);
        for(long long  k=1;k<n;k<<=1)
        {
            for(long long  i=0;i<n;i+=2*k)
            {
                for(long long  j=0;j<k;j++)
                {
                    num z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }

    vector<num> fa,fb;

    vector<long long > multiply(vector<long long > &a, vector<long long > &b)
    {
        long long  need=a.size()+b.size()-1;
        long long  nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        long long  sz=1<<nbase;
        if(sz>(long long )fa.size()) fa.resize(sz);
        for(long long  i=0;i<sz;i++)
        {
            long long  x=(i<(long long )a.size()?a[i]:0);
            long long  y=(i<(long long )b.size()?b[i]:0);
            fa[i]=num(x,y);
        }
        fft(fa,sz);
        num r(0,-0.25/sz);
        for(long long  i=0;i<=(sz>>1);i++)
        {
            long long  j=(sz-i)&(sz-1);
            num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
            if(i!=j) fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
            fa[i]=z;
        }
        fft(fa,sz);
        vector<long long > res(need);
        for(long long  i=0;i<need;i++) res[i]=fa[i].x+0.5;
        return res;
    }

    vector<long long > multiply_mod(vector<long long > &a,vector<long long > &b,long long  m,long long  eq=0)
    {
        long long  need=a.size()+b.size()-1;
        long long  nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        long long  sz=1<<nbase;
        if(sz>(long long )fa.size()) fa.resize(sz);
        for(long long  i=0;i<(long long )a.size();i++)
        {
            long long  x=(a[i]%m+m)%m;
            fa[i]=num(x&((1<<15)-1),x>>15);
        }
        fill(fa.begin()+a.size(),fa.begin()+sz,num{0,0});
        fft(fa,sz);
        if(sz>(long long )fb.size()) fb.resize(sz);
        if(eq) copy(fa.begin(),fa.begin()+sz,fb.begin());
        else
        {
            for(long long  i=0;i<(long long )b.size();i++)
            {
                long long  x=(b[i]%m+m)%m;
                fb[i]=num(x&((1<<15)-1),x>>15);
            }
            fill(fb.begin()+b.size(),fb.begin()+sz,num{0,0});
            fft(fb,sz);
        }
        double ratio=0.25/sz;
        num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
        for(long long  i=0;i<=(sz>>1);i++)
        {
            long long  j=(sz-i)&(sz-1);
            num a1=(fa[i]+conj(fa[j]));
            num a2=(fa[i]-conj(fa[j]))*r2;
            num b1=(fb[i]+conj(fb[j]))*r3;
            num b2=(fb[i]-conj(fb[j]))*r4;
            if(i!=j)
            {
                num c1=(fa[j]+conj(fa[i]));
                num c2=(fa[j]-conj(fa[i]))*r2;
                num d1=(fb[j]+conj(fb[i]))*r3;
                num d2=(fb[j]-conj(fb[i]))*r4;
                fa[i]=c1*d1+c2*d2*r5;
                fb[i]=c1*d2+c2*d1;
            }
            fa[j]=a1*b1+a2*b2*r5;
            fb[j]=a1*b2+a2*b1;
        }
        fft(fa,sz);fft(fb,sz);
        vector<long long > res(need);
        for(long long  i=0;i<need;i++)
        {
            ll aa=fa[i].x+0.5;
            ll bb=fb[i].x+0.5;
            ll cc=fa[i].y+0.5;
            res[i]=(aa+((bb%m)<<15)+((cc%m)<<30))%m;
        }
        return res;
    }
    vector<long long > square_mod(vector<long long > &a,long long  m)
    {
        return multiply_mod(a,a,m,1);
    }
};
vector<long long > P(vector<long long > a,long long  k)
{
    if (k==1)
        return a;
    vector<long long > b = P(a,k/2);
    b = fft::multiply_mod(b,b,mod);
    if (k%2)
        b = fft::multiply_mod(a,b,mod);
    return b;
}
long long  p[1000000];
int  main()
{
    ios_base::sync_with_stdio(0);
    long long  n,x;
    cin>>n>>x;
    for (long long  i=0;i<n;i++)
    {
        cin>>p[i];
        if (p[i]<x)p[i]=1;
        else p[i]=0;
        if (i>0)p[i]+=p[i-1];
    }
    vector<long long > a(n+1);
    vector<long long > b(n+1);
    a[0]++;
    b[n]++;
    for (long long  i=0;i<n;i++)
        a[p[i]]++,b[n-p[i]]++;
    long long ret=0;
    for (long long  i=0;i<a.size();i++)
        ret+=(a[i]*1LL*(a[i]-1))/2;
    cout<<ret;
    a = fft::multiply(a,b);
    for (long long  i=n-1;i>=0;i--)
        cout<<' '<<a[i];
}