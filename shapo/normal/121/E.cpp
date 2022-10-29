#include <iostream>
#include <cmath>
#include <vector>

#define root 317
#define maxn 500000
#define maxk 20000

using namespace std;

char lucky[maxk];
long int n, m, cur[maxn], res[maxn], rt[maxn],sum[2*root], ppt[2*root], llt[2*root];
long int l,r,d;

void init()
{
    for(long int i=1;i<maxk;i++){
        long int k=i;
        char ok=true;
        while(k!=0){
            ok=(ok && ((k%10==4)||(k%10==7)));
            k=k/10;
        }
        lucky[i]=ok;
    }
    for(long int i=1;i<2*root;i++)sum[i]=0;
    for(long int i=1;i<maxn;i++)rt[i]=(i+root-1)/root;
    for(long int i=1;i<2*root;i++){ppt[i]=i*root;llt[i]=(i-1)*root+1;}
}

int add(long int x, long int y, long int z)
{
    for (long int i=x;i<=y;i++){
        if (lucky[cur[i]]) sum[rt[i]]--;
        cur[i]+=z;
        if (lucky[cur[i]]) sum[rt[i]]++;
    }
    return 0;
}

long int count(long int x, long int y)
{
    long int res=0;
    long int ll=rt[x], rr=rt[y];
    if (ll==rr){
        for(int i=x;i<=y;i++) if (lucky[cur[i]]) res++;
        return res;
    }
    if (x!=llt[ll]){
        for(long int i=x;i<=ppt[ll];i++)if (lucky[cur[i]]) res++;
        ll++;
    }
    if (y!=ppt[rr]){
        for(long int i=llt[rr];i<=y;i++)if (lucky[cur[i]]) res++;
        rr--;
    }
    for(long int i=ll;i<=rr;i++) res+=sum[i];
    return res;
}

int main(){
    init();
    string s;
    cin >> n >> m;
    long int num=0;
    for(long int i=1;i<=n;i++){cin >> cur[i];if (lucky[cur[i]]) sum[rt[i]]++;}
    for(long int i=1;i<=m;i++){
        cin >> s;
        if (s=="add"){
            cin >> l >> r >> d;
            add(l,r,d);
        }
        else{
        cin >> l >> r;
        num++;
        res[num]=count(l,r);
        }
    }
    for (long int i=1;i<=num;i++) cout<<res[i]<<endl;
    return 0;
}