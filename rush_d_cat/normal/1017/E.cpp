#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 200000+10;
typedef long long LL;

struct node {
    LL x,y;
} a[N],p[N];
LL top,n,m;
LL cross(node p0, node p1) {
    return p0.x * p1.y - p0.y * p1.x;
}
LL cross(node p0,node p1,node p2)//p0,p1,p2
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
LL dis(node a,node b)//
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool cmp(node p1,node p2)//
{
    LL z=cross(a[0],p1,p2);
    if(z>0||(z==0&&dis(a[0],p1)<dis(a[0],p2)))
        return 1;
    return 0;
}
void Graham()
{
    LL k=0;
    //printf(" n = %d \n", n);
    for(LL i=0; i<n; i++)
        if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x))
            k=i;
        swap(a[0],a[k]);//p[0]
        sort(a+1,a+n,cmp);
        top=1;
        p[0]=a[0];
        p[1]=a[1];
        for(LL i=2; i<n; i++)//
        {
            while(cross(p[top-1],p[top],a[i])<=0&&top)
                top--;
            top++;
            p[top]=a[i];
        }
}
struct Item {
    LL len;
    LL ang;
    void prt() {
        printf("len = %lld, ang = %lld\n", len, ang);
    }
    bool operator < (const Item & o) const {
        if (len == o.len) return ang < o.ang;
        return len < o.len;
    }
};

vector<Item> gao() {
    vector<Item> ans;
    for(LL i=0;i<=top;i++) {
        ///printf("! %lld %lld\n", p[i].y, p[(i==0)?top:(i-1)].y);
        node v1;
        node v2;
        v1.x = p[i].x-p[(i==0)?top:(i-1)].x, v1.y =  p[i].y-p[(i==0)?top:(i-1)].y;
        v2.x = p[(i+1)%(top+1)].x-p[i].x, v2.y = p[(i+1)%(top+1)].y-p[i].y;
        Item it; 
        it.len = v2.x*v2.x + v2.y*v2.y;
        //printf("v1(%lld, %lld), v2(%lld,%lld)\n", v1.x,v1.y, v2.x,v2.y);
        it.ang = cross(v1, v2);
        ans.push_back(it);
    }
    //printf("-----------------------\n");
    return ans;
}
vector<Item> comp;
map<Item, LL> mp;
LL s[N],t[N],slen,tlen,nextval[N];
void get_nextval()
{
    LL i=0;
    nextval[0]=-1;
    LL j=-1;
    while(i< tlen)
    {
        if(j==-1||t[i]==t[j])
        {
            i++;j++; 
            if(t[i]!=t[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }

}
LL kmp()//ts
{
    get_nextval();

    LL i=0;
    LL j=0;
    LL ans=0;
    while(i<slen)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;j++;
        }
        else j=nextval[j];
        if(j>=tlen)
        {
            ans++;
            j=nextval[tlen];
        }
    }
    return ans;
}
int main() {

    scanf("%lld %lld",&n, &m);
    for(LL i=0; i<n; i++) {
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    Graham();

    std::vector<Item> v1 = gao();
    n = m;
    for(LL i=0;i<n;i++) {
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    Graham();
    std::vector<Item> v2 = gao();

    for(LL i=0;i<v1.size();i++) comp.push_back(v1[i]);
    for(LL i=0;i<v2.size();i++) comp.push_back(v2[i]);  
    sort(comp.begin(), comp.end());

    for(LL i=0;i<comp.size();i++) {
        if (i==0 || !(comp[i].len==comp[i-1].len && comp[i].ang==comp[i-1].ang))
            mp[comp[i]] = i+1;
    }

    /*
    for(int i=0;i<v1.size();i++) v1[i].prt();
    printf("----------\n");
    for(int i=0;i<v2.size();i++) v2[i].prt();
    printf("----------\n");
    for(int i=0;i<comp.size();i++)comp[i].prt();
    */

    slen = 2*v1.size(); tlen=v2.size();
    for(LL i=0;i<v1.size();i++) {
        s[i]=mp[v1[i]];
        s[i+v1.size()]=s[i];
    }
    for(LL i=0;i<v2.size();i++) {
        t[i]=mp[v2[i]];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1.size()!=v2.size()) return !printf("NO\n");
    for(int i=0;i<v1.size();i++) {
        if (v1[i].len != v2[i].len || v1[i].ang != v2[i].ang) return !printf("NO\n");
    }
    if(kmp()) printf("YES\n");
    else printf("NO\n");
}