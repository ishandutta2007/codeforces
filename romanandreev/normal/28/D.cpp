#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
typedef pair<int,int> pii;
vector<pii> a;
int vv[1000000];
int cc[1000000];
int ll[1000000];
int rr[1000000];
int d[1000000];
int bc[1000000];
int bc2[1000000];
int f[1000000];
int n;
vector<int> aa;
void bct(int n){
    if (ll[n]!=0)
    bct(bc2[n]);
    aa.pb(n);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d%d%d",&vv[i],&cc[i],&ll[i],&rr[i]);
        a.pb(mp(cc[i]+ll[i]+rr[i],i));
    }
    sort(a.begin(),a.end());
    int pr=-1;
    int cnt=0;
    int ans=0;
    for (int i=0;i<n;i++){
        if ((i==n-1)||(a[i].fs!=a[i+1].fs)){
            cnt++;
            d[0]=0;
            f[0]=cnt;
            f[a[i].fs]=cnt;
            d[a[i].fs]=0;
            for (int j=pr+1;j<=i;j++){
                if (f[ll[a[j].sc]]==cnt){
                    if (f[ll[a[j].sc]+cc[a[j].sc]]!=cnt){
                        f[ll[a[j].sc]+cc[a[j].sc]]=cnt;
                        d[ll[a[j].sc]+cc[a[j].sc]]=0;
                    }
                    if (d[ll[a[j].sc]]+vv[a[j].sc]>d[ll[a[j].sc]+cc[a[j].sc]]){
                        d[ll[a[j].sc]+cc[a[j].sc]]=d[ll[a[j].sc]]+vv[a[j].sc];
                        bc[ll[a[j].sc]+cc[a[j].sc]]=a[j].sc;
                        bc2[a[j].sc]=bc[ll[a[j].sc]];
                    }
                    if (d[ll[a[j].sc]+cc[a[j].sc]]==0){
                        f[ll[a[j].sc]+cc[a[j].sc]]=cnt-1;
                    }
                }
            }
            if (d[a[i].fs]>ans){
                ans=d[a[i].fs];
                aa.clear();
                bct(bc[a[i].fs]);
            }
            pr=i;
        }
    }
    printf("%d\n",aa.size());
    for (int i=0;i<aa.size();i++){
        printf("%d ",aa[i]+1);
    }
}