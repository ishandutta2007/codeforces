#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 5010
struct P{int x,y;}a[N];int n,d[N],s;vector<int> S;
bool ints(int x1,int y1,int x2,int y2)
{
    if(x1>x2||x1==x2&&y1>y2)swap(x1,x2),swap(y1,y2);
    if(x2<y1)return 1;else return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j&&ints(a[i].x,a[i].y,a[j].x,a[j].y))d[i]++,d[j]++,s++;
    for(int i=0;i<n;i++)if(d[i]==s)S.push_back(i);
    printf("%d\n",(int)S.size());
    for(int i=0;i<(int)S.size();i++)
        printf("%d%c",S[i]+1,i==(int)S.size()-1?'\n':' ');
    return 0;
}