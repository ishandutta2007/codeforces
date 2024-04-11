#include <cstdio>
#include <cstring>
int mp[6][6];
int len[15]={0,3,4,5,4,3};
int has(){
    int ans=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=len[i];j++){
            ans=(ans<<1)+mp[i][j];
        }
    }
    return ans;
}
bool f[(1<<19)+5];
bool visit[(1<<19)+5];
bool dfs(){
    int tmp=has();
    if(visit[tmp]){
        return f[tmp];
    }
    f[tmp]=1;
    visit[tmp]=1;
    int now[6][6];
    memcpy(now,mp,sizeof mp);
    bool get_ans=1;
    for(int i=1;i<=5;i++){
        for(int j=1,k,l;j<=len[i];j++){
            if(mp[i][j]==0){
                continue;
            }
            k=j;
            while(k<=len[i]&&mp[i][k]==1&&get_ans){
                mp[i][k]=0;
                get_ans=get_ans&&dfs();
                k++;
            }
            memcpy(mp,now,sizeof mp);
            if(!get_ans){
                return 1;
            }
            k=i+1;
            l=j;
            mp[i][j]=0;
            while(k<=5&&l>0&&l<=len[k]&&mp[k][l]==1&&get_ans){
                mp[k][l]=0;
                get_ans=get_ans&&dfs();
                k++;
                if(k>3){
                    l--;
                }
            }
            memcpy(mp,now,sizeof mp);
            if(!get_ans){
                return 1;
            }
            k=i+1;
            l=j+1;
            mp[i][j]=0;
            while(k<=5&&l<=len[k]&&mp[k][l]==1&&get_ans){
                mp[k][l]=0;
                get_ans=get_ans&&dfs();
                k++;
                if(k<=3){
                    l++;
                }
            }
            memcpy(mp,now,sizeof mp);
            if(!get_ans){
                return 1;
            }
            k=i+1,l=j;
            mp[i][j]=0;
            while(k<=5&&l<=len[k]&&mp[k][l]==1&&get_ans){
                mp[k][l]=0;
                get_ans=get_ans&&dfs();
                k++;
                if(k>3){
                    l++;
                }
            }
            memcpy(mp,now,sizeof mp);
            if(!get_ans){
                return 1;
            }
            k=i+1,l=j-1;
            mp[i][j]=0;
            while(k<=5&&l>0&&l<=len[k]&&mp[k][l]==1&&get_ans){
                mp[k][l]=0;
                get_ans=get_ans&&dfs();
                k++;
                if(k<=3){
                    l--;
                }
            }
            memcpy(mp,now,sizeof mp);
            if(!get_ans){
                return 1;
            }
        }
    }
    return f[tmp]=0;
}
int main(){
    char c;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=len[i];j++){
            c=getchar();
            while(c!='.'&&c!='O'){
                c=getchar();
            }
            if(c=='.'){
                mp[i][j]=0;
            }
            else{
                mp[i][j]=1;
            }
        }
    }
    visit[0]=1;
    visit[523775]=1;
    visit[393143]=1;
    visit[523071]=1;
    visit[515551]=1;
    visit[524280]=1;
    visit[245183]=1;
    visit[502239]=1;
    visit[390631]=1;
    visit[262128]=1;
    visit[520783]=1;
    visit[386871]=1;
    visit[489707]=1;
    visit[499652]=1;
    visit[392624]=1;
    visit[522032]=1;
    visit[92921]=1;
    visit[356601]=1;
    visit[167801]=1;
    visit[260960]=1;
    visit[483072]=1;
    visit[226176]=1;
    visit[26889]=1;
    visit[113664]=1;
    f[218112]=1;
    visit[218112]=1;
    visit[9536]=1;
    visit[140882]=1;
    if(dfs()){
        puts("Karlsson");
    }
    else{
        puts("Lillebror");
    }
    return 0;
}