#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
const int N=505;
VI son[N*8];int real[N*8],now[N*8];
int can[N*8];//can=0 ->()  can=1 ->[] can't rev  can=2 ->[] can rev
bool rev[N*8];
int root;int tot;
int n;char a[N][N];
int ans[N];
inline bool qquan(int x){return now[x]==real[x];}

inline bool qkong(int x){return !now[x];}

inline bool qzi(int x){return (!qquan(x))&&(!qkong(x));}

inline int rever(int x){
    VI tmp;
    per(i,son[x].size()-1,0)tmp.pb(son[x][i]);
    son[x]=tmp;
}

inline void updata(int x){
    if(rev[x]){
        rev[x]=0;rever(x);
        rep(i,0,son[x].size()-1)rev[son[x][i]]^=1;
    }
}

void fail(string info){
    printf("NO");
    exit(0);
}

void need(int x){
    if(can[x]==1)fail("can't rev!");
    rev[x]=1;can[x]=1;
    updata(x);
}

void dfs_get(int x){
    updata(x);
    if(x<=n){
        real[x]=1;
        return;
    }
    real[x]=0;now[x]=0;
    rep(i,0,son[x].size()-1){
        dfs_get(son[x][i]);
        real[x]+=real[son[x][i]];
        now[x]+=now[son[x][i]];
    }
}


int work(int x,int type){
    //0:suibian  1:left 2:right
    updata(x);
    if(x<=n)return x;
    if(!can[x]){
        VI tmp,kong,quan,zi;
        
        
        rep(i,0,son[x].size()-1)
        if(qquan(son[x][i]))quan.pb(son[x][i]);
        else if(qzi(son[x][i]))zi.pb(son[x][i]);
        else kong.pb(son[x][i]);
        
        
        if(S(zi)>2)fail("size of ziji is too big");
        if(type>0&&S(zi)==2)fail("need left or right but size of ziji is 2");
        if(S(quan)==0&&S(zi)==1&&type==0){
            rep(i,0,son[x].size()-1)if(son[x][i]==zi[0]){
                son[x][i]=work(zi[0],0);
                return x;
            }
        }
        
        int middle;
        if(!S(quan))middle=0;
        else if(S(quan)==1)middle=quan[0];
        else{
            middle=++tot;
            can[middle]=0;
            son[middle]=quan;
        }
        
        if(type==0){
            if(S(zi)==1){
                tmp.pb(work(zi[0],2));
                if(middle)tmp.pb(middle);
            }
            else if(S(zi)==2){
                tmp.pb(work(zi[0],2));
                if(middle)tmp.pb(middle);
                tmp.pb(work(zi[1],1));
            }
            else{
                tmp.pb(middle);
            }
        }
        else if(type==1){
            if(middle)tmp.pb(middle);
            if(S(zi))tmp.pb(work(zi[0],1));
        }
        else if(type==2){
            if(S(zi))tmp.pb(work(zi[0],2));
            if(middle)tmp.pb(middle);
        }
        
        int t2=0;
        if(S(tmp)==1)t2=tmp[0];
        else{
            t2=++tot;
            can[t2]=2;
            son[t2]=tmp;
        }
        
        
        
        int t3=0;
        if(S(kong)==0)t3=t2;
        else{
            t3=++tot;
            if(type==0){
                can[t3]=0;
                son[t3]=kong;
                son[t3].pb(t2);
            }
            else{
                int t4=0;
                if(S(kong)==1)t4=kong[0];
                else{
                    t4=++tot;
                    can[t4]=0;
                    son[t4]=kong;
                }
                can[t3]=1;
                if(type==1){
                    son[t3].pb(t2);
                    son[t3].pb(t4);
                }
                else{
                    son[t3].pb(t4);
                    son[t3].pb(t2);
                }
            }
        }
        return t3;
    }
    else{
        int head=son[x][0];
        int tail=son[x][S(son[x])-1];
        
        if(type==1&& !(qquan(head)||(now[head]!=0&&now[tail]!=real[tail])))need(x);
        else if(type==2&& !(qquan(tail)||(now[tail]!=0&&now[head]!=real[head])))need(x);
        
        int last=-1;int cnt,sum;cnt=sum=0;bool flag=0;
        rep(i,0,son[x].size()-1){
            int w=0;
            if(qquan(son[x][i]))w=2;
            else if(qzi(son[x][i]))w=1;
            
            if(last!=-1){
                if(w>last&&type==1)fail("hehe");
                if(w<last&&type==2)fail("haha");
                if(!w&&last)flag=1;
                if(w&&flag&&!last)fail("two segment");
            }
            last=w;
            cnt+=(w==1);
            sum+=(w>0);
        }
        if(cnt>(type==0?2:1))fail("two many");
        cnt=0;
        rep(i,0,son[x].size()-1){
            int biu = !qkong(son[x][i]);
            if(qzi(son[x][i])){
                if(type)son[x][i]=work(son[x][i],type);
                else if(sum==1)son[x][i]=work(son[x][i],type);
                else{
                    if(!cnt)son[x][i]=work(son[x][i],2);
                    else son[x][i]=work(son[x][i],1);
                }
            }
            cnt+=biu;
        }
        return x;
    }
}

void get_ans(int x){
    updata(x);
    if(x<=n){
        ans[++ans[0]]=x;
        return;
    }
    rep(i,0,son[x].size()-1)get_ans(son[x][i]);
}

void outans(){
    ans[0]=0;
    get_ans(root);
    rep(i,1,n){
        rep(j,1,n)printf("%c",a[i][ans[j]]);
        printf("\n");
    }
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%s",a[i]+1);
    tot=root=n+1;
    rep(i,1,n)son[root].pb(i);
    rep(i,1,n){
        rep(j,1,n)now[j]=a[i][j]-'0';
        dfs_get(root);
        if(qkong(root))continue;
        root=work(root,0);
    }
    printf("YES\n");
    outans();
    return 0;
}