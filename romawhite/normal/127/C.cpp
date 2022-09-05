    #include <iostream>
    #include <vector>
    #include <set>
    #include <cstdio>
    #include <cmath>
    #include <string>
    #include <algorithm>
    #include <map>

    using namespace std;

    #define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
    #define MP make_pair
    #define ALL(a) ((a).begin(),(a).end())
    #define PB push_back
    #define PII pair<int,int>

    typedef long long ll;
    typedef unsigned long long ull;
    int gcd(int a,int b){
        if (!b) return a;
        else return gcd(b,a%b);
    }

    int main(){
        int t0,a,b,c,d,t1,t2,y1,y2,x1,x2;
        cin>>t1>>t2>>x1>>x2>>t0;
        if (t0==t1 && t0==t2) {cout<<x1<<' '<<x2; return 0;}
        if (t0==t1) {cout<<x1<<' '<<0;return 0;}
        if (t0==t2) {cout<<0<<' '<<x2;return 0;}
        b=gcd(t0-t1,t2-t0);
        d=(t0-t1)/b;
        c=(t2-t0)/b;
        if (c<=x1 && d<=x2){
            a=min(x1/c,x2/d);
            cout<<a*c<<' '<<a*d;
            return 0;
        }
        int j;
        int m1=-1,m2=-1;
        long double e=20000000,q;
        FOR(i,1,x1+1)
        {
            j=((long double)d/c)*i;
            int h=j;
            if (j>x2) h=x2;
            q=((long double)t1*(long double)i+(long double)t2*(long double)h)/(i+h);
            if (q-(long double)t0<=e && q-(long double)t0>=0 && i+h>m1+m2) {m1=i;m2=h;e=q-(long double)t0;}
            if (j>=x2) h=x2-1;
            q=((long double)t1*i+(long double)t2*(h+1))/(i+h+1);
            if (q-(long double)t0<=e && q-(long double)t0>=0 && i+h+1>m1+m2) {m1=i;m2=h+1;e=q-(long double)t0;}
        }
        if (m1==-1) {cout<<0<<' '<<x2;return 0;}
        cout<<m1<<' '<<m2;
        //system("pause");
        return 0;
    }