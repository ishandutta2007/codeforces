#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef __int64 ll;
map<string,int> mp;int len;
char a[10000+2];
string ans[1000000];
int index=0;
bool vis[10000+4][4];// 
void dfs(int l,int d)
{ //l
   if(l<5||vis[l][d]) return;
   vis[l][d]=true;
   string tmp1="",tmp2="";
   for(int i=0;i<d;i++) tmp1+=a[l+i];
   for(int i=d-1;i>=0;i--) tmp2+=a[l-i-1];
   if(l-d+1<=4) tmp2="";
   if(tmp1==tmp2)
   {
      ans[index++]=tmp1;
      dfs(l-(5-d),5-d);
   }else{
      ans[index++]=tmp1;
      dfs(l-d,d);dfs(l-(5-d),5-d);
   }
}
int main()
{
    scanf("%s",a);
    len=strlen(a);
    memset(vis,false,sizeof(vis));
    dfs(len-2,2);
    dfs(len-3,3);
    sort(ans,ans+index);
    int res=1;
    for(int i=1;i<index;i++)
    {
        if(ans[i]!=ans[i-1]) res++;
    }
    if(index==0)res=0;
    cout<<res<<endl;
    if(index!=0)cout<<ans[0]<<endl;
    for(int i=1;i<index;i++){
        if(ans[i]!=ans[i-1]) cout<<ans[i]<<endl;
    }
    return 0;
}