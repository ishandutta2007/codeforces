#include<cstdio>
int n,m,A[500][500],i,j,k,S;
long long x[500],y[500],X[500],Y[500],a,b,c;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;scanf("%I64d%I64d",x+i,y+i),i++);
    for(i=0;i<m;scanf("%I64d%I64d",X+i,Y+i),i++);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(x[i]<x[j])
            {
                a=y[j]-y[i],b=x[i]-x[j],c=-x[i]*a-y[i]*b;
                for(k=0;k<m;A[i][j]+=X[k]>x[i]&&X[k]<=x[j]&&a*X[k]+b*Y[k]+c>0,k++);
                A[j][i]=-A[i][j];
            }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            for(k=j+1;k<n;k++)
                S+=A[i][j]+A[j][k]+A[k][i]==0;
    printf("%d\n",S);   
}