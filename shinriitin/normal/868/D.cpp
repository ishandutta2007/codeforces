#include <bits/stdc++.h>

const int max_N=200;

int n,m;

double length[max_N+21];

char s[max_N+21][max_N],pre[max_N+21][max_N],suf[max_N+21][max_N];

std::set<int>subs[max_N+21][20];

int ans[max_N+21];

inline int get_hash(int x,int l,int r){
    int res=0;
    for(int i=l;i<=r;++i)res=(res<<1)|(s[x][i]-'0');
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%s",s[i]);
        int len=strlen(s[i]);
        for(int j=0;j<len&&j<13;++j)pre[i][j]=s[i][j];
        if(len<=13){
            for(int j=0;j<len;++j)suf[i][j]=s[i][j];
        }
        else{
            for(int j=0;j<13;++j)suf[i][j]=s[i][len-13+j];
        }
        for(int k=1;k<=13&&k<=len;++k){
            for(int l=0;l<len;++l){
                int r=l+k-1;
                if(r==len)break;
                subs[i][k].insert(get_hash(i,l,r));
            }
        }
        length[i]=len;
    }
    scanf("%d",&m);
    for(int i=1,a,b;i<=m;++i){
        scanf("%d%d",&a,&b);
        length[n+i]=length[a]+length[b];
        if(length[n+i]<=26){
            for(int j=0;j<length[a];++j)s[n+i][j]=s[a][j];
            for(int j=0;j<length[b];++j)s[n+i][j+(int)length[a]]=s[b][j];
            for(int j=0;j<13&&j<length[n+i];++j)pre[n+i][j]=s[n+i][j];
            if(length[n+i]<=13){
                for(int j=0;j<length[n+i];++j)suf[n+i][j]=s[n+i][j];
            }
            else{
                for(int j=0;j<13;++j)suf[n+i][j]=s[n+i][(int)length[n+i]-13+j];
            }

        }
        else{
            int tot=0;
            for(int j=0,len=strlen(suf[a]);j<len;++j)s[n+i][tot++]=suf[a][j];
            for(int j=0,len=strlen(pre[b]);j<len;++j)s[n+i][tot++]=pre[b][j];
            tot=0;
            for(int j=0,len=strlen(pre[a]);j<len;++j)pre[n+i][tot++]=pre[a][j];
            for(int j=0,len=strlen(pre[b]);j<len&&tot<13;++j)pre[n+i][tot++]=pre[b][j];
            int len=strlen(suf[b]);
            if(len<13){
                tot=0;
                for(int j=0,len1=strlen(suf[a]);j<13-len;++j)suf[n+i][tot++]=suf[a][len1-(13-len)+j];
                for(int j=0;j<len;++j)suf[n+i][tot++]=suf[b][j];
            }
            else{
                for(int j=0;j<len;++j)suf[n+i][j]=suf[b][j];
            }
        }
        for(int k=1,len=strlen(s[n+i]);k<=13&&k<=len;++k){
                for(int l=0;l<len;++l){
                    int r=l+k-1;
                    if(r==len)break;
                    subs[n+i][k].insert(get_hash(n+i,l,r));
                }
            }
        for(int k=1;k<=13;++k){
            for(auto&x:subs[a][k])subs[n+i][k].insert(x);
            for(auto&x:subs[b][k])subs[n+i][k].insert(x);
            bool flag=1;
            for(int j=0;j<(1<<k);++j)
                if(subs[n+i][k].find(j)==subs[n+i][k].end()){
                    flag=0;
                    break;
                }
            if(flag)ans[n+i]=k;
        }
        printf("%d\n",ans[n+i]);
    }
    return 0;
}