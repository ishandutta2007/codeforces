#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=100000+10;
vector<int> v;
int id(int x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
int n,op[N],a[N]; 
struct Nod{
    LL sum[5]; int cnt;
    Nod(){
        cnt=0; memset(sum,0,sizeof(sum));
    }
    Nod operator+(const Nod&o)const{
        Nod ans; ans.cnt=cnt+o.cnt;
        for(int i=0;i<5;i++){
            ans.sum[i]+=sum[i];
            ans.sum[(i+cnt%5)%5]+=o.sum[i];
        }
        return ans;
    }
} nod[N<<2];   
void update(int l,int r,int rt,int pos,int sgn){
    if(l==r){
        nod[rt].cnt+=sgn; nod[rt].sum[0]+=sgn*v[pos-1];
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) update(l,mid,rt<<1,pos,sgn);
    else update(mid+1,r,rt<<1|1,pos,sgn);
    nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n<<1;i++) nod[i]=Nod();
    for(int i=1;i<=n;i++){
        char str[6]; scanf("%s",str);
        if(str[0]=='a'||str[0]=='d') {
            op[i]=0, scanf("%d",&a[i]), v.push_back(a[i]);
            if(str[0]=='d') op[i]=-1; 
        }
        else op[i]=1;
    }
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());

    for(int i=1;i<=n;i++){
        if(op[i]<=0) {
            update(1,v.size(),1,id(a[i]),op[i]==0?+1:-1);
        } else {
            printf("%lld\n", nod[1].sum[2]);
        }
    }
}