#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int flag[220],len[220][2],color[220],f[220][2];
vector<pair<int,int> >a[220][2];
char Std[220],s[220],c1,c2,changetoC,changetoV;
int l,n,m,x,y,p11,p12,p21,p22,nowcolor,bo;
int change,changex,newcolor,first,last;

int dfs(int x)
{
    flag[x]=1;
    for(int i=0;i<a[x][color[x]].size();i++)
    {
        int nowx=a[x][color[x]][i].first,
        nowcolor=a[x][color[x]][i].second;
        if(flag[nowx])
        {
            if(color[nowx]!=nowcolor)return 0;
            continue;
        }
        color[nowx]=nowcolor;
        if(!dfs(nowx))return 0;
    }
    return 1;
}

void paint(int x)
{
    flag[x]=1;
    for(int i=0;i<a[x][color[x]].size();i++)
    {
        int nowx=a[x][color[x]][i].first,
        nowcolor=a[x][color[x]][i].second;
        if(flag[nowx])continue;
        color[nowx]=nowcolor;
        paint(nowx);
    }
}

int check(int now)
{
    for(int i=now+1;i<=l;i++)
        if(Std[i]!=Std[now])return 1;
    return 0;
}

//0->V 1->C
int main()
{
    scanf("%s",Std+1);
    l=strlen(Std+1);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %c %d %c",&x,&c1,&y,&c2);
        if(c1=='C')p11=1,p12=0;
        else p11=0,p12=1;
        if(c2=='C')p21=1,p22=0;
        else p21=0,p22=1;
        a[x][p11].push_back(make_pair(y,p21));
        a[y][p22].push_back(make_pair(x,p12));
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
        {
            for(int k=1;k<=n;k++)flag[k]=0;
            color[i]=j;
            f[i][j]=dfs(i);
        }
    for(int i=1;i<=n;i++)
        if(!f[i][0]&&!f[i][1])return puts("-1"),0;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)flag[i]=0;
    for(int i=1;i<=n;i++)
    {
        nowcolor=(Std[s[i]-'a'+1]=='C');
        if(flag[i])
        {
            if(color[i]!=nowcolor)
            {
                bo=1;
                if(check(s[i]-'a'+1))
                {
                    change=nowcolor^1;
                    changex=i;
                }
                break;
            }
            else
            {
                for(int j=s[i]-'a'+2;j<=l;j++)
                {
                    newcolor=(Std[j]=='C');
                    if(newcolor==color[i])
                    {
                        change=newcolor;
                        changex=i;
                        break;
                    }
                }
            }
        }
        else
        {
            if(f[i][nowcolor])
            {
                for(int j=s[i]-'a'+2;j<=l;j++)
                {
                    newcolor=(Std[j]=='C');
                    if(f[i][newcolor])
                    {
                        change=newcolor;
                        changex=i;
                        break;
                    }
                }
                color[i]=nowcolor;
                paint(i);
            }
            else
            {
                bo=1;
                if(check(s[i]-'a'+1))
                {
                    change=nowcolor^1;
                    changex=i;
                }
                break;
            }
        }
    }
    if(!bo)return puts(s+1),0;
    if(!changex)return puts("-1"),0;
    for(int i=1;i<=n;i++)flag[i]=0;
    for(int i=1;i<changex;i++)
    {
        color[i]=(Std[s[i]-'a'+1]=='C');
        paint(i);
    }
    color[changex]=change;
    paint(changex);
    s[changex]++;
    while(s[changex]<'a'+l&&((Std[s[changex]-'a'+1]=='C')!=change))s[changex]++;
    if(s[changex]=='a'+l)return puts("-1"),0;
    changetoC='a';
    while(changetoC<'a'+l&&Std[changetoC-'a'+1]=='V')changetoC++;
    changetoV='a';
    while(changetoV<'a'+l&&Std[changetoV-'a'+1]=='C')changetoV++;
    if(changetoC=='a'+l||changetoV=='a'+l)return puts("-1"),0;
    if(Std[1]=='C')first=1,last=0;
    else first=0,last=1;
    for(int i=changex+1;i<=n;i++)
    {
        if(flag[i])
        {
            if(color[i]==1)s[i]=changetoC;
            else s[i]=changetoV;
        }
        else
        {
            if(f[i][first])
            {
                color[i]=first;
                paint(i);
                if(first==1)s[i]=changetoC;
                else s[i]=changetoV;
            }
            else
            {
                color[i]=last;
                paint(i);
                if(last==1)s[i]=changetoC;
                else s[i]=changetoV;
            }
        }
    }
    puts(s+1);
}