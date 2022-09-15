#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORE(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define inp(n) int (n); scanf("%d",&(n));
#define inp2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define inp3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
#define SSD(x) (scanf("%d",&x))
#define SSL(x) (scanf("%lld",&x))
#define SSF(x) (scanf("%f",&x))
#define SSS(x) (scanf("%s",x))
inline void prt(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS inp(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define MAX(a,b) (a)=max((a),(b));
#define MIN(a,b) (a)=min((a),(b));
#define INRAN(a,b,c) ((a)>=(b) && (a)<(c))

long long a[200001];
long long b[200001];
int main ()
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w+",stdout);
    long long sum=0;
    double ans=0.0;
    int k=1;
    TESTS
    {
        inp(t);
        if(t==1)
        {
            inp2(i,x);
            b[i]+=x;
            sum+=i*x;
        }
        if(t==2)
        {
            inp(y);
            a[++k]=y;
            sum+=y;
        }
        if(t==3)
        {
            sum-=a[k]+b[k];
            b[k-1]+=b[k];
            b[k]=a[k] = 0;
            k--;
        }
        ans=1.0*sum;
        ans/=1.0*k;
        printf("%lf\n",ans);
    }
    return 0;

}