#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;
const int MAXN = 100002;
vector<char> v;
char s[100002];
int used[100002];
int main()
{
    int m,i,j,k,cnt=0,ok;cin>>m;
    scanf("%s",s+1);int len = strlen(s+1);
    memset(used,1,sizeof(used));
    for(i='z';i>='a';i--){
        cnt = 0;ok = 1;
        for(j=1,k=-1;j<=len;j++){
            if(s[j] == i) used[j] = 0,k = j;
            if(used[j]) cnt++;
            if(j > m && used[j-m])	cnt--;
            if(cnt==0 && j >= m){
                cnt++;used[k] = 1;ok=0;
            }
        }
        if(!ok) break;
    }
    for(i=1;i<=len;i++) if(used[i]) v.push_back(s[i]);
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++) cout<<v[i];
}