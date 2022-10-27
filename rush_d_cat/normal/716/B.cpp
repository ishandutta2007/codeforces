#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false)
#define INF 1e18
#define MOD 1e9 + 7
#define MAXN 50000+10
#define MAXM 500000+10
char s[MAXN];
int cnt[30];
int main()
{
    scanf("%s",s+1);
    int len = strlen(s+1);
    int l=1,r=26;
    if(len<26) cout<<-1<<endl;
    else{
        for(int i=1;i<=26;i++){
            if(s[i]=='?') cnt[27]++;
            else cnt[s[i]-'A'+1]++;
        }
        for(r=26;r<=len;r++){
            if(r!=26){
                if(s[r]=='?') cnt[27]++;
                else cnt[s[r]-'A'+1]++;
  
                if(s[l]=='?') cnt[27]--;
                else cnt[s[l]-'A'+1]--;
                l++;
            }
            bool ok = 1;
            for(int i=1;i<=26;i++){
                if(cnt[i]>=2) ok=0;
            }
            if(ok){
                for(int i=1;i<=len;i++){
                    if((l<=i)&&(i<=r)){
                        if(s[i]!='?') cout<<s[i];
                        else{
                            for(int j=1;j<=26;j++){
                                if(cnt[j]==0){
                                    cout<<(char)('A'+j-1);
                                    cnt[j]=1;
                                    break;
                                }
                            }
                        }
                    }else{
                        if(s[i]!='?') cout<<s[i];
                        else cout<<'A';
                    }
                }
                return 0;
            }
        }
        cout<<-1<<endl;
    }
}