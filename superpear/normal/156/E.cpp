#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int where[25]={1,1,1,1,1,1,1,2,2,2,2,3,1,3,3,4,4,2,4,4,4,3,3,2,1};
const int e[17]={0,0,14,9,7,6,6,5,5,5,4,4,4,4,4,4,4};

struct four
{
    int d,w;
    LL c;
    string s;
};

LL data[10005];
int big[5],rem[5],finalans[30005];
int n,m,ff,jt,f1,f2,ft1,ft2,ft;
four f[30005];
vector<int> g1[4][15][3][15][3];
vector<int> g2[17][8][17];
string st;
string q[10005][18];
char ch;

bool cmp(const four &a,const four &b)
{
    if (a.d<b.d) return true;
    if (a.d>b.d) return false;
    return a.s<b.s;
}

int getans()
{
    for (int i=0;i<25;i++)
        if (rem[where[i]]%prime[i]==0) return prime[i];
    return -1;
}

bool pipei(const string &s,const string &st)
{
    if (st.size()<s.size()) return false;
    for (int i=0;i<s.size();i++)
        if ((st[i]!='?')&&(st[i]!=s[i])) return false;
    for (int i=s.size();i<st.size();i++)
        if ((st[i]!='?')&&(st[i]!='0')) return false;
    return true;
}

int main()
{
    //freopen("E.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++) cin>>data[i];
    for (int i=1;i<=4;i++) big[i]=1;
    for (int i=0;i<25;i++) big[where[i]]*=prime[i];
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>f[i].d>>f[i].s>>f[i].c;
        //if ((data[0]==322925950206957592LL)&&(i==26047)) break;
        if (f[i].s.size()>e[f[i].d]) f[i].s.erase(0,f[i].s.size()-e[f[i].d]);
        for (int j=0;j<f[i].s.size()/2;j++)
            swap(f[i].s[j],f[i].s[f[i].s.size()-j-1]);
        f[i].w=i;
    }
    //if (data[0]==322925950206957592LL) {cout<<f[26047].d<<" "<<f[26047].s<<" "<<f[26047].c<<endl;return 0;}
    sort(f+1,f+m+1,cmp);
    int cs,ct1,ct2,ct;
    int data1[10005][5];
    for (int i=0;i<n;i++)
        for (int j=1;j<=4;j++)
            data1[i][j]=(LL)data[i]%big[j];
    for (int i=0;i<n;i++)
        for (int j=2;j<=16;j++)
        {
            st="";
            cs=i;
            while (cs>0)
            {
                if (cs%j<10) st+=cs%j+48; else st+=cs%j+55;
                cs/=j;
            }
            if (st=="") st="0";
            q[i][j]=st;
            if (j<=3)
            {
                //cout<<j<<" "<<st<<" "<<st.size()<<" "<<e[j]<<endl;
                int ee=st.size();
                if (st.size()<e[j]) for (int k1=1;k1<=e[j]-ee;k1++) st+='0';
                //cout<<j<<" "<<st<<endl;
                for (int k1=0;k1<st.size();k1++)
                    for (int k2=k1+1;k2<st.size();k2++)
                    {
                        ct1=st[k1]-48;ct2=st[k2]-48;
                        //cout<<k1<<" "<<k2<<" "<<ct1<<" "<<ct2<<endl;
                        g1[j][k1][ct1][k2][ct2].p_b(i);
                    }
            }
            else
            {
                int ee=st.size();
                if (st.size()<e[j]) for (int k1=1;k1<=e[j]-ee;k1++) st+='0';
                for (int k=0;k<st.size();k++)
                {
                    if ((st[k]>='A')&&(st[k]<='F')) ct=st[k]-55; else ct=st[k]-48;
                    g2[j][k][ct].p_b(i);
                }
            }
        }
    memset(rem,0,sizeof(rem));
    for (int i=1;i<=m;i++)
    {
        if ((i!=1)&&(f[i].d==f[i-1].d)&&(f[i].s==f[i-1].s))
        {
            for (int j=1;j<=4;j++) rem[j]=((LL)rem[j]-f[i-1].c+f[i].c+big[j])%big[j];
            finalans[f[i].w]=getans();
        }
        else
        {
            for (int j=1;j<=4;j++) rem[j]=1;
            st=f[i].s;
            if (f[i].d>3)
            {
                ff=-1;
                for (int j=0;j<st.size();j++)
                    if (st[j]!='?') {ff=j;break;}
                if (ff==-1)
                {
                    for (int j=0;j<n;j++)
                        if (pipei(q[j][f[i].d],f[i].s))
                            for (int k=1;k<=4;k++)
                                rem[k]=(LL)rem[k]*data1[j][k]%big[k];
                    for (int k=1;k<=4;k++) rem[k]=((LL)rem[k]+f[i].c)%big[k];
                }
                else
                {
                    ch=st[ff];
                    if ((ch>='A')&&(ch<='Z')) ft=ch-55; else ft=ch-48;
                    for (int j=0;j<g2[f[i].d][ff][ft].size();j++)
                    {
                        jt=g2[f[i].d][ff][ft][j];
                        if (pipei(q[jt][f[i].d],f[i].s))
                            for (int k=1;k<=4;k++)
                                rem[k]=(LL)rem[k]*data1[jt][k]%big[k];
                    }
                    for (int k=1;k<=4;k++) rem[k]=((LL)rem[k]+f[i].c)%big[k];
                }
            }
            else
            {
                f1=-1;f2=-1;
                for (int j=0;j<st.size();j++)
                    if (st[j]!='?')
                    {
                        if (f1==-1) f1=j; else f2=j;
                        if (f2!=-1) break;
                    }
                //if ((data[0]==322925950206957592LL)&&(f[i].w==26047)) cout<<f1<<" "<<f2<<endl;
                if (f2==-1)
                {
                    for (int j=0;j<n;j++)
                        if (pipei(q[j][f[i].d],f[i].s))
                            for (int k=1;k<=4;k++)
                                rem[k]=(LL)rem[k]*data1[j][k]%big[k];
                    for (int k=1;k<=4;k++) rem[k]=((LL)rem[k]+f[i].c)%big[k];
                }
                else
                {
                    ch=st[f1];
                    if ((ch>='A')&&(ch<='Z')) ft1=ch-55; else ft1=ch-48;
                    ch=st[f2];
                    if ((ch>='A')&&(ch<='Z')) ft2=ch-55; else ft2=ch-48;
                    //cout<<f[i].s<<" "<<f1<<" "<<f2<<endl;
                    for (int j=0;j<g1[f[i].d][f1][ft1][f2][ft2].size();j++)
                    {
                        jt=g1[f[i].d][f1][ft1][f2][ft2][j];
                        //if ((data[0]==322925950206957592LL)&&(f[i].w==26047)) cout<<data[jt]<<endl;
                        if (pipei(q[jt][f[i].d],f[i].s))
                        {
                            //if ((data[0]==322925950206957592LL)&&(f[i].w==26047)) cout<<data[jt]<<endl;
                            for (int k=1;k<=4;k++)
                            {
                                rem[k]=(LL)rem[k]*data1[jt][k]%big[k];

                            }
                        }
                    }
                    for (int k=1;k<=4;k++) rem[k]=((LL)rem[k]+f[i].c)%big[k];
                }
            }
            finalans[f[i].w]=getans();
        }
    }
    for (int i=1;i<=m;i++) cout<<finalans[i]<<endl;

    return 0;
}