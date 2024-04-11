#include<cstdio>
int a[400],n,S=-1,i,j,s,p,q,k;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;scanf("%d",a+i++));
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            p=a[i]-1;
            for(k=q=s=0;k<=j;q+=p/a[k],s+=p/a[k]*a[k],p%=a[k++]);
            q++,p=s+=a[j];
            for(k=0;k<n;q-=p/a[k],p%=a[k++]);
            if(q<0&&s<=unsigned(S))
                S=s;
        }
    printf("%d\n",S);
    return 0;
}