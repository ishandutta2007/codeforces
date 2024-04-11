#include <cstdio>
#include <algorithm>
using namespace std;
struct Data {
    int id;
    int value;
}D1[100002],D2[100002],*t;
int head1,head2;
bool Compare(const Data &a,const Data &b) {
    return a.value>b.value;
}
int main() {
    int n,v,mark1=0,mark2=0;
    long long ans=0,temp;
    scanf("%d%d",&n,&v);
    for(int i=1,j;i<=n;++i) {
        scanf("%d",&j);
        if(j==1)
            t=&D1[head1++];
        else
            t=&D2[head2++];
        t->id=i;
        scanf("%d",&t->value);
    }
    for(sort(D2,D2+head2,Compare);v>1&&mark2<head2;v-=2)
        ans+=D2[mark2++].value;
    for(sort(D1,D1+head1,Compare);v>0&&mark1<head1;v-=1)    
        ans+=D1[mark1++].value;
    temp=ans;
    for(int i=mark2-1,j;i>=0;--i){
        temp-=D2[i].value;
        v+=2;
        for(j=mark1;j<head1&&v>0;++j) {
            temp+=D1[j].value;
            v-=1;
        }
        if(ans<temp){
            ans=temp;
            mark1=j;
            mark2-=1;
        }
        else
            break;
    }
    printf("%I64d\n",ans);
    for(int i=0;i<mark2;++i)
        printf("%d ",D2[i].id);
    for(int i=0;i<mark1;++i)
        printf("%d ",D1[i].id);
    return 0;
}