#include<set>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int k,m,v;
int l[5],Pow[5];
vector<pair<int,int> >q[5];
set<pair<int,int> >b;

int main()
{
    scanf("%d%d",&k,&m);
    for(int i=0;i<=9;i++)
    {
        q[1].push_back(make_pair(i,i));
        if(i)q[1].push_back(make_pair(i,-i));
    }
    Pow[0]=1;Pow[1]=10;Pow[2]=100;Pow[3]=1000;
    for(int i=2;i<=4;i++)
    {
        b.clear();
        for(int j=1;j<i;j++)
            for(int k=0;k<(int)q[j].size();k++)
                for(int p=0;p<(int)q[i-j].size();p++)
                    b.insert(make_pair(q[j][k].first*Pow[i-j]+q[i-j][p].first,q[j][k].second+q[i-j][p].second)),
                    b.insert(make_pair(q[j][k].first*Pow[i-j]+q[i-j][p].first,q[j][k].second-q[i-j][p].second)),
                    b.insert(make_pair(q[j][k].first*Pow[i-j]+q[i-j][p].first,q[j][k].second*q[i-j][p].second));
        for(set<pair<int,int> >::iterator it=b.begin();it!=b.end();it++)
            q[i].push_back(*it);
    }
    for(int i=0;i<(int)q[4].size();i++)
    {
        v=q[4][i].second+k;
        if(v<10000&&v>=0)
        {
            printf("%.4d%.4d\n",q[4][i].first,v);
            m--;
            if(!m)return 0;
        }
    }
}