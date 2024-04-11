#include<bits/stdc++.h>
using namespace std;
double dplr[2009][2009],dprr[2009][2009],dprl[2009][2009],dpll[2009][2009];
double pll[2009][2009],prr[2009][2009],plr[2009][2009],prl[2009][2009];
int tl[2009],tr[2009];
int n;
double h;
double p;
double x[2009];
main()
{cin>>n>>h>>p;
for (int i=1;i<=n; i++)
cin>>x[i];
sort(x+1,x+n+1);
for(int i=1; i<=n; i++)
{tl[i]=i;
while(tl[i]>=2 && x[tl[i]-1]>x[tl[i]]-h) tl[i]--;
tr[i]=i;
while(tr[i]<=n-1 && x[tr[i]+1]<x[tr[i]]+h) tr[i]++;}
for(int i=1; i<=n; i++)
{dplr[i][i]=0;
dpll[i][i]=h;
dprl[i][i]=0;
dprr[i][i]=h;
plr[i][i]=0;
pll[i][i]=p;
prr[i][i]=1-p;
prl[i][i]=0;
}
for(int i=1; i<=n; i++)
for(int j=1; j<=n-i; j++)
{int l=j,r=j+i;
pll[l][r]=0.5*p*(pll[l+1][r]+prl[l+1][r]);
dpll[l][r]=p*prl[l+1][r]/2*(dprl[l+1][r]+h)+p*pll[l+1][r]/2*(dpll[l+1][r]+h-max((double)0,x[l]-x[l+1]+h));
plr[l][r]=0.5*p*(plr[l+1][r]+prr[l+1][r]);
dplr[l][r]=p*prr[l+1][r]/2*(dprr[l+1][r]+h)+p*plr[l+1][r]/2*(dplr[l+1][r]+h-max((double)0,x[l]-x[l+1]+h));
prr[l][r]+=0.5*(1-p)*(prr[l][r-1]+prl[l][r-1]);
dprr[l][r]+=(1-p)/2*prl[l][r-1]*(dprl[l][r-1]+h)+(1-p)/2*prr[l][r-1]*(dprr[l][r-1]+h-max((double)0,x[r-1]-x[r]+h)) ;
plr[l][r]+=0.5*(1-p)*(plr[l][r-1]+pll[l][r-1]);
dplr[l][r]+=(1-p)/2*pll[l][r-1]*(dpll[l][r-1]+h)+(1-p)/2*plr[l][r-1]*(dplr[l][r-1]+h-max((double)0,x[r-1]-x[r]+h)) ;
int T=min(r,tr[l]);
double d=x[T]-x[l];
if(T==r)
{prr[l][r]+=(1-p)*0.5;
dprr[l][r]+=0.5*(1-p)*(d+h);}
else{prl[l][r]+=0.5*(1-p)*(pll[T+1][r]+prl[T+1][r]);
dprl[l][r]+=(1-p)*prl[T+1][r]/2*(dprl[T+1][r]+h+d)+(1-p)*pll[T+1][r]/2*(dpll[T+1][r]+d+h-max((double)0,2*h-x[T+1]+x[T]));
prr[l][r]+=0.5*(1-p)*(plr[T+1][r]+prr[T+1][r]);
dprr[l][r]+=(1-p)*prr[T+1][r]/2*(dprr[T+1][r]+h+d)+(1-p)*plr[T+1][r]/2*(dplr[T+1][r]+d+h-max((double)0,2*h-x[T+1]+x[T]));}
T=max(l,tl[r]);
d=x[r]-x[T];
    if(T==l)
{pll[l][r]+=0.5*p;
dpll[l][r]+=0.5*p*(d+h);}
else
{prl[l][r]+=p*(prr[l][T-1]+prl[l][T-1])/2;
dprl[l][r]+=p/2*prl[l][T-1]*(dprl[l][T-1]+h+d)+p/2*prr[l][T-1]*(dprr[l][T-1]+h+d-max((double)0,2*h-x[T]+x[T-1])) ;
pll[l][r]+=p*(plr[l][T-1]+pll[l][T-1])/2;
dpll[l][r]+=p/2*pll[l][T-1]*(dpll[l][T-1]+h+d)+p/2*plr[l][T-1]*(dplr[l][T-1]+h+d-max((double)0,2*h-x[T]+x[T-1])) ;
}
if(prl[l][r]!=0) dprl[l][r]/=prl[l][r];
if(pll[l][r]!=0)dpll[l][r]/=pll[l][r];
if(prr[l][r]!=0)dprr[l][r]/=prr[l][r];
if(plr[l][r]!=0)dplr[l][r]/=plr[l][r];}
double e=0;
e+=dplr[1][n]*plr[1][n];
e+=dpll[1][n]*pll[1][n];
e+=dprr[1][n]*prr[1][n];
e+=dprl[1][n]*prl[1][n];
printf("%.8f",e);
}