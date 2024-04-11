#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef __int64 ll;
struct people{
    ll lan;
    ll cnt;
}p[200000+2];
ll l[200000+2];
ll b[200000+2];
ll c[200000+2];
bool cmp(people a,people b){
    return a.cnt>b.cnt;
}
map<ll,int> mp;
int main(){
    int index=1;
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i];
    sort(l+1,l+n+1);
    p[1].lan=l[1];
    p[1].cnt=1;
    for(int i=2;i<=n;i++){
        if(l[i]==l[i-1]) p[index].cnt++;
        else{
            p[++index].lan=l[i];
            p[index].cnt=1;
        }
    }
    sort(p+1,p+index+1,cmp);
    for(int i=1;i<=index;i++){
        mp[p[i].lan]=p[i].cnt;
    }
    int m;cin>>m;
    int ans=0;
    int mx=-1;
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=1;i<=m;i++)
    {

        if(mp[b[i]]>mx)
        {
            mx=mp[b[i]];
            ans=i;
        }

        if(mp[b[i]]==mx)
        {
            if(mp[c[i]]>mp[c[ans]])
                ans=i;
        }

    }
    cout<<ans<<endl;
    return 0;
}