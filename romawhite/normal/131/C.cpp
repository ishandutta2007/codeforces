    #include <cstdlib>
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
typedef vector<int> lnum;
const int base = 1000*1000*1000;

void print(lnum a){
     printf ("%d", a.empty() ? 0 : a.back());
for (int i=(int)a.size()-2; i>=0; --i)
    printf ("%09d", a[i]);
}

lnum add(lnum a,lnum b){
     int carry = 0;
for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
    if (i == a.size())
        a.push_back (0);
    a[i] += carry + (i < b.size() ? b[i] : 0);
    carry = a[i] >= base;
    if (carry)  a[i] -= base;
}
return a;
}

lnum mult(lnum a,int b){
     int carry = 0;
for (size_t i=0; i<a.size() || carry; ++i) {
    if (i == a.size())
        a.push_back (0);
    long long cur = carry + a[i] * 1ll * b;
    a[i] = int (cur % base);
    carry = int (cur / base);
}
while (a.size() > 1 && a.back() == 0)
    a.pop_back();
    return a;
}

lnum div1(lnum a,int b){
     int carry = 0;
for (int i=(int)a.size()-1; i>=0; --i) {
    long long cur = a[i] + carry * 1ll * base;
    a[i] = int (cur / b);
    carry = int (cur % b);
}
while (a.size() > 1 && a.back() == 0)
    a.pop_back();
    return a;
}

lnum read(string s){
     lnum a;
     for (int i=(int)s.length(); i>0; i-=9)
    if (i < 9)
        a.push_back (atoi (s.substr (0, i).c_str()));
    else
        a.push_back (atoi (s.substr (i-9, 9).c_str()));
        return a;
    }

    lnum c(int n,int k){
             lnum res=read("1");
                  FOR(i,n-k+1,n+1)
                  res=mult(res,i);
                  FOR(i,1,k+1)
                  res=div1(res,i);
              return res;
              }
              
    lnum mul(lnum a,lnum b){
         lnum c (a.size()+b.size());
for (size_t i=0; i<a.size(); ++i)
    for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
        long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
        c[i+j] = int (cur % base);
        carry = int (cur / base);
    }
while (c.size() > 1 && c.back() == 0)
    c.pop_back();
    return c;
}

    int main(){
        int n,t,k,l,m;
        cin>>n>>m>>t;
        //cout<<c(n,m);
        lnum res1=read("0");
        FOR(i,4,t)
        res1=add(res1,mul(c(n,i),c(m,t-i)));
        print(res1);
        //system("pause");
        return 0;
    }