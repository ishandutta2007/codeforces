#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define RI register int
#define endl "\n"
const int N=100000+10;
const int M=100000+10;
const int MOD=1e9+7;
const double PI = acos(-1.0);
const double EXP = 1E-8;
const int INF = 0x3f3f3f3f;
int t,n,m,k,p,l,r,u,v;
int ans,cnt,flag,temp,sum;
int a[30];
char str[N];
struct node{};
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>str;
        int len=strlen(str);
        memset(a,0,sizeof(a));
        for(int i=0;i<len;i++){
            a[str[i]-'a']++;
        }
        string ans1="",ans2="",ans="";
        cnt=0;
        for(int i=0;i<26;i+=2){
            while(a[i]){
                ans1+=(i+'a');
                a[i]--;
                cnt++;
            }
        }
        for(int i=1;i<26;i+=2){
            while(a[i]){
                ans2+=(i+'a');
                a[i]--;
                //cnt++;
            }
        }
        if(ans1.size()>0&&ans2.size()>0){
            if(abs(ans1[cnt-1]-ans2[0])!=1){
                ans=ans1+ans2;
            }else{
                ans=ans2+ans1;
            }
        }else{
            if(ans1.size()>0){
                ans=ans1;
            }else{
                ans=ans2;
            }
        }
 
        flag=1;
        for(int i=1;i<len;i++){
            if(abs(ans[i-1]-ans[i])==1){
                flag=0;
                break;
            }
        }
        cout<<(flag?ans:"No answer")<<endl;
    }
    return 0;
}
/////////