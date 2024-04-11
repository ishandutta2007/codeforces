#include <cstdio>
int main()
{
    int n,m,s,f;
    int t,l,r;
    int i,j,last;
    int add;
    char put;
    //freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&s,&f);
    if (s<f)
    {
        put='R';
        add=1;
    }
    else
    {
        put='L';
        add=-1;
    }
    last=0;
    for (i=0;i<m;++i)
    {
        scanf("%d%d%d",&t,&l,&r);
        for (j=last+1;j<t;++j)
        {
            if (s!=f)
            {
                printf("%c",put);
                s+=add;
            }
            else return 0;
        }
        if (s==f) return 0;
        last=t;
        if ((l<=s&&s<=r)||(l<=s+add&&s+add<=r)) printf("X");
        else
        {
            if (s!=f)
            {
                printf("%c",put);
                s+=add;
            }
            else return 0;
        }
    }
    for (;s!=f;s+=add) printf("%c",put);
    return 0;
}