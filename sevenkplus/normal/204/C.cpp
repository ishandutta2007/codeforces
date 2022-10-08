#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define N 200010
char s[N],t[N];
double S=0,T=0;int n;
vector<int> a[26],b[26];
double sl[N],sr[N];
int main()
{
    scanf("%d%s%s",&n,s,t);
    for(int i=1;i<=n;i++)
        T+=(double)(n-i+1)*(n-i+1);
    for(int i=0;i<n;i++)
        a[s[i]-'A'].pb(i),b[t[i]-'A'].pb(i);
    for(int i=0;i<26;i++)
        if(!a[i].empty()&&!b[i].empty())
        {
            sl[0]=0;
            for(int j=0;j<(int)b[i].size();j++)
                sl[j+1]=sl[j]+b[i][j]+1;
            sr[(int)b[i].size()]=0;
            for(int j=(int)b[i].size()-1;j>=0;j--)
                sr[j]=sr[j+1]+(n-b[i][j]);
            for(int j=0,k=0;j<(int)a[i].size();j++)
            {
                while(k<(int)b[i].size()&&b[i][k]<a[i][j])k++;
                S+=(n-a[i][j])*sl[k]+(a[i][j]+1)*sr[k];
            }
        }
    printf("%.9lf\n",S/T);
    return 0;
}