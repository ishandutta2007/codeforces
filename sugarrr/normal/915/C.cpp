

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
int mod(ll a){
    int c=a%1000000007;
    if(c>=0)return c;
    else return c+1000000007;
}
typedef pair<int,int> i_i;
#define inf 100000000/*10^8*/

/////////////////////////////////
int digit(ll a){
    int b=1;
    while(a/10>0)b++,a=a/10;
    return b;
}


int a[20];
int main(){
    char s[20];cin>>s;
    ll b;cin>>b;
    ll ka=strlen(s);
    int kb=digit(b);
    for(int i=0;i<=9;i++)a[i]=0;
    for(int i=0;i<=ka-1;i++){
        int c=s[i]-'0';
        a[c]++;
    }
    int ans[20];
    if(ka<kb){
        int i=0;
        while(i<=ka-1){
            int j=9;
            while(a[j]==0)j--;
            ans[i]=j;
            a[j]--;
            i++;
        }
        for(int i=0;i<=ka-1;i++)cout<<ans[i];
    }else{
        int x[20];
        for(int i=kb-1;i>=0;i--){
            x[i]=b%10;
            b=b/10;
        }
        stack<int>S;
        int i=0;
        while(i<=kb-1){
            if(a[x[i]]>0){
                S.push(x[i]);a[x[i]]--;i++;
            }else{
                break;
            }
        }/*i*/
        
        if(i!=kb){
            bool fl=false;
            int lk;
            for(int j=0;j<=x[i]-1;j++){
                if(a[j]>0)fl=true,lk=j;
            }
            if(fl==true)S.push(lk),a[lk]--;
            if(fl==false){
                bool flag=false;
                int li;int j=0;
                while(flag==false/*&&i>=0*/){
                    int c=S.top();S.pop();
                    a[c]++;i--;
                    for(j=0;j<=x[i]-1;j++){
                        if(a[j]>0)flag=true,li=j;
                    }
                }
                S.push(li);a[li]--;
            }
        }
        for(int j=9;j>=0;j--){
            while(a[j]>0)S.push(j),a[j]--;
        }
        for(int i=kb-1;i>=0;i--){
            ans[i]=S.top();
            S.pop();
        }
        for(int i=0;i<=kb-1;i++)cout<<ans[i];
    }
    
    
    return 0;
}