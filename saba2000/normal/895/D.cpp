#include<bits/stdc++.h>
#define N 10000
#define Pii pair<long long,long long>
#define S second
#define F first
#define testN 1
using namespace std;
long long M=1000000007;
long long f(long long a)
{long long b=M-2,c=M,k,ans=1;

while(b>0)
{long long p=1,k=a;
while((p*2)<=b){p*=2;
k=k*k%c; }
ans=ans*k%c;
b-=p;}
return ans;
}
long long fact[2000009],ifact[1000009];
long long inv[2000009];
long long F[1009];
long long F1[1009];
main()
{
    fact[0]=1;
   for (long long i=1; i<=2000000; i++)
    {fact[i]=(fact[i-1]*i)%M;
  //  ifact[i]=ifact[i-1]*(f(i))%M;
    }
    string a,b;
    cin>>a>>b;

    string c="",d="";
    long long W=0;
    while(a[W]==b[W]) W++;
    for (long long i=W; i<a.size(); i++)
        c+=a[i],d+=b[i];
    a=c;b=d;
    for (long long i=0; i<a.size(); i++)
        F[a[i]]++,
        F1[a[i]]++;
        long long Al=1,Al1;
    for (long long j='a'; j<='z'; j++)
        Al=(Al*f(fact[F[j]])%M);
        Al1=Al;
    long long ans=0,a1=0,a2=0;
    long long cb=1;
   for (long long j=a[0]+1; j<b[0]; j++)
    ans=(ans+fact[a.size()-1]*Al%M*F[j])%M;
   a1=(Al*F[a[0]])%M;
   a2=(Al*F[b[0]])%M;
   F[a[0]]--;
   if(F1[b[0]]>0) F1[b[0]]--;
   else cb=0;
    for (long long i=1; i<a.size(); i++)
        {
            for (long long j=a[i]+1; j<='z'; j++)
                ans=(ans+a1*fact[a.size()-i-1]%M*F[j])%M;
            a1=(a1*F[a[i]])%M;
            F[a[i]]--;
             if(cb){for (long long j='a'; j<b[i]; j++)
                ans=(ans+a2*fact[a.size()-i-1]%M*F1[j])%M;
            a2=(a2*F1[b[i]])%M;
            F1[b[i]]--;
            if(F1[b[i]]<0) cb=0;}
        }
    cout<<ans<<endl;
}