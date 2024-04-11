#include<iostream>
using namespace std;
long long x2,x1,y1,y2,n,x[2000],y[2000],ans=0;
long long la(long long p, long long q)
{return (x1-p)*(x1-p)+(y1-q)*(y1-q);}
long long lb(long long p, long long q)
{return (x2-p)*(x2-p)+(y2-q)*(y2-q);}
main()
{cin>>n>>x1>>y1>>x2>>y2;
for (int i=0; i<n; i++)
cin>>x[i]>>y[i];
for (int i=0; i<n; i++)
{long long R1=la(x[i],y[i]),R2=lb(x[i],y[i]);
long long  m1=0,m2=0;
for (int j=0; j<n; j++){
if (la(x[j],y[j])>R1) m2=(long long)max((long long)m2,lb(x[j],y[j]));
if (lb(x[j],y[j])>R2) m1=(long long)max((long long)m1,la(x[j],y[j]));
}
if (R1+m2<ans || ans==0) ans=R1+m2;
if (R2+m1<ans) ans=R2+m1;
}

cout<<ans<<endl;
}