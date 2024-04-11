#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int n,m;
char fi[233],se[233];
string fn[1010],sn[1010];
int state[1010];
int ft[25000],st[25000];
inline int Hash(char a,char b,char c)
{
    int aa=a-'A'+1,bb=b-'A'+1,cc=c-'A'+1;
    int ret=aa*29*29+bb*29+cc;
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s",fi,se);
        fn[i]=string("")+fi[0]+fi[1]+fi[2];
        sn[i]=string("")+fi[0]+fi[1]+se[0];
        int hf=Hash(fn[i][0],fn[i][1],fn[i][2]);
        //cout<<fn[i]<<' '<<hf<<' '<<ft[hf]<<endl;
        if(ft[hf])
        {
            int tmp=ft[hf],hs;
            if(tmp!=-1)
            {
                hs=Hash(sn[tmp][0],sn[tmp][1],sn[tmp][2]);
                if(st[hs])
                {
                    printf("NO\n");
                    return 0;
                }
                state[tmp]=2;
            }
            st[hs]=1;
            ft[hf]=-1;
            hs=Hash(sn[i][0],sn[i][1],sn[i][2]);
            if(st[hs])
            {
                printf("NO\n");
                return 0;
            }
            else state[i]=2;
            st[hs]=1;
        }
        else
        {
            ft[hf]=i;
            state[i]=1;
        }
    }
    int changed=1;
    while(changed)
    {
        changed=0;
        for(int i=1;i<=n;i++)
        {
            if(state[i]==2)continue;
            int hf=Hash(fn[i][0],fn[i][1],fn[i][2]);
            if(st[hf])
            {
                int hs=Hash(sn[i][0],sn[i][1],sn[i][2]);
                if(st[hs])
                {
                    printf("NO\n");
                    return 0;
                }
                else state[i]=2;
                st[hs]=1;
                st[hf]=-1;
                changed=1;
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        if(state[i]==1)printf("%s\n",fn[i].c_str());
        else printf("%s\n",sn[i].c_str());
    }
    return 0;
}