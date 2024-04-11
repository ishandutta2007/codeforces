
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define PB push_back

typedef long long ll;

using namespace std;

const int mod=1000000007;
ll fact[100100];
ll fact1[100100];
int f(int l){
    int x=l;
    int m=0;
    while (x)
    {m++; x/=10;}
    int res=(1<<m)-2;
    FOR(i,0,m){
               if (l%10==7) res+=(1<<i);
               l/=10;
    } 
    return res;
}

ll pow(int n,int k){
           if (k==0) return 1;
           if (k%2==1) return (n*(pow(n,k-1)) % mod);
           else{
                ll q=pow(n,k/2); 
                return (q*q % mod);
           }
}

ll c(int n,int k){
         if (k>n || k<0) return 0;
         return (((fact[n]*fact1[k]) % mod)*fact1[n-k]) % mod;
}

int main()
{
    fact[0]=1;
    FOR(i,1,100100)
    fact[i]=(i*fact[i-1]) % mod;
    fact1[0]=1;
    FOR(i,1,100100)
    fact1[i]=pow(fact[i],mod-2);
    int n,k,l,m;
    int a[10000];
    int b=0;
    memset(a,0,sizeof(a));
    cin >> n >> k;
    FOR(i,0,n){
               cin >> l;
               bool q=1;
               int x=l;
               while (x)
               {
                     if (x%10!=4 && x%10 != 7 && q) {b++;q=0;}
                     x/=10;
               }
               if (q) a[f(l)]++;
    }
    vector <ll> d;
    FOR(i,0,1025)
    if (a[i]) d.PB(a[i]);
    if (d.size()+b<k) {cout<<0;return 0;}
    if (d.size()==0) {cout << c(b,k); return 0;}
        ll **dp=new ll*[1100];
    FOR(i,0,1100)
    dp[i]=new ll[1100];
    FOR(i,0,1100)
    FOR(j,0,1100)
    dp[i][j]=0;
    FOR(i,0,d.size())
    dp[i][0]=1;
    dp[0][1]=d[0];
    FOR(i,1,d.size())
    FOR(j,1,i+2)
    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*d[i]) % mod;
    ll res=0;
    FOR(i,0,d.size()+1)
    {
                       res+=dp[d.size()-1][i]*c(b,k-i);
                       res%=mod;
    }
    cout << res;
    //system("pause");
    return 0;
}