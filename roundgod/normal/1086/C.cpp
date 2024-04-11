/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-23 22:12:37
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k,flag;
char str[MAXN],a[MAXN],b[MAXN];
int s[1000005];
int ans[30];
set<int> valid;
void find_answer()
{
    for(int i=0;i<k;i++)
    {
        if(ans[i]==-1) {ans[i]=*valid.begin(); valid.erase(valid.begin());}
    }
    for(int i=0;i<k;i++) printf("%c",ans[i]+'a');
    puts("");
}
void succ()
{
    puts("YES");
    flag=2;
    find_answer();
}
void fail()
{
    puts("NO");
    flag=1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);valid.clear();
        for(int i=0;i<k;i++) valid.insert(i);
        memset(ans,-1,sizeof(ans));
        scanf("%s",str);scanf("%s",a);scanf("%s",b);
        int n=strlen(str);
        for(int i=0;i<n;i++) s[i]=str[i]-'a';
        flag=0;
        for(int i=0;i<n;i++)
        {
            if(ans[s[i]]!=-1)
            {
                if(ans[s[i]]+'a'>a[i]&&ans[s[i]]+'a'<b[i])
                {
                    succ();
                    break;
                }
                if(ans[s[i]]+'a'>b[i]||ans[s[i]]+'a'<a[i])
                {
                    fail();
                    break;
                }
                if(ans[s[i]]+'a'==b[i]&&ans[s[i]]+'a'==a[i]) continue;
                if(ans[s[i]]+'a'>a[i]&&ans[s[i]]+'a'==b[i])
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(flag!=0) break;
                        if(ans[s[j]]!=-1)
                        {
                            if(ans[s[j]]+'a'==b[j]) continue;
                            if(ans[s[j]]+'a'<b[j]) {succ(); break;}
                            else {fail(); break;}
                        }
                        else 
                        {
                            auto it=valid.begin();
                            if(*it+'a'==b[j]) {ans[s[j]]=*it; valid.erase(it); continue;}
                            else if(*it+'a'<b[j]) {ans[s[j]]=*it; valid.erase(it); succ(); break;}
                            else {fail(); break;}
                        }
                    }
                    break;
                }
                else if(ans[s[i]]+'a'==a[i]&&ans[s[i]]+'a'<b[i])
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(flag!=0) break;
                        if(ans[s[j]]!=-1)
                        {
                            if(ans[s[j]]+'a'==a[j]) continue;
                            if(ans[s[j]]+'a'>a[j]) {succ(); break;}
                            else {fail(); break;}
                        }
                        else 
                        {
                            auto it=valid.end(); it--;
                            if(*it+'a'==a[j]) {ans[s[j]]=*it; valid.erase(it); continue;}
                            else if(*it+'a'>a[j]) {ans[s[j]]=*it; valid.erase(it); succ(); break;}
                            else {fail(); break;}
                        }
                    }
                    break;
                }
            }
            if(a[i]==b[i])
            {
                if(!valid.count(b[i]-'a')) {fail(); break;}
                ans[s[i]]=b[i]-'a'; valid.erase(b[i]-'a');
                continue;
            }
            else 
            {
                auto it=valid.upper_bound(a[i]-'a');
                if(it==valid.end()) goto here;
                if(*it<b[i]-'a')
                {
                    ans[s[i]]=*it; valid.erase(it); succ(); break;
                }
                else if(*it>b[i]-'a'&&!valid.count(a[i]-'a'))
                {
                    fail();break;
                }
                else if(*it==b[i]-'a')
                {
                    set<int> dummy;
                    int cp[30];
                    for(int i=0;i<30;i++) cp[i]=ans[i];
                    for(auto j:valid) dummy.insert(j);
                    ans[s[i]]=*it; valid.erase(it);
                    for(int j=i+1;j<n;j++)
                    {
                        if(flag!=0) break;
                        if(ans[s[j]]!=-1)
                        {
                            if(ans[s[j]]+'a'==b[j]) continue;
                            if(ans[s[j]]+'a'<b[j]) {succ(); break;}
                            else  
                            {
                                valid.clear();
                                for(int i=0;i<30;i++) ans[i]=cp[i];
                                for(auto i:dummy) valid.insert(i);
                                goto here;
                            }
                        }
                        else 
                        {
                            auto it=valid.begin();
                            if(*it+'a'==b[j]) {ans[s[j]]=*it; valid.erase(it); continue;}
                            else if(*it+'a'<b[j]) {ans[s[j]]=*it; valid.erase(it); succ(); break;}
                            else 
                            {
                                valid.clear();
                                for(int i=0;i<30;i++) ans[i]=cp[i];
                                for(auto i:dummy) valid.insert(i);
                                goto here;
                            }
                        }
                    }
                    if(flag==0) {succ(); break;}
                }
here:           if(flag==0&&valid.count(a[i]-'a'))
                {
                    ans[s[i]]=a[i]-'a'; valid.erase(a[i]-'a');
                    for(int j=i+1;j<n;j++)
                    {
                        if(flag!=0) break;
                        if(ans[s[j]]!=-1)
                        {
                            if(ans[s[j]]+'a'==a[j]) continue;
                            if(ans[s[j]]+'a'>a[j]) {succ(); break;}
                            else {fail(); break;}
                        }
                        else 
                        {
                            auto it=valid.end(); it--;
                            if(*it+'a'==a[j]) {ans[s[j]]=*it; valid.erase(it); continue;}
                            else if(*it+'a'>a[j]) {ans[s[j]]=*it; valid.erase(it); succ(); break;}
                            else {fail(); break;}
                        }
                    }
                    if(flag==0) {succ(); break;}
                }
                if(flag==0) {fail(); break;} else break;
            }
        }
        if(flag==0) succ();
    }
    return 0;
}