#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int pl,pr,vl,vr,k;ll S=0;
vector<int> a;
int main()
{
    scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k);
    for(int i=1;i<=9;i++)
        for(int k=0;k<(1<<i);k++)
        {
            int x=0;
            for(int j=0;j<i;j++)
                if((k>>j)&1)x=x*10+4;else x=x*10+7;
            a.push_back(x);
        }
    sort(a.begin(),a.end());
    for(int i=0;i<(int)a.size();i++)
        for(int j=i;j<(int)a.size();j++)
            if(j-i+1==k)
                if(min(pr,a[i])-max(pl,i==0?1:a[i-1]+1)>=0&&min(vr,j==(int)a.size()-1?vr:a[j+1]-1)-max(vl,a[j])>=0)
                    S+=(ll)(min(pr,a[i])-max(pl,i==0?1:a[i-1]+1)+1)*(min(vr,j==(int)a.size()-1?vr:a[j+1]-1)-max(vl,a[j])+1);
    swap(pl,vl),swap(pr,vr);
    for(int i=0;i<(int)a.size();i++)
        for(int j=i;j<(int)a.size();j++)
            if(j-i+1==k)
                if(min(pr,a[i])-max(pl,i==0?1:a[i-1]+1)>=0&&min(vr,j==(int)a.size()-1?vr:a[j+1]-1)-max(vl,a[j])>=0)
                    S+=(ll)(min(pr,a[i])-max(pl,i==0?1:a[i-1]+1)+1)*(min(vr,j==(int)a.size()-1?vr:a[j+1]-1)-max(vl,a[j])+1);
    if(k==1)for(int i=0;i<(int)a.size();i++)if(pl<=a[i]&&a[i]<=pr&&vl<=a[i]&&a[i]<=vr)S--;
    printf("%.10lf\n",(S+0.0)/((ll)(pr-pl+1)*(vr-vl+1)));
    return 0;
}