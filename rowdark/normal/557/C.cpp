#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
multiset<int> M;
multiset<int>::reverse_iterator iter;
pair<int, int> P[400000];
int n;
int main(){
scanf("%d",&n);
int total=0;
for(int i=0;i<n;++i) scanf("%d",&P[i].first);
for(int i=0;i<n;++i) scanf("%d",&P[i].second),M.insert(P[i].second),total+=P[i].second;
sort(P,P+n);
reverse(P,P+n);
int ans=200*n;
int cnt=0,now=0;
for(int i=0;i<n;++i){
if(i==0||P[i].first==P[i-1].first)
++cnt,now+=P[i].second;
else{
int rem=cnt-1;
int nowdel=0;
iter=M.rbegin();
while(rem--&&iter!=M.rend())
nowdel+=*iter++;
ans=min(ans,total-nowdel-now);
cnt=1;
now=P[i].second;
}
M.erase(M.find(P[i].second));
}
ans=min(ans,total-now);
printf("%d\n",ans);
return 0;
}