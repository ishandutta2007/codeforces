#include<bits/stdc++.h>
using namespace std;
long long v[10],p[10];
long long ans=-1;
long long M=1000000007;
long long f[19]={2,4,8,16,32,2000000000};
long long g[19]={1,2,4,8,16,32};
long long N[5],n;
bool Cs(long long A,long long b, long long c, long long d,long long e)
{long long a[5]={A*500+500,b*500+500,c*500+500,d*500+500,e*500+500};
long long P=0,V=0;
for (long long i=0; i<5; i++){
if(p[i]!=-1) P+=a[i]-p[i]*a[i]/250;
if (v[i]!=-1) V+=a[i]-v[i]*a[i]/250;
}
//cout<<V<<" "<<P<<endl;
return V>P;

}
//N/n>=1/f    n/N<=f N*F>=n
void S(long long A,long long b, long long c, long long d,long long e)
{long long a[5]={A,b,c,d,e};

long long p=0,q=100000007;
for (long long i=0; i<5; i++)
{if (N[i]==0) continue;
if(v[i]==-1) q=min(q,f[a[i]]*N[i]-n-1);      //N/(n+x)<=1/f  (n+x)/N>=f  n+x>=f*N xf*N-n
else if(N[i]*f[a[i]]<=n){p=max(p,(n-f[a[i]]*N[i]+f[a[i]]-1)/f[a[i]]); if((N[i]+p)*f[a[i]]<=n+p) p++; }  //3-2*1+ 1
if(N[i]*g[a[i]]>n){p=max(p,N[i]*g[a[i]]-n);}  
}             //N/n<=1/g n/N>=g n>=N*g   N*g<=n+x x>=N*g-x}
//if(A==0 && b==2 && c==1 && d==2 && e==5) cout<<p<<" "<<q<<endl;
if(p>q || Cs(A,b,c,d,e)==0) return;
//cout<<p<<endl;

//if(p==1) cout<<A<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<p<<" "<<q<<endl;
//system("pause");}
if(ans==-1) ans=p; else ans=min(ans,p);
}
int main()
{
cin>>n;
for (long long i=0; i<5; i++)
{cin>>v[i]; if (v[i]!=-1) N[i]++;}
for (long long i=0; i<5; i++)
{cin>>p[i]; if (p[i]!=-1) N[i]++;}
//cout<<N[3]<<endl;
for(long long i=0; i<n-2; i++)
for (long long j=0; j<5; j++)
{long long a; cin>>a;
if(a!=-1) N[j]++;}
//cout<<N[1]<<endl;
for(long long a=0; a<6; a++)
for (long long b=0; b<6; b++)
for (long long c=0; c<6; c++)
for (long long d=0; d<6; d++)
for (long long e=0; e<6; e++)
S(a,b,c,d,e);
cout<<ans<<endl; 

}

//
//3 10
//1 2
//(x-y)/(p-q)  
//
//a+1/ b+1>a/b  a<=b   1/2   2/3
//ab+b>ab+a
//a<b
//