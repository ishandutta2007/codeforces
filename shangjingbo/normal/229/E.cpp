#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

const int maxn  =   1005;

int n,m;
double C[maxn][maxn],f[maxn][maxn];
int sum[maxn];
VI a[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    VI bak;
    for (int i=0;i<m;++i){
        a[i].clear();
        int k;
        scanf("%d",&k);
        for (int j=0;j<k;++j){
            int x;
            scanf("%d",&x);
            a[i].push_back(x);
            bak.push_back(x);
        }
        sort(a[i].begin(),a[i].end());
    }
    sort(bak.begin(),bak.end());
    reverse(bak.begin(),bak.end());
    
    int target=bak[n-1],need=0;
    for (int i=0;i<n;++i){
        need+=bak[i]==target;
    }
    
    for (int i=m-1;i>=0;--i){
        sum[i]=sum[i+1];
        int index=lower_bound(a[i].begin(),a[i].end(),target)-a[i].begin();
        if (index>=0 && index<a[i].size() && a[i][index]==target){
            ++sum[i];
        }
    }
    
    for (int i=0;i<=1000;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for (int i=0;i<m;++i){
        int index=lower_bound(a[i].begin(),a[i].end(),target)-a[i].begin();
        for (int j=0;j<=need;++j){
            if (f[i][j]>1e-11){
                if (index>=0 && index<a[i].size() && a[i][index]==target){
                    double p=(need-j)/(double)sum[i];
                    f[i+1][j+1]+=f[i][j]*p/C[a[i].size()][a[i].size()-index];
                    f[i+1][j]+=f[i][j]*(1-p)/C[a[i].size()][a[i].size()-index-1];
                }else{
                    f[i+1][j]+=f[i][j]/C[a[i].size()][a[i].size()-index];
                }
            }
        }
    }
    printf("%.10f\n",f[m][need]);
    
    return 0;
}