#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
#define prev _prev
#define stack _stack
 
ll scal(pi a,pi b)
{return(ll)a.first*(ll)a.second+(ll)b.first*(ll)b.second;}
ll mul(pi a,pi b)
{return(ll)a.first*(ll)b.second-(ll)a.second*(ll)b.first;}
int half(pi a)
{if(a.second>0||(a.second==0&&a.first>=0))
return 0;return 1;}
int half(pi a,pi b)
{ll pr=mul(a,b);if(pr!=0)
return(pr<=0);return(scal(a,b)<0);}
const int M=210;const int MOD=998244353;int n,x[M],y[M],dp[M],val[M][M],ml[M],ei[M][M],first[M][M],last[M][M],sum[2*M],ok[M][M];vector<int>v[M];vector<int>way[M][M];pi vect(int i,int j)
{return make_pair(x[j]-x[i],y[j]-y[i]);}
pi vect(pi t)
{return make_pair(x[t.second]-x[t.first],y[t.second]-y[t.first]);}
void dfs_help(int p,int pr)
{int id=-1;for(int i=0;i<(int)v[p].size();i++)
{if(v[p][i]==pr)
id=i;else
dfs_help(v[p][i],p);}
if(id!=-1)
{swap(v[p][id],v[p].back());v[p].pop_back();}}
vector<int>stack;void dfs_way(int p,int pr,int st)
{stack.push_back(p);if(p!=st&&(int)stack.size()>=3)
{bool ch=true;for(int i:stack)
if(mul(vect(st,p),vect(st,i))<0)
{ch=false;break;}
if(ch)
way[st][p]=stack;}
for(int i:v[p])
if(i!=pr)
dfs_way(i,p,st);stack.pop_back();}
bool cmp(pi a,pi b){pi va=vect(a);pi vb=vect(b);int ha=half(va);int hb=half(vb);if(ha!=hb)
return ha<hb;ll pr=mul(va,vb);if(pr!=0)
return(pr>0);return a<b;}
bool good(pi a,pi b,pi c){int hb=half(a,b);int hc=half(a,c);if(hb!=hc)
return hb<hc;return mul(b,c)>0;}
vector<int>g[M];vector<int>dfs(int p){ml[p]=1;vector<int>now={p};for(int i:v[p])
{vector<int>to=dfs(i);for(int x:to)
now.push_back(x);ml[p]=(ll)ml[p]*dp[i]%MOD;}
dp[p]=ml[p];for(int i:v[p])
{int cur=ml[i];for(int j:v[p])
if(j!=i)
cur=(ll)cur*dp[j]%MOD;dp[p]+=cur;if(dp[p]>=MOD)
dp[p]-=MOD;}
for(int i:now)
g[i].clear();int k=0;for(int i:now)
for(int j:v[i])
{g[i].push_back(j);g[j].push_back(i);ei[i][j]=k++;ei[j][i]=k++;}
for(int i:now)
for(int j:now)
ok[i][j]=0;vector<pi>al;for(int i:now)
for(int j:now)
if(!way[i][j].empty()&&mul(vect(i,j),vect(i,p))>=0)
{al.push_back(make_pair(i,j));first[i][j]=ei[way[i][j][0]][way[i][j][1]];last[i][j]=ei[way[i][j][(int)way[i][j].size()-1]][way[i][j][(int)way[i][j].size()-2]];if(val[i][j]!=-1)
continue;ok[i][j]=1;val[i][j]=1;for(int x=0;x<(int)way[i][j].size();x++)
{int v_cur=way[i][j][x];pi lb,rb;if(x==0)
{lb=vect(v_cur,way[i][j][x+1]);lb.first=-lb.first,lb.second=-lb.second;}
else
lb=vect(v_cur,way[i][j][x-1]);if(x+1==(int)way[i][j].size())
{rb=vect(v_cur,way[i][j][x-1]);rb.first=-rb.first,rb.second=-rb.second;}
else
rb=vect(v_cur,way[i][j][x+1]);for(int to:v[v_cur])
if(good(lb,vect(v_cur,to),rb))
{if(x!=0&&to==way[i][j][x-1])
continue;if(x+1<(int)way[i][j].size()&&to==way[i][j][x+1])
continue;val[i][j]=(ll)val[i][j]*dp[to]%MOD;}}}
sort(al.begin(),al.end(),cmp);for(int v_st:now)
for(int ig:g[v_st])
{if(half(vect(v_st,ig)))
continue;for(int ban=-1;ban<=1;ban+=2)
{for(int i=0;i<k;i++)
sum[i]=0;sum[ei[v_st][ig]]=1;for(pi t:al)
{if(ban==-1&&ok[t.first][t.second])
continue;int S=first[t.first][t.second];int F=last[t.first][t.second];sum[F]+=(ll)sum[S]*val[t.first][t.second]%MOD;if(sum[F]>=MOD)
sum[F]-=MOD;}
sum[ei[v_st][ig]]--;if(sum[ei[v_st][ig]]<0)
sum[ei[v_st][ig]]+=MOD;dp[p]+=ban*sum[ei[v_st][ig]];if(dp[p]>=MOD)
dp[p]-=MOD;if(dp[p]<0)
dp[p]+=MOD;}}
return now;}
int main()
{cin>>n;for(int i=0;i<n;i++)
cin>>x[i]>>y[i];for(int i=0;i<n-1;i++)
{int s,f;cin>>s>>f;s--,f--;v[s].push_back(f);v[f].push_back(s);}
for(int i=0;i<n;i++)
dfs_way(i,-1,i);dfs_help(0,-1);memset(val,-1,sizeof(val));dfs(0);cout<<dp[0]<<"\n";return 0;}