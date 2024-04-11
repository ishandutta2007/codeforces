#include<bits/stdc++.h>
#define MAXN 5005
#define MAXK 2505
using namespace std;
int n,k;
vector<int> dif[MAXK];
vector <int> save;
bool rep[MAXK];
char str[MAXK][MAXN];
bool used[26];
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++)
        scanf("%s",str[i]);
    bool f=true;
    for(int i=1;i<k;i++)
        for(int j=0;j<n;j++)
        {
            if(str[i][j]!=str[0][j]) dif[i].push_back(j);
            if(dif[i].size()>4) {f=false; break;}
        }
    memset(rep,false,sizeof(rep));
    for(int i=0;i<k;i++)
    {
        memset(used,false,sizeof(used));
        for(int j=0;j<n;j++)
        {
            if(used[str[i][j]-'a'])
            {
                rep[i]=true;
                break;
            }
            else used[str[i][j]-'a']=true;
        }
    }
    if(!f)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            swap(str[0][i],str[0][j]);
            bool flag=true;
            for(int p=1;p<k;p++)
            {
                save.clear();
                for(int q=0;q<dif[p].size();q++)
                    if(str[p][dif[p][q]]!=str[0][dif[p][q]]) save.push_back(dif[p][q]);
                if((str[0][i]!=str[p][i])&&(str[0][j]==str[p][i])) save.push_back(i);
                if((str[0][j]!=str[p][j])&&(str[0][i]==str[p][j])) save.push_back(j);
                if(save.size()==0)
                {
                    if(rep[p]) continue;
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(save.size()!=2) {flag=false; break;}
                if(str[p][save[0]]!=str[0][save[1]]||str[p][save[1]]!=str[0][save[0]]) {flag=false; break;}
            }
            if(flag)
            {
                printf("%s\n",str[0]);
                return 0;
            }
            swap(str[0][i],str[0][j]);
        }
    printf("-1\n");
    return 0;
}